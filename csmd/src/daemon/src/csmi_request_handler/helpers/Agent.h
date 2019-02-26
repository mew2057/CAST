/*================================================================================
   
    csmd/src/daemon/src/csmi_request_handler/helpers/Agent.h

  © Copyright IBM Corporation 2015-2017. All Rights Reserved

    This program is licensed under the terms of the Eclipse Public License
    v1.0 as published by the Eclipse Foundation and available at
    http://www.eclipse.org/legal/epl-v10.html

    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.
 
================================================================================*/

#ifndef _AGENT_H_
#define _AGENT_H_
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include "cgroup.h"
//#include "logging.h"   ///< CSM logging.

#define CSM_BB_CMD "/opt/ibm/bb/bin/bbcmd"
#define CSM_SFR_CMD "/opt/ibm/csm/recovery/soft_failure_recovery"
#define CSM_JSRUN_CMD "/opt/ibm/spectrum_mpi/jsm_pmix/bin/jsm"

#define CSM_SMT_CMD     "/usr/sbin/ppc64_cpu"
#define CSM_SMT_SMT_ARG "--smt="
#define CSM_UPTIME_FILE "/proc/uptime"

#define CSM_TYPE_ALLOCATION_ID    "CSM_ALLOCATION_ID"
#define CSM_TYPE_JSM_ARGS         "CSM_JSM_ARGS"
#define CSM_TYPE_PRIMARY_JOB_ID   "CSM_PRIMARY_JOB_ID"
#define CSM_TYPE_STEP_ID          "CSM_STEP_ID"
#define CSM_TYPE_SECONDARY_JOB_ID "CSM_SECONDARY_JOB_ID"
#define CSM_TYPE_USER_NAME        "CSM_USER_NAME"
#define CSM_TYPE_HOSTS            "CSM_HOSTS"
#define CSM_TYPE_TYPE             "CSM_TYPE"

#define csm_export_env( allocation_id, primary_jid, secondary_jid, user_name )  \
    setenv(CSM_TYPE_ALLOCATION_ID   , std::to_string(allocation_id).c_str(), 1);\
    setenv(CSM_TYPE_PRIMARY_JOB_ID  , std::to_string(primary_jid).c_str()  , 1);\
    setenv(CSM_TYPE_SECONDARY_JOB_ID, std::to_string(secondary_jid).c_str(), 1);\
    setenv(CSM_TYPE_USER_NAME       , user_name                            , 1);

