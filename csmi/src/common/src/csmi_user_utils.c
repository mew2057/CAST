/*================================================================================

    csmi/src/common/src/csmi_user_utils.c

    © Copyright IBM Corporation 2015-2019. All Rights Reserved

    This program is licensed under the terms of the Eclipse Public License
    v1.0 as published by the Eclipse Foundation and available at
    http://www.eclipse.org/legal/epl-v10.html

    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.

================================================================================*/
#include <sys/time.h>
#include <sys/resource.h>

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>       // For user details.
#include <unistd.h>    // For UID
#include <sys/types.h> // For user details.
#include <grp.h>       // For setgroups

#include "csmi/include/csm_api_common.h"
#include "csmi/src/common/include/csmi_common_utils.h"


int32_t get_ulimits(csmi_ulimit_t** ulimits[] )
{
    struct rlimit rlp;
    int resource_num=0;
    csmi_ulimit_t** ulims=(csmi_ulimit_t**)calloc(RLIM_NLIMITS,
    sizeof(csmi_ulimit_t*));
    
    // Iterate over the resources and store the values.
    for (;resource_num < RLIM_NLIMITS; ++resource_num )
    {
        getrlimit(resource_num, &rlp);
        ulims[resource_num] =  malloc(sizeof(csmi_ulimit_t));
        ulims[resource_num]->resource  = resource_num;
        ulims[resource_num]->cur_limit = rlp.rlim_cur;
        ulims[resource_num]->max_limit = rlp.rlim_max;
    }

    *ulimits=ulims;

    return RLIM_NLIMITS;
}

int set_ulimits( int32_t num_ulimits, csmi_ulimit_t** ulimits)
{
    struct rlimit rlp;
    int resource_num=0;
    for (;resource_num < num_ulimits; ++resource_num )
    {

        rlp.rlim_cur = ulimits[resource_num]->cur_limit;
        rlp.rlim_max = ulimits[resource_num]->max_limit;

        setrlimit(ulimits[resource_num]->resource, &rlp);
    }

    return 0;
}

int get_user_info(csmi_user_info_t** info)
{
    struct passwd *pw;
    csmi_user_info_t* uinfo =  malloc(sizeof(csmi_user_info_t));

    uinfo->uid = getuid();
    uinfo->num_ulimits = get_ulimits(&uinfo->ulimits);

    pw = getpwuid(uinfo->uid); 
    if (pw)
    {
        uinfo->user = strdup(pw->pw_name);
        uinfo->gid  = pw->pw_gid;
    }
    // TODO supplementary group stuff.

    *info = uinfo;

    return 0;
}

int apply_user_info(csmi_user_info_t* info)
{
    if ( setregid(info->gid, info->gid) )
        return 1;

    if ( setreuid(info->uid, info->uid) ) 
        return 3;
    
    if( set_ulimits(info->num_ulimits, info->ulimits) )
        return 4;

    return 0;
}
        