namespace csm {
namespace daemon {
namespace helper {

/**
 * @brief Forks, clears the file descriptors, then executes a script.
 *
 * @todo Add context object.
 * @param[in] argv    The arguments to the script, array is null terminated. 
 *                      The first index is the script with its full path.
 * @param[in] output  The output of the of the forked process.
 * @param[in] info    The user info to execute as.
 * @param[in] timeout_seconds A timeout in seconds, if set to zero no timeout occurs.
 */
int ForkAndExecCapture(  char * const argv[], char** output, csmi_user_info_t* info, int timeout_seconds=0 );

/**
 * @brief Forks the supplied argv then moves the forked pid into the supplied allocation id.
 *
 * @param[in] argv    The arguments to the script, array is null terminated. 
 *                      The first index is the script with its full path.
 * @param[in] allocation_id The allocation id of the targeted cgroup.
 * @param[in] info    The user info to execute as.
 */
int ForkAndExecAllocationCGroup(  char * const argv[], uint64_t allocation_id, csmi_user_info_t* info);

/**
 * @brief Forks, clears the file descriptors, then executes a script.
 *
 * @todo Add context object.
 * @param[in] argv The arguments to the script, array is null terminated. 
 *                  The first index is the script with its full path.
 */
int ForkAndExec(  char * const argv[]);

/**
 * @brief Sets the SMT level of the node then fixes the CSM cgroups.
 *
 * @param[in] smtLevel The new SMT level of for the node [0..).
 *
 * @return The error code of the ppc64_cpu call. 0 for success.
 */
inline int SetSMTLevelCSM( int smtLevel )
{
    // Get the current SMT level.
    int32_t threads, sockets, oldSMT = 0, coresPerSocket;
    bool success = CGroup::GetCPUs(threads, sockets, oldSMT, coresPerSocket );
    
    // EARLY RETURN If the smt level is unchanged. 
    if ( !success || (smtLevel == oldSMT && smtLevel < 0)) return 0;

    // Convert the SMT level to a string.
    std::string smtStr(CSM_SMT_SMT_ARG);
    smtStr.append(std::to_string(smtLevel));
    char* smtLevelStr = strdup(smtStr.c_str());
    
    // Build the query.
    char* scriptArgs[] = { 
        (char*) CSM_SMT_CMD, 
        smtLevelStr,
        NULL};
    int errCode = ForkAndExec(scriptArgs);
    
    // If the error code was zero and the smt was moving from a lower to higher level repair SMT.
    if ( errCode == 0 && oldSMT < smtLevel )
    {
        // TODO handle errors.
        try
        {
            errCode = CGroup::RepairSMTChange() ?  0 : 1;
        }
        catch(const csm::daemon::helper::CSMHandlerException& e)
        {
            errCode = 1; // TODO Is this the correct behavior?
        }
        catch(const std::exception& e)
        {
            errCode = 1; // TODO Is this the correct behavior?
        }
    }

    free( smtLevelStr );
    return errCode;
}

inline int ExecuteBB( char* command_args, char ** output, csmi_user_info_t* info, int timeout)
{
    timeout += 10;
    char* scriptArgs[] = { (char*)CSM_BB_CMD, command_args, NULL };
    int errCode = ForkAndExecCapture( scriptArgs, output, info, timeout );
    return errCode;
}

inline int ExecuteSFRecovery( char ** output, int timeout)
{
    timeout += 10;
    char* scriptArgs[] = { (char*)CSM_SFR_CMD, NULL };
    int errCode = ForkAndExecCapture( scriptArgs, output, NULL, timeout );
    return errCode;
}

inline int ExecuteJSRUN( char* jsm_path, int64_t allocation_id, csmi_user_info_t* info, char* kv_pairs, 
    uint32_t num_nodes, char** compute_nodes, char* launch_node, csmi_allocation_type_t  type)
{
    // Build the nodes string.
    std::string hosts = "";

    for (size_t j=0; j < num_nodes; ++j)
    {
        hosts.append(compute_nodes[j]).append(" ");
    }
    hosts.back() = 0;
    
    std::string node_count = std::to_string(num_nodes);
    std::string alloc_type = std::to_string(type);

    char* scriptArgs[] = { 
        jsm_path != NULL ? jsm_path : (char*)CSM_JSRUN_CMD, 
        (char*)"--type", (char*)alloc_type.c_str(),
        (char*)"--launch_node", launch_node ? launch_node : (char*)"BAD_NODE",
        (char*)"--num_hosts", (char*)node_count.c_str(),
        (char*)"--hosts", (char*)hosts.c_str(),
        NULL };

    // Setup the environment.
    setenv(CSM_TYPE_ALLOCATION_ID   , std::to_string(allocation_id).c_str(), 1);
    setenv(CSM_TYPE_JSM_ARGS        , kv_pairs                             , 1);

    // set the error code.
    int errCode  = INT_MAX;
    
    // Verify the file exists then execute.
    struct stat fileDetails;
    if ((stat(scriptArgs[0] , &fileDetails ) == 0) && 
         (!( ( (fileDetails.st_mode & S_IFDIR) > 0 ) ^ false) ) )
    {
        // Fork and don't wait.
        errCode = ForkAndExecAllocationCGroup( scriptArgs, allocation_id, info);
    }

    return errCode;
}


/**
 * @brief Retrieves the uptime of the system.
 *
 * @return The uptime of the system, 0 if the retrieval failed.
 */
inline long GetUptime()
{
    struct sysinfo info;
    int ret_code = sysinfo(&info);
    
    if ( ret_code )
    {
        return 0;
    }

    return info.uptime;

}



} // End namespace helpers
} // End namespace daemon
} // End namespace csm

#endif
