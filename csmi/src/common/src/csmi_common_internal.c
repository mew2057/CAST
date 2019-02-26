/*================================================================================
   
    csmi/src/common/src/csmi_common_internal.c

    © Copyright IBM Corporation 2015-2017. All Rights Reserved

    This program is licensed under the terms of the Eclipse Public License
    v1.0 as published by the Eclipse Foundation and available at
    http://www.eclipse.org/legal/epl-v10.html
    
    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
    restricted by GSA ADP Schedule Contract with IBM Corp.
    
================================================================================*/
#include "csmi/src/common/include/csmi_common_internal.h"
#include "csmi/src/common/include/csmi_common_type_internal.h"
const csmi_struct_node_t csm_node_error_tree[3] = {{"errcode",offsetof(csm_node_error_t,errcode),0,NULL,0x74acc5a9,44},
{"source",offsetof(csm_node_error_t,source),0,NULL,0x1c3aff76,4},
{"errmsg",offsetof(csm_node_error_t,errmsg),0,NULL,0xfbc757d5,4}}
;

void* cast_csm_node_error_t(void* ptr,size_t index, char isArray) { 
    csm_node_error_t ** ptr_cast = *(csm_node_error_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_error_t= {
    3,
    csm_node_error_tree,
    cast_csm_node_error_t
};

const csmi_struct_node_t csmi_err_tree[4] = {{"error_count",offsetof(csmi_err_t,error_count),0,NULL,0xd1ef0537,24},
{"errcode",offsetof(csmi_err_t,errcode),0,NULL,0x74acc5a9,44},
{"errmsg",offsetof(csmi_err_t,errmsg),0,NULL,0xfbc757d5,4},
{"node_errors",offsetof(csmi_err_t,node_errors),offsetof(csmi_err_t, error_count),&map_csm_node_error_t,0x352e9f67,1}}
;

void* cast_csmi_err_t(void* ptr,size_t index, char isArray) { 
    csmi_err_t ** ptr_cast = *(csmi_err_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_err_t= {
    4,
    csmi_err_tree,
    cast_csmi_err_t
};

const csmi_struct_node_t csmi_ulimit_tree[3] = {{"resource",offsetof(csmi_ulimit_t,resource),0,NULL,0x241a090d,44},
{"max_limit",offsetof(csmi_ulimit_t,max_limit),0,NULL,0xacea769,40},
{"cur_limit",offsetof(csmi_ulimit_t,cur_limit),0,NULL,0x2539726d,40}}
;

void* cast_csmi_ulimit_t(void* ptr,size_t index, char isArray) { 
    csmi_ulimit_t ** ptr_cast = *(csmi_ulimit_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ulimit_t= {
    3,
    csmi_ulimit_tree,
    cast_csmi_ulimit_t
};

const csmi_struct_node_t csmi_user_info_tree[7] = {{"uid",offsetof(csmi_user_info_t,uid),0,NULL,0xb88b287,36},
{"gid",offsetof(csmi_user_info_t,gid),0,NULL,0xb8876f9,36},
{"user",offsetof(csmi_user_info_t,user),0,NULL,0x7c9f2e84,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"ulimits",offsetof(csmi_user_info_t,ulimits),offsetof(csmi_user_info_t, num_ulimits),&map_csmi_ulimit_t,0x35b425cc,1},
{"num_ulimits",offsetof(csmi_user_info_t,num_ulimits),0,NULL,0x8972a33b,36}}
;

void* cast_csmi_user_info_t(void* ptr,size_t index, char isArray) { 
    csmi_user_info_t ** ptr_cast = *(csmi_user_info_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_user_info_t= {
    7,
    csmi_user_info_tree,
    cast_csmi_user_info_t
};

#include "csmi/src/wm/include/csmi_wm_internal.h"
#include "csmi/src/wm/include/csmi_wm_type_internal.h"
const csmi_struct_node_t csmi_allocation_history_tree[3] = {{"end_time",offsetof(csmi_allocation_history_t,end_time),0,NULL,0xb56ec18a,4},
{"archive_history_time",offsetof(csmi_allocation_history_t,archive_history_time),0,NULL,0x9e88b9e6,4},
{"exit_status",offsetof(csmi_allocation_history_t,exit_status),0,NULL,0xe8583582,36}}
;

void* cast_csmi_allocation_history_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_history_t ** ptr_cast = *(csmi_allocation_history_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_history_t= {
    3,
    csmi_allocation_history_tree,
    cast_csmi_allocation_history_t
};

const csmi_struct_node_t csmi_allocation_tree[53] = {{"allocation_id",offsetof(csmi_allocation_t,allocation_id),0,NULL,0x99d3da77,40},
{"user_id",offsetof(csmi_allocation_t,user_id),0,NULL,0x45c27210,36},
{"ssd_min",offsetof(csmi_allocation_t,ssd_min),0,NULL,0xabb1b072,40},
{"shared",offsetof(csmi_allocation_t,shared),0,NULL,0x1bb15c9c,16},
{"type",offsetof(csmi_allocation_t,type),csmi_allocation_type_t_MAX,&csmi_allocation_type_t_strs,0x7c9ebd07,8},
{"num_nodes",offsetof(csmi_allocation_t,num_nodes),0,NULL,0xa5d6722d,24},
{"primary_job_id",offsetof(csmi_allocation_t,primary_job_id),0,NULL,0xcfd430cf,40},
{"launch_node_name",offsetof(csmi_allocation_t,launch_node_name),0,NULL,0xf7cc9c5,4},
{"num_gpus",offsetof(csmi_allocation_t,num_gpus),0,NULL,0x338e5253,36},
{"begin_time",offsetof(csmi_allocation_t,begin_time),0,NULL,0x5f818b18,4},
{"user_script",offsetof(csmi_allocation_t,user_script),0,NULL,0x7e4ec898,4},
{"job_type",offsetof(csmi_allocation_t,job_type),csmi_job_type_t_MAX,&csmi_job_type_t_strs,0x9b0819e1,8},
{"ssd_max",offsetof(csmi_allocation_t,ssd_max),0,NULL,0xabb1af74,40},
{"secondary_job_id",offsetof(csmi_allocation_t,secondary_job_id),0,NULL,0xbc667133,36},
{"projected_memory",offsetof(csmi_allocation_t,projected_memory),0,NULL,0xe6057cfd,36},
{"job_submit_time",offsetof(csmi_allocation_t,job_submit_time),0,NULL,0xb996701,4},
{"state",offsetof(csmi_allocation_t,state),csmi_state_t_MAX,&csmi_state_t_strs,0x10614a06,8},
{"account",offsetof(csmi_allocation_t,account),0,NULL,0x1cbdb112,4},
{"ssd_file_system_name",offsetof(csmi_allocation_t,ssd_file_system_name),0,NULL,0x33b3dbb2,4},
{"history",offsetof(csmi_allocation_t,history),0,&map_csmi_allocation_history_t,0x46b87b17,0},
{"compute_nodes",offsetof(csmi_allocation_t,compute_nodes),offsetof(csmi_allocation_t, num_nodes),NULL,0x74676dda,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"job_name",offsetof(csmi_allocation_t,job_name),0,NULL,0x9b046920,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"time_limit",offsetof(csmi_allocation_t,time_limit),0,NULL,0xadbb7332,40},
{"user_flags",offsetof(csmi_allocation_t,user_flags),0,NULL,0xc4ddbbf0,4},
{"system_flags",offsetof(csmi_allocation_t,system_flags),0,NULL,0xd97b5e76,4},
{"num_processors",offsetof(csmi_allocation_t,num_processors),0,NULL,0xeac9b7c7,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"queue",offsetof(csmi_allocation_t,queue),0,NULL,0x103db68a,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"wc_key",offsetof(csmi_allocation_t,wc_key),0,NULL,0x24aa4e27,4},
{NULL,0,0,NULL,0,0},
{"requeue",offsetof(csmi_allocation_t,requeue),0,NULL,0x3f066941,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"smt_mode",offsetof(csmi_allocation_t,smt_mode),0,NULL,0x795cf4dd,72},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"user_group_id",offsetof(csmi_allocation_t,user_group_id),0,NULL,0xb690441c,36},
{"user_name",offsetof(csmi_allocation_t,user_name),0,NULL,0xc029f5a4,4},
{NULL,0,0,NULL,0,0},
{"comment",offsetof(csmi_allocation_t,comment),0,NULL,0xd363aa58,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"isolated_cores",offsetof(csmi_allocation_t,isolated_cores),0,NULL,0xfb061e75,36}}
;

void* cast_csmi_allocation_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_t ** ptr_cast = *(csmi_allocation_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_t= {
    53,
    csmi_allocation_tree,
    cast_csmi_allocation_t
};

const csmi_struct_node_t csmi_allocation_accounting_tree[16] = {{"gpu_usage",offsetof(csmi_allocation_accounting_t,gpu_usage),0,NULL,0x4178e945,40},
{"ib_tx",offsetof(csmi_allocation_accounting_t,ib_tx),0,NULL,0xfa26dbb,40},
{"gpfs_write",offsetof(csmi_allocation_accounting_t,gpfs_write),0,NULL,0x6947993f,40},
{"ib_rx",offsetof(csmi_allocation_accounting_t,ib_rx),0,NULL,0xfa26d79,40},
{"energy_consumed",offsetof(csmi_allocation_accounting_t,energy_consumed),0,NULL,0x2934342c,40},
{"power_shifting_ratio",offsetof(csmi_allocation_accounting_t,power_shifting_ratio),0,NULL,0x5af42f2b,36},
{"memory_usage_max",offsetof(csmi_allocation_accounting_t,memory_usage_max),0,NULL,0xd625f597,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"ssd_read",offsetof(csmi_allocation_accounting_t,ssd_read),0,NULL,0x21ea6a4a,40},
{"power_cap_hit",offsetof(csmi_allocation_accounting_t,power_cap_hit),0,NULL,0x315b4c49,40},
{"gpu_energy",offsetof(csmi_allocation_accounting_t,gpu_energy),0,NULL,0x4aeb6e5a,40},
{"ssd_write",offsetof(csmi_allocation_accounting_t,ssd_write),0,NULL,0x5f997379,40},
{"cpu_usage",offsetof(csmi_allocation_accounting_t,cpu_usage),0,NULL,0x6f872541,40},
{"gpfs_read",offsetof(csmi_allocation_accounting_t,gpfs_read),0,NULL,0xebe7ef50,40},
{"power_cap",offsetof(csmi_allocation_accounting_t,power_cap),0,NULL,0x15494165,36}}
;

void* cast_csmi_allocation_accounting_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_accounting_t ** ptr_cast = *(csmi_allocation_accounting_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_accounting_t= {
    16,
    csmi_allocation_accounting_tree,
    cast_csmi_allocation_accounting_t
};

const csmi_struct_node_t csmi_allocation_step_list_tree[4] = {{"step_id",offsetof(csmi_allocation_step_list_t,step_id),0,NULL,0xae22086d,40},
{"num_nodes",offsetof(csmi_allocation_step_list_t,num_nodes),0,NULL,0xa5d6722d,24},
{"end_time",offsetof(csmi_allocation_step_list_t,end_time),0,NULL,0xb56ec18a,4},
{"compute_nodes",offsetof(csmi_allocation_step_list_t,compute_nodes),0,NULL,0x74676dda,4}}
;

void* cast_csmi_allocation_step_list_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_step_list_t ** ptr_cast = *(csmi_allocation_step_list_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_step_list_t= {
    4,
    csmi_allocation_step_list_tree,
    cast_csmi_allocation_step_list_t
};

const csmi_struct_node_t csmi_allocation_state_history_tree[2] = {{"history_time",offsetof(csmi_allocation_state_history_t,history_time),0,NULL,0x60dc8265,4},
{"state",offsetof(csmi_allocation_state_history_t,state),csmi_state_t_MAX,&csmi_state_t_strs,0x10614a06,8}}
;

void* cast_csmi_allocation_state_history_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_state_history_t ** ptr_cast = *(csmi_allocation_state_history_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_state_history_t= {
    2,
    csmi_allocation_state_history_tree,
    cast_csmi_allocation_state_history_t
};

const csmi_struct_node_t csmi_allocation_details_tree[13] = {{"power_cap_hit",offsetof(csmi_allocation_details_t,power_cap_hit),0,NULL,0x315b4c49,28},
{"ssd_read",offsetof(csmi_allocation_details_t,ssd_read),0,NULL,0x21ea6a4a,28},
{"num_nodes",offsetof(csmi_allocation_details_t,num_nodes),0,NULL,0xa5d6722d,24},
{"steps",offsetof(csmi_allocation_details_t,steps),offsetof(csmi_allocation_details_t, num_steps),&map_csmi_allocation_step_list_t,0x10615a94,1},
{NULL,0,0,NULL,0,0},
{"ssd_write",offsetof(csmi_allocation_details_t,ssd_write),0,NULL,0x5f997379,28},
{"num_steps",offsetof(csmi_allocation_details_t,num_steps),0,NULL,0xa633b043,24},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"num_transitions",offsetof(csmi_allocation_details_t,num_transitions),0,NULL,0x3fe3fad2,24},
{"state_transitions",offsetof(csmi_allocation_details_t,state_transitions),offsetof(csmi_allocation_details_t, num_transitions),&map_csmi_allocation_state_history_t,0x9d16c003,1},
{NULL,0,0,NULL,0,0},
{"node_accounting",offsetof(csmi_allocation_details_t,node_accounting),offsetof(csmi_allocation_details_t, num_nodes),&map_csmi_allocation_accounting_t,0xac4406b5,1}}
;

void* cast_csmi_allocation_details_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_details_t ** ptr_cast = *(csmi_allocation_details_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_details_t= {
    13,
    csmi_allocation_details_tree,
    cast_csmi_allocation_details_t
};

const csmi_struct_node_t csmi_allocation_step_history_tree[21] = {{"omp_thread_limit",offsetof(csmi_allocation_step_history_t,omp_thread_limit),0,NULL,0x8884ccc6,4},
{"max_memory",offsetof(csmi_allocation_step_history_t,max_memory),0,NULL,0x66b074e3,40},
{"total_u_time",offsetof(csmi_allocation_step_history_t,total_u_time),0,NULL,0xa692ad0b,56},
{"gpu_stats",offsetof(csmi_allocation_step_history_t,gpu_stats),0,NULL,0x4155465f,4},
{"cpu_stats",offsetof(csmi_allocation_step_history_t,cpu_stats),0,NULL,0x6f63825b,4},
{"total_s_time",offsetof(csmi_allocation_step_history_t,total_s_time),0,NULL,0xa1e85bc9,56},
{"exit_status",offsetof(csmi_allocation_step_history_t,exit_status),0,NULL,0xe8583582,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"memory_stats",offsetof(csmi_allocation_step_history_t,memory_stats),0,NULL,0x85ddb50c,4},
{"archive_history_time",offsetof(csmi_allocation_step_history_t,archive_history_time),0,NULL,0x9e88b9e6,4},
{NULL,0,0,NULL,0,0},
{"io_stats",offsetof(csmi_allocation_step_history_t,io_stats),0,NULL,0xa9304fab,4},
{"error_message",offsetof(csmi_allocation_step_history_t,error_message),0,NULL,0xf41641f3,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"end_time",offsetof(csmi_allocation_step_history_t,end_time),0,NULL,0xb56ec18a,4}}
;

void* cast_csmi_allocation_step_history_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_step_history_t ** ptr_cast = *(csmi_allocation_step_history_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_step_history_t= {
    21,
    csmi_allocation_step_history_tree,
    cast_csmi_allocation_step_history_t
};

const csmi_struct_node_t csmi_allocation_step_tree[26] = {{"num_nodes",offsetof(csmi_allocation_step_t,num_nodes),0,NULL,0xa5d6722d,36},
{"begin_time",offsetof(csmi_allocation_step_t,begin_time),0,NULL,0x5f818b18,4},
{"projected_memory",offsetof(csmi_allocation_step_t,projected_memory),0,NULL,0xe6057cfd,36},
{"num_gpus",offsetof(csmi_allocation_step_t,num_gpus),0,NULL,0x338e5253,36},
{"executable",offsetof(csmi_allocation_step_t,executable),0,NULL,0x7c422127,4},
{"step_id",offsetof(csmi_allocation_step_t,step_id),0,NULL,0xae22086d,40},
{"num_processors",offsetof(csmi_allocation_step_t,num_processors),0,NULL,0xeac9b7c7,36},
{"status",offsetof(csmi_allocation_step_t,status),csmi_step_status_t_MAX,&csmi_step_status_t_strs,0x1c8a8d49,8},
{"argument",offsetof(csmi_allocation_step_t,argument),0,NULL,0x40da0e88,4},
{"environment_variable",offsetof(csmi_allocation_step_t,environment_variable),0,NULL,0x74e8fc3f,4},
{"allocation_id",offsetof(csmi_allocation_step_t,allocation_id),0,NULL,0x99d3da77,40},
{"num_tasks",offsetof(csmi_allocation_step_t,num_tasks),0,NULL,0xa63b987a,36},
{"working_directory",offsetof(csmi_allocation_step_t,working_directory),0,NULL,0xdfe1263a,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"history",offsetof(csmi_allocation_step_t,history),0,&map_csmi_allocation_step_history_t,0x46b87b17,0},
{"compute_nodes",offsetof(csmi_allocation_step_t,compute_nodes),offsetof(csmi_allocation_step_t, num_nodes),NULL,0x74676dda,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"user_flags",offsetof(csmi_allocation_step_t,user_flags),0,NULL,0xc4ddbbf0,4}}
;

void* cast_csmi_allocation_step_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_step_t ** ptr_cast = *(csmi_allocation_step_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_step_t= {
    26,
    csmi_allocation_step_tree,
    cast_csmi_allocation_step_t
};

const csmi_struct_node_t csmi_ssd_resources_record_tree[3] = {{"update_time",offsetof(csmi_ssd_resources_record_t,update_time),0,NULL,0x7ceafa96,4},
{"wear_lifespan_used",offsetof(csmi_ssd_resources_record_t,wear_lifespan_used),0,NULL,0x7bc95915,56},
{"serial_number",offsetof(csmi_ssd_resources_record_t,serial_number),0,NULL,0xd931f68d,4}}
;

void* cast_csmi_ssd_resources_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ssd_resources_record_t ** ptr_cast = *(csmi_ssd_resources_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ssd_resources_record_t= {
    3,
    csmi_ssd_resources_record_tree,
    cast_csmi_ssd_resources_record_t
};

const csmi_struct_node_t csmi_node_resources_record_tree[23] = {{"node_available_gpus",offsetof(csmi_node_resources_record_t,node_available_gpus),0,NULL,0x2fe53009,36},
{"ssds_count",offsetof(csmi_node_resources_record_t,ssds_count),0,NULL,0x1d4cb32a,24},
{"vg_available_size",offsetof(csmi_node_resources_record_t,vg_available_size),0,NULL,0xa5e09dbc,40},
{"node_state",offsetof(csmi_node_resources_record_t,node_state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x29ab88b,8},
{"node_available_cores",offsetof(csmi_node_resources_record_t,node_available_cores),0,NULL,0x2c4234a6,36},
{"node_name",offsetof(csmi_node_resources_record_t,node_name),0,NULL,0x746e3e2b,4},
{"vg_total_size",offsetof(csmi_node_resources_record_t,vg_total_size),0,NULL,0xc464e35f,40},
{"node_ready",offsetof(csmi_node_resources_record_t,node_ready),0,NULL,0x280645f,16},
{"node_available_processors",offsetof(csmi_node_resources_record_t,node_available_processors),0,NULL,0xff985fd,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"node_installed_memory",offsetof(csmi_node_resources_record_t,node_installed_memory),0,NULL,0x53739482,40},
{"ssds",offsetof(csmi_node_resources_record_t,ssds),offsetof(csmi_node_resources_record_t, ssds_count),&map_csmi_ssd_resources_record_t,0x7c9e15a2,1},
{NULL,0,0,NULL,0,0},
{"node_update_time",offsetof(csmi_node_resources_record_t,node_update_time),0,NULL,0xfa0078db,4},
{"node_discovered_sockets",offsetof(csmi_node_resources_record_t,node_discovered_sockets),0,NULL,0xdf0e4d,36},
{NULL,0,0,NULL,0,0},
{"vg_update_time",offsetof(csmi_node_resources_record_t,vg_update_time),0,NULL,0x70e3692,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"node_discovered_gpus",offsetof(csmi_node_resources_record_t,node_discovered_gpus),0,NULL,0x5a2162f0,36},
{"node_type",offsetof(csmi_node_resources_record_t,node_type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7471eeec,8},
{"node_discovered_cores",offsetof(csmi_node_resources_record_t,node_discovered_cores),0,NULL,0x9e04c46d,36}}
;

void* cast_csmi_node_resources_record_t(void* ptr,size_t index, char isArray) { 
    csmi_node_resources_record_t ** ptr_cast = *(csmi_node_resources_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_resources_record_t= {
    23,
    csmi_node_resources_record_tree,
    cast_csmi_node_resources_record_t
};

const csmi_struct_node_t csmi_cgroup_tree[5] = {{"num_params",offsetof(csmi_cgroup_t,num_params),0,NULL,0x64594df8,24},
{"params",offsetof(csmi_cgroup_t,params),offsetof(csmi_cgroup_t, num_params),NULL,0x143c4269,5},
{"type",offsetof(csmi_cgroup_t,type),csmi_cgroup_controller_t_MAX,&csmi_cgroup_controller_t_strs,0x7c9ebd07,8},
{NULL,0,0,NULL,0,0},
{"values",offsetof(csmi_cgroup_t,values),offsetof(csmi_cgroup_t, num_params),NULL,0x22383ff5,5}}
;

void* cast_csmi_cgroup_t(void* ptr,size_t index, char isArray) { 
    csmi_cgroup_t ** ptr_cast = *(csmi_cgroup_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_cgroup_t= {
    5,
    csmi_cgroup_tree,
    cast_csmi_cgroup_t
};

const csmi_struct_node_t csmi_allocation_resources_record_tree[3] = {{"ready",offsetof(csmi_allocation_resources_record_t,ready),0,NULL,0x1046f5da,16},
{NULL,0,0,NULL,0,0},
{"node_name",offsetof(csmi_allocation_resources_record_t,node_name),0,NULL,0x746e3e2b,4}}
;

void* cast_csmi_allocation_resources_record_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_resources_record_t ** ptr_cast = *(csmi_allocation_resources_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_resources_record_t= {
    3,
    csmi_allocation_resources_record_tree,
    cast_csmi_allocation_resources_record_t
};


const csmi_struct_node_t csm_allocation_query_details_input_tree[1] = {{"allocation_id",offsetof(csm_allocation_query_details_input_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csm_allocation_query_details_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_details_input_t ** ptr_cast = *(csm_allocation_query_details_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_details_input_t= {
    1,
    csm_allocation_query_details_input_tree,
    cast_csm_allocation_query_details_input_t
};

const csmi_struct_node_t csm_allocation_query_details_output_tree[2] = {{"allocation",offsetof(csm_allocation_query_details_output_t,allocation),0,&map_csmi_allocation_t,0xdc80184b,0},
{"allocation_details",offsetof(csm_allocation_query_details_output_t,allocation_details),0,&map_csmi_allocation_details_t,0xd9be0df0,0}}
;

void* cast_csm_allocation_query_details_output_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_details_output_t ** ptr_cast = *(csm_allocation_query_details_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_details_output_t= {
    2,
    csm_allocation_query_details_output_tree,
    cast_csm_allocation_query_details_output_t
};

const csmi_struct_node_t csm_allocation_update_state_input_tree[3] = {{"new_state",offsetof(csm_allocation_update_state_input_t,new_state),csmi_state_t_MAX,&csmi_state_t_strs,0xe3dcb12f,8},
{"allocation_id",offsetof(csm_allocation_update_state_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"exit_status",offsetof(csm_allocation_update_state_input_t,exit_status),0,NULL,0xe8583582,36}}
;

void* cast_csm_allocation_update_state_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_update_state_input_t ** ptr_cast = *(csm_allocation_update_state_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_update_state_input_t= {
    3,
    csm_allocation_update_state_input_tree,
    cast_csm_allocation_update_state_input_t
};


const csmi_struct_node_t csm_allocation_step_end_input_tree[5] = {{"allocation_id",offsetof(csm_allocation_step_end_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"status",offsetof(csm_allocation_step_end_input_t,status),csmi_step_status_t_MAX,&csmi_step_status_t_strs,0x1c8a8d49,8},
{"step_id",offsetof(csm_allocation_step_end_input_t,step_id),0,NULL,0xae22086d,40},
{NULL,0,0,NULL,0,0},
{"history",offsetof(csm_allocation_step_end_input_t,history),0,&map_csmi_allocation_step_history_t,0x46b87b17,0}}
;

void* cast_csm_allocation_step_end_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_end_input_t ** ptr_cast = *(csm_allocation_step_end_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_end_input_t= {
    5,
    csm_allocation_step_end_input_tree,
    cast_csm_allocation_step_end_input_t
};

const csmi_struct_node_t csm_allocation_step_query_input_tree[5] = {{"allocation_id",offsetof(csm_allocation_step_query_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"limit",offsetof(csm_allocation_step_query_input_t,limit),0,NULL,0xfdcc804,36},
{"step_id",offsetof(csm_allocation_step_query_input_t,step_id),0,NULL,0xae22086d,40},
{NULL,0,0,NULL,0,0},
{"offset",offsetof(csm_allocation_step_query_input_t,offset),0,NULL,0x123b4b4c,36}}
;

void* cast_csm_allocation_step_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_query_input_t ** ptr_cast = *(csm_allocation_step_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_query_input_t= {
    5,
    csm_allocation_step_query_input_tree,
    cast_csm_allocation_step_query_input_t
};

const csmi_struct_node_t csm_allocation_step_query_output_tree[2] = {{"num_steps",offsetof(csm_allocation_step_query_output_t,num_steps),0,NULL,0xa633b043,36},
{"steps",offsetof(csm_allocation_step_query_output_t,steps),offsetof(csm_allocation_step_query_output_t, num_steps),&map_csmi_allocation_step_t,0x10615a94,1}}
;

void* cast_csm_allocation_step_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_query_output_t ** ptr_cast = *(csm_allocation_step_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_query_output_t= {
    2,
    csm_allocation_step_query_output_tree,
    cast_csm_allocation_step_query_output_t
};

const csmi_struct_node_t csm_allocation_step_query_details_input_tree[5] = {{"allocation_id",offsetof(csm_allocation_step_query_details_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"limit",offsetof(csm_allocation_step_query_details_input_t,limit),0,NULL,0xfdcc804,36},
{"step_id",offsetof(csm_allocation_step_query_details_input_t,step_id),0,NULL,0xae22086d,40},
{NULL,0,0,NULL,0,0},
{"offset",offsetof(csm_allocation_step_query_details_input_t,offset),0,NULL,0x123b4b4c,36}}
;

void* cast_csm_allocation_step_query_details_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_query_details_input_t ** ptr_cast = *(csm_allocation_step_query_details_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_query_details_input_t= {
    5,
    csm_allocation_step_query_details_input_tree,
    cast_csm_allocation_step_query_details_input_t
};


const csmi_struct_node_t csm_allocation_step_query_active_all_input_tree[3] = {{"offset",offsetof(csm_allocation_step_query_active_all_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_allocation_step_query_active_all_input_t,limit),0,NULL,0xfdcc804,36},
{"allocation_id",offsetof(csm_allocation_step_query_active_all_input_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csm_allocation_step_query_active_all_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_query_active_all_input_t ** ptr_cast = *(csm_allocation_step_query_active_all_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_query_active_all_input_t= {
    3,
    csm_allocation_step_query_active_all_input_tree,
    cast_csm_allocation_step_query_active_all_input_t
};


const csmi_struct_node_t csm_node_resources_query_input_tree[4] = {{"offset",offsetof(csm_node_resources_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_node_resources_query_input_t,limit),0,NULL,0xfdcc804,36},
{"node_names_count",offsetof(csm_node_resources_query_input_t,node_names_count),0,NULL,0x868cf686,24},
{"node_names",offsetof(csm_node_resources_query_input_t,node_names),offsetof(csm_node_resources_query_input_t, node_names_count),NULL,0x23603fe,5}}
;

void* cast_csm_node_resources_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_resources_query_input_t ** ptr_cast = *(csm_node_resources_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_resources_query_input_t= {
    4,
    csm_node_resources_query_input_tree,
    cast_csm_node_resources_query_input_t
};

const csmi_struct_node_t csm_node_resources_query_output_tree[2] = {{"results_count",offsetof(csm_node_resources_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_node_resources_query_output_t,results),offsetof(csm_node_resources_query_output_t, results_count),&map_csmi_node_resources_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_node_resources_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_resources_query_output_t ** ptr_cast = *(csm_node_resources_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_resources_query_output_t= {
    2,
    csm_node_resources_query_output_tree,
    cast_csm_node_resources_query_output_t
};

const csmi_struct_node_t csm_node_resources_query_all_input_tree[3] = {{"limit",offsetof(csm_node_resources_query_all_input_t,limit),0,NULL,0xfdcc804,36},
{NULL,0,0,NULL,0,0},
{"offset",offsetof(csm_node_resources_query_all_input_t,offset),0,NULL,0x123b4b4c,36}}
;

void* cast_csm_node_resources_query_all_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_resources_query_all_input_t ** ptr_cast = *(csm_node_resources_query_all_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_resources_query_all_input_t= {
    3,
    csm_node_resources_query_all_input_tree,
    cast_csm_node_resources_query_all_input_t
};

const csmi_struct_node_t csm_node_resources_query_all_output_tree[2] = {{"results_count",offsetof(csm_node_resources_query_all_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_node_resources_query_all_output_t,results),offsetof(csm_node_resources_query_all_output_t, results_count),&map_csmi_node_resources_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_node_resources_query_all_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_resources_query_all_output_t ** ptr_cast = *(csm_node_resources_query_all_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_resources_query_all_output_t= {
    2,
    csm_node_resources_query_all_output_tree,
    cast_csm_node_resources_query_all_output_t
};

const csmi_struct_node_t csm_allocation_step_cgroup_create_input_tree[7] = {{"num_components",offsetof(csm_allocation_step_cgroup_create_input_t,num_components),0,NULL,0x7feddc9a,24},
{"pid",offsetof(csm_allocation_step_cgroup_create_input_t,pid),0,NULL,0xb889d42,64},
{"allocation_id",offsetof(csm_allocation_step_cgroup_create_input_t,allocation_id),0,NULL,0x99d3da77,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"components",offsetof(csm_allocation_step_cgroup_create_input_t,components),offsetof(csm_allocation_step_cgroup_create_input_t, num_components),&map_csmi_cgroup_t,0x9827a18b,1},
{"cgroup_name",offsetof(csm_allocation_step_cgroup_create_input_t,cgroup_name),0,NULL,0xa90e8395,4}}
;

void* cast_csm_allocation_step_cgroup_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_cgroup_create_input_t ** ptr_cast = *(csm_allocation_step_cgroup_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_cgroup_create_input_t= {
    7,
    csm_allocation_step_cgroup_create_input_tree,
    cast_csm_allocation_step_cgroup_create_input_t
};

const csmi_struct_node_t csm_allocation_step_cgroup_delete_input_tree[4] = {{"num_types",offsetof(csm_allocation_step_cgroup_delete_input_t,num_types),0,NULL,0xa648b409,24},
{"allocation_id",offsetof(csm_allocation_step_cgroup_delete_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"cgroup_name",offsetof(csm_allocation_step_cgroup_delete_input_t,cgroup_name),0,NULL,0xa90e8395,4},
{"controller_types",offsetof(csm_allocation_step_cgroup_delete_input_t,controller_types),offsetof(csm_allocation_step_cgroup_delete_input_t, num_types),NULL,0x8afb5cbd,1}}
;

void* cast_csm_allocation_step_cgroup_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_step_cgroup_delete_input_t ** ptr_cast = *(csm_allocation_step_cgroup_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_step_cgroup_delete_input_t= {
    4,
    csm_allocation_step_cgroup_delete_input_tree,
    cast_csm_allocation_step_cgroup_delete_input_t
};

const csmi_struct_node_t csm_allocation_resources_query_input_tree[3] = {{"offset",offsetof(csm_allocation_resources_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_allocation_resources_query_input_t,limit),0,NULL,0xfdcc804,36},
{"allocation_id",offsetof(csm_allocation_resources_query_input_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csm_allocation_resources_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_resources_query_input_t ** ptr_cast = *(csm_allocation_resources_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_resources_query_input_t= {
    3,
    csm_allocation_resources_query_input_tree,
    cast_csm_allocation_resources_query_input_t
};

const csmi_struct_node_t csm_allocation_resources_query_output_tree[2] = {{"results_count",offsetof(csm_allocation_resources_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_allocation_resources_query_output_t,results),offsetof(csm_allocation_resources_query_output_t, results_count),&map_csmi_allocation_resources_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_allocation_resources_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_resources_query_output_t ** ptr_cast = *(csm_allocation_resources_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_resources_query_output_t= {
    2,
    csm_allocation_resources_query_output_tree,
    cast_csm_allocation_resources_query_output_t
};

const csmi_struct_node_t csm_allocation_update_history_input_tree[12] = {{"allocation_id",offsetof(csm_allocation_update_history_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"user_id",offsetof(csm_allocation_update_history_input_t,user_id),0,NULL,0x45c27210,36},
{"user_name",offsetof(csm_allocation_update_history_input_t,user_name),0,NULL,0xc029f5a4,4},
{"account",offsetof(csm_allocation_update_history_input_t,account),0,NULL,0x1cbdb112,4},
{NULL,0,0,NULL,0,0},
{"user_group_id",offsetof(csm_allocation_update_history_input_t,user_group_id),0,NULL,0xb690441c,36},
{"comment",offsetof(csm_allocation_update_history_input_t,comment),0,NULL,0xd363aa58,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"job_name",offsetof(csm_allocation_update_history_input_t,job_name),0,NULL,0x9b046920,4},
{NULL,0,0,NULL,0,0},
{"reservation",offsetof(csm_allocation_update_history_input_t,reservation),0,NULL,0xd289fb77,4}}
;

void* cast_csm_allocation_update_history_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_update_history_input_t ** ptr_cast = *(csm_allocation_update_history_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_update_history_input_t= {
    12,
    csm_allocation_update_history_input_tree,
    cast_csm_allocation_update_history_input_t
};

const csmi_struct_node_t csm_allocation_query_input_tree[3] = {{"secondary_job_id",offsetof(csm_allocation_query_input_t,secondary_job_id),0,NULL,0xbc667133,36},
{"allocation_id",offsetof(csm_allocation_query_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"primary_job_id",offsetof(csm_allocation_query_input_t,primary_job_id),0,NULL,0xcfd430cf,40}}
;

void* cast_csm_allocation_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_input_t ** ptr_cast = *(csm_allocation_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_input_t= {
    3,
    csm_allocation_query_input_tree,
    cast_csm_allocation_query_input_t
};

const csmi_struct_node_t csm_allocation_query_output_tree[1] = {{"allocation",offsetof(csm_allocation_query_output_t,allocation),0,&map_csmi_allocation_t,0xdc80184b,0}}
;

void* cast_csm_allocation_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_output_t ** ptr_cast = *(csm_allocation_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_output_t= {
    1,
    csm_allocation_query_output_tree,
    cast_csm_allocation_query_output_t
};

const csmi_struct_node_t csm_allocation_query_active_all_input_tree[3] = {{"limit",offsetof(csm_allocation_query_active_all_input_t,limit),0,NULL,0xfdcc804,36},
{NULL,0,0,NULL,0,0},
{"offset",offsetof(csm_allocation_query_active_all_input_t,offset),0,NULL,0x123b4b4c,36}}
;

void* cast_csm_allocation_query_active_all_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_active_all_input_t ** ptr_cast = *(csm_allocation_query_active_all_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_active_all_input_t= {
    3,
    csm_allocation_query_active_all_input_tree,
    cast_csm_allocation_query_active_all_input_t
};

const csmi_struct_node_t csm_allocation_query_active_all_output_tree[3] = {{"num_allocations",offsetof(csm_allocation_query_active_all_output_t,num_allocations),0,NULL,0x4d10bf0d,24},
{NULL,0,0,NULL,0,0},
{"allocations",offsetof(csm_allocation_query_active_all_output_t,allocations),offsetof(csm_allocation_query_active_all_output_t, num_allocations),&map_csmi_allocation_t,0x6c83221e,1}}
;

void* cast_csm_allocation_query_active_all_output_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_query_active_all_output_t ** ptr_cast = *(csm_allocation_query_active_all_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_query_active_all_output_t= {
    3,
    csm_allocation_query_active_all_output_tree,
    cast_csm_allocation_query_active_all_output_t
};

const csmi_struct_node_t csm_allocation_delete_input_tree[5] = {{"primary_job_id",offsetof(csm_allocation_delete_input_t,primary_job_id),0,NULL,0xcfd430cf,40},
{"allocation_id",offsetof(csm_allocation_delete_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"exit_status",offsetof(csm_allocation_delete_input_t,exit_status),0,NULL,0xe8583582,36},
{NULL,0,0,NULL,0,0},
{"secondary_job_id",offsetof(csm_allocation_delete_input_t,secondary_job_id),0,NULL,0xbc667133,36}}
;

void* cast_csm_allocation_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_allocation_delete_input_t ** ptr_cast = *(csm_allocation_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_allocation_delete_input_t= {
    5,
    csm_allocation_delete_input_tree,
    cast_csm_allocation_delete_input_t
};

const csmi_struct_node_t csm_cgroup_login_input_tree[6] = {{"allocation_id",offsetof(csm_cgroup_login_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"pid",offsetof(csm_cgroup_login_input_t,pid),0,NULL,0xb889d42,64},
{"user_name",offsetof(csm_cgroup_login_input_t,user_name),0,NULL,0xc029f5a4,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"migrate_pid",offsetof(csm_cgroup_login_input_t,migrate_pid),0,NULL,0xb05bda0a,68}}
;

void* cast_csm_cgroup_login_input_t(void* ptr,size_t index, char isArray) { 
    csm_cgroup_login_input_t ** ptr_cast = *(csm_cgroup_login_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_cgroup_login_input_t= {
    6,
    csm_cgroup_login_input_tree,
    cast_csm_cgroup_login_input_t
};

const csmi_struct_node_t csmi_allocation_gpu_metrics_tree[7] = {{"num_gpus",offsetof(csmi_allocation_gpu_metrics_t,num_gpus),0,NULL,0x338e5253,40},
{"gpu_id",offsetof(csmi_allocation_gpu_metrics_t,gpu_id),offsetof(csmi_allocation_gpu_metrics_t, num_gpus),NULL,0x4ee05d,1},
{"cpu_usage",offsetof(csmi_allocation_gpu_metrics_t,cpu_usage),offsetof(csmi_allocation_gpu_metrics_t, num_cpus),NULL,0x6f872541,1},
{NULL,0,0,NULL,0,0},
{"num_cpus",offsetof(csmi_allocation_gpu_metrics_t,num_cpus),0,NULL,0x338c20cf,40},
{"gpu_usage",offsetof(csmi_allocation_gpu_metrics_t,gpu_usage),offsetof(csmi_allocation_gpu_metrics_t, num_gpus),NULL,0x4178e945,1},
{"max_gpu_memory",offsetof(csmi_allocation_gpu_metrics_t,max_gpu_memory),offsetof(csmi_allocation_gpu_metrics_t, num_gpus),NULL,0xf084750e,1}}
;

void* cast_csmi_allocation_gpu_metrics_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_gpu_metrics_t ** ptr_cast = *(csmi_allocation_gpu_metrics_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_gpu_metrics_t= {
    7,
    csmi_allocation_gpu_metrics_tree,
    cast_csmi_allocation_gpu_metrics_t
};

const csmi_struct_node_t csmi_allocation_mcast_context_tree[47] = {{"allocation_id",offsetof(csmi_allocation_mcast_context_t,allocation_id),0,NULL,0x99d3da77,40},
{"num_gpus",offsetof(csmi_allocation_mcast_context_t,num_gpus),0,NULL,0x338e5253,36},
{"num_processors",offsetof(csmi_allocation_mcast_context_t,num_processors),0,NULL,0xeac9b7c7,36},
{"ib_tx",offsetof(csmi_allocation_mcast_context_t,ib_tx),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0xfa26dbb,1},
{"gpfs_write",offsetof(csmi_allocation_mcast_context_t,gpfs_write),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x6947993f,1},
{"primary_job_id",offsetof(csmi_allocation_mcast_context_t,primary_job_id),0,NULL,0xcfd430cf,40},
{"isolated_cores",offsetof(csmi_allocation_mcast_context_t,isolated_cores),0,NULL,0xfb061e75,36},
{"ib_rx",offsetof(csmi_allocation_mcast_context_t,ib_rx),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0xfa26d79,1},
{"power_cap",offsetof(csmi_allocation_mcast_context_t,power_cap),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x15494165,1},
{"gpu_energy",offsetof(csmi_allocation_mcast_context_t,gpu_energy),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x4aeb6e5a,1},
{"save_allocation",offsetof(csmi_allocation_mcast_context_t,save_allocation),0,NULL,0x6f9d0af9,68},
{"secondary_job_id",offsetof(csmi_allocation_mcast_context_t,secondary_job_id),0,NULL,0xbc667133,36},
{"projected_memory",offsetof(csmi_allocation_mcast_context_t,projected_memory),0,NULL,0xe6057cfd,36},
{"gpfs_read",offsetof(csmi_allocation_mcast_context_t,gpfs_read),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0xebe7ef50,1},
{"energy",offsetof(csmi_allocation_mcast_context_t,energy),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0xfb77e8af,1},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"state",offsetof(csmi_allocation_mcast_context_t,state),csmi_state_t_MAX,&csmi_state_t_strs,0x10614a06,8},
{"power_cap_hit",offsetof(csmi_allocation_mcast_context_t,power_cap_hit),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x315b4c49,1},
{"gpu_usage",offsetof(csmi_allocation_mcast_context_t,gpu_usage),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x4178e945,1},
{"timestamp",offsetof(csmi_allocation_mcast_context_t,timestamp),0,NULL,0x5c073e19,4},
{"cpu_usage",offsetof(csmi_allocation_mcast_context_t,cpu_usage),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x6f872541,1},
{"smt_mode",offsetof(csmi_allocation_mcast_context_t,smt_mode),0,NULL,0x795cf4dd,72},
{"num_nodes",offsetof(csmi_allocation_mcast_context_t,num_nodes),0,NULL,0xa5d6722d,24},
{"user_flags",offsetof(csmi_allocation_mcast_context_t,user_flags),0,NULL,0xc4ddbbf0,4},
{"system_flags",offsetof(csmi_allocation_mcast_context_t,system_flags),0,NULL,0xd97b5e76,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"memory_max",offsetof(csmi_allocation_mcast_context_t,memory_max),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0xee7ddc83,1},
{NULL,0,0,NULL,0,0},
{"gpu_metrics",offsetof(csmi_allocation_mcast_context_t,gpu_metrics),offsetof(csmi_allocation_mcast_context_t, num_nodes),&map_csmi_allocation_gpu_metrics_t,0xfc3c27a7,1},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"shared",offsetof(csmi_allocation_mcast_context_t,shared),0,NULL,0x1bb15c9c,16},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"ps_ratio",offsetof(csmi_allocation_mcast_context_t,ps_ratio),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x52c9e086,1},
{"runtime",offsetof(csmi_allocation_mcast_context_t,runtime),0,NULL,0x64222d69,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"compute_nodes",offsetof(csmi_allocation_mcast_context_t,compute_nodes),offsetof(csmi_allocation_mcast_context_t, num_nodes),NULL,0x74676dda,5},
{"type",offsetof(csmi_allocation_mcast_context_t,type),csmi_allocation_type_t_MAX,&csmi_allocation_type_t_strs,0x7c9ebd07,8},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"user_name",offsetof(csmi_allocation_mcast_context_t,user_name),0,NULL,0xc029f5a4,4},
{"start_state",offsetof(csmi_allocation_mcast_context_t,start_state),csmi_state_t_MAX,&csmi_state_t_strs,0xc8b079b3,8}}
;

void* cast_csmi_allocation_mcast_context_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_mcast_context_t ** ptr_cast = *(csmi_allocation_mcast_context_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_mcast_context_t= {
    47,
    csmi_allocation_mcast_context_tree,
    cast_csmi_allocation_mcast_context_t
};

const csmi_struct_node_t csmi_allocation_mcast_payload_request_tree[19] = {{"primary_job_id",offsetof(csmi_allocation_mcast_payload_request_t,primary_job_id),0,NULL,0xcfd430cf,40},
{"secondary_job_id",offsetof(csmi_allocation_mcast_payload_request_t,secondary_job_id),0,NULL,0xbc667133,36},
{"num_processors",offsetof(csmi_allocation_mcast_payload_request_t,num_processors),0,NULL,0xeac9b7c7,36},
{"num_gpus",offsetof(csmi_allocation_mcast_payload_request_t,num_gpus),0,NULL,0x338e5253,36},
{"user_name",offsetof(csmi_allocation_mcast_payload_request_t,user_name),0,NULL,0xc029f5a4,4},
{"projected_memory",offsetof(csmi_allocation_mcast_payload_request_t,projected_memory),0,NULL,0xe6057cfd,36},
{"isolated_cores",offsetof(csmi_allocation_mcast_payload_request_t,isolated_cores),0,NULL,0xfb061e75,36},
{"shared",offsetof(csmi_allocation_mcast_payload_request_t,shared),0,NULL,0x1bb15c9c,16},
{"smt_mode",offsetof(csmi_allocation_mcast_payload_request_t,smt_mode),0,NULL,0x795cf4dd,72},
{NULL,0,0,NULL,0,0},
{"user_flags",offsetof(csmi_allocation_mcast_payload_request_t,user_flags),0,NULL,0xc4ddbbf0,4},
{"system_flags",offsetof(csmi_allocation_mcast_payload_request_t,system_flags),0,NULL,0xd97b5e76,4},
{NULL,0,0,NULL,0,0},
{"create",offsetof(csmi_allocation_mcast_payload_request_t,create),0,NULL,0xf715b2b9,68},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"runtime",offsetof(csmi_allocation_mcast_payload_request_t,runtime),0,NULL,0x64222d69,40},
{"allocation_id",offsetof(csmi_allocation_mcast_payload_request_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csmi_allocation_mcast_payload_request_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_mcast_payload_request_t ** ptr_cast = *(csmi_allocation_mcast_payload_request_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_mcast_payload_request_t= {
    19,
    csmi_allocation_mcast_payload_request_tree,
    cast_csmi_allocation_mcast_payload_request_t
};

const csmi_struct_node_t csmi_allocation_mcast_payload_response_tree[25] = {{"gpu_usage",offsetof(csmi_allocation_mcast_payload_response_t,gpu_usage),0,NULL,0x4178e945,40},
{"ib_tx",offsetof(csmi_allocation_mcast_payload_response_t,ib_tx),0,NULL,0xfa26dbb,40},
{"gpfs_read",offsetof(csmi_allocation_mcast_payload_response_t,gpfs_read),0,NULL,0xebe7ef50,40},
{"ib_rx",offsetof(csmi_allocation_mcast_payload_response_t,ib_rx),0,NULL,0xfa26d79,40},
{"pc_hit",offsetof(csmi_allocation_mcast_payload_response_t,pc_hit),0,NULL,0x1456257c,40},
{"gpfs_write",offsetof(csmi_allocation_mcast_payload_response_t,gpfs_write),0,NULL,0x6947993f,40},
{"create",offsetof(csmi_allocation_mcast_payload_response_t,create),0,NULL,0xf715b2b9,68},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"power_cap",offsetof(csmi_allocation_mcast_payload_response_t,power_cap),0,NULL,0x15494165,36},
{"ps_ratio",offsetof(csmi_allocation_mcast_payload_response_t,ps_ratio),0,NULL,0x52c9e086,36},
{"cpu_usage",offsetof(csmi_allocation_mcast_payload_response_t,cpu_usage),0,NULL,0x6f872541,40},
{"memory_max",offsetof(csmi_allocation_mcast_payload_response_t,memory_max),0,NULL,0xee7ddc83,40},
{"energy",offsetof(csmi_allocation_mcast_payload_response_t,energy),0,NULL,0xfb77e8af,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"gpu_energy",offsetof(csmi_allocation_mcast_payload_response_t,gpu_energy),0,NULL,0x4aeb6e5a,40},
{"error_code",offsetof(csmi_allocation_mcast_payload_response_t,error_code),csmi_cmd_err_t_MAX,&csmi_cmd_err_t_strs,0x53eff629,8},
{NULL,0,0,NULL,0,0},
{"hostname",offsetof(csmi_allocation_mcast_payload_response_t,hostname),0,NULL,0xeba474a4,4},
{NULL,0,0,NULL,0,0},
{"error_message",offsetof(csmi_allocation_mcast_payload_response_t,error_message),0,NULL,0xf41641f3,4},
{NULL,0,0,NULL,0,0},
{"gpu_metrics",offsetof(csmi_allocation_mcast_payload_response_t,gpu_metrics),0,&map_csmi_allocation_gpu_metrics_t,0xfc3c27a7,0}}
;

void* cast_csmi_allocation_mcast_payload_response_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_mcast_payload_response_t ** ptr_cast = *(csmi_allocation_mcast_payload_response_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_mcast_payload_response_t= {
    25,
    csmi_allocation_mcast_payload_response_tree,
    cast_csmi_allocation_mcast_payload_response_t
};

const csmi_struct_node_t csmi_allocation_step_mcast_context_tree[7] = {{"num_nodes",offsetof(csmi_allocation_step_mcast_context_t,num_nodes),0,NULL,0xa5d6722d,24},
{"compute_nodes",offsetof(csmi_allocation_step_mcast_context_t,compute_nodes),offsetof(csmi_allocation_step_mcast_context_t, num_nodes),NULL,0x74676dda,5},
{"user_flags",offsetof(csmi_allocation_step_mcast_context_t,user_flags),0,NULL,0xc4ddbbf0,4},
{"begin",offsetof(csmi_allocation_step_mcast_context_t,begin),0,NULL,0xf2587ea,68},
{"allocation_id",offsetof(csmi_allocation_step_mcast_context_t,allocation_id),0,NULL,0x99d3da77,40},
{"step_id",offsetof(csmi_allocation_step_mcast_context_t,step_id),0,NULL,0xae22086d,40},
{"json_str",offsetof(csmi_allocation_step_mcast_context_t,json_str),0,NULL,0xee47efb7,4}}
;

void* cast_csmi_allocation_step_mcast_context_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_step_mcast_context_t ** ptr_cast = *(csmi_allocation_step_mcast_context_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_step_mcast_context_t= {
    7,
    csmi_allocation_step_mcast_context_tree,
    cast_csmi_allocation_step_mcast_context_t
};

const csmi_struct_node_t csmi_allocation_step_mcast_payload_tree[7] = {{"allocation_id",offsetof(csmi_allocation_step_mcast_payload_t,allocation_id),0,NULL,0x99d3da77,40},
{"begin",offsetof(csmi_allocation_step_mcast_payload_t,begin),0,NULL,0xf2587ea,68},
{"user_flags",offsetof(csmi_allocation_step_mcast_payload_t,user_flags),0,NULL,0xc4ddbbf0,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"step_id",offsetof(csmi_allocation_step_mcast_payload_t,step_id),0,NULL,0xae22086d,40},
{"hostname",offsetof(csmi_allocation_step_mcast_payload_t,hostname),0,NULL,0xeba474a4,4}}
;

void* cast_csmi_allocation_step_mcast_payload_t(void* ptr,size_t index, char isArray) { 
    csmi_allocation_step_mcast_payload_t ** ptr_cast = *(csmi_allocation_step_mcast_payload_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_allocation_step_mcast_payload_t= {
    7,
    csmi_allocation_step_mcast_payload_tree,
    cast_csmi_allocation_step_mcast_payload_t
};

const csmi_struct_node_t csmi_jsrun_cmd_payload_tree[13] = {{"allocation_id",offsetof(csmi_jsrun_cmd_payload_t,allocation_id),0,NULL,0x99d3da77,40},
{"user_id",offsetof(csmi_jsrun_cmd_payload_t,user_id),0,NULL,0x45c27210,24},
{"jsm_path",offsetof(csmi_jsrun_cmd_payload_t,jsm_path),0,NULL,0xe89734bb,4},
{"launch_node",offsetof(csmi_jsrun_cmd_payload_t,launch_node),0,NULL,0x3603aa05,4},
{"compute_nodes",offsetof(csmi_jsrun_cmd_payload_t,compute_nodes),offsetof(csmi_jsrun_cmd_payload_t, num_nodes),NULL,0x74676dda,5},
{"num_nodes",offsetof(csmi_jsrun_cmd_payload_t,num_nodes),0,NULL,0xa5d6722d,24},
{"hostname",offsetof(csmi_jsrun_cmd_payload_t,hostname),0,NULL,0xeba474a4,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"type",offsetof(csmi_jsrun_cmd_payload_t,type),csmi_allocation_type_t_MAX,&csmi_allocation_type_t_strs,0x7c9ebd07,8},
{"kv_pairs",offsetof(csmi_jsrun_cmd_payload_t,kv_pairs),0,NULL,0x9c4b0fc4,4},
{"user_info",offsetof(csmi_jsrun_cmd_payload_t,user_info),0,&map_csmi_user_info_t,0xc0276e2f,0}}
;

void* cast_csmi_jsrun_cmd_payload_t(void* ptr,size_t index, char isArray) { 
    csmi_jsrun_cmd_payload_t ** ptr_cast = *(csmi_jsrun_cmd_payload_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_jsrun_cmd_payload_t= {
    13,
    csmi_jsrun_cmd_payload_tree,
    cast_csmi_jsrun_cmd_payload_t
};

const csmi_struct_node_t csm_jsrun_cmd_input_tree[6] = {{"kv_pairs",offsetof(csm_jsrun_cmd_input_t,kv_pairs),0,NULL,0x9c4b0fc4,4},
{"allocation_id",offsetof(csm_jsrun_cmd_input_t,allocation_id),0,NULL,0x99d3da77,40},
{"jsm_path",offsetof(csm_jsrun_cmd_input_t,jsm_path),0,NULL,0xe89734bb,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"user_info",offsetof(csm_jsrun_cmd_input_t,user_info),0,&map_csmi_user_info_t,0xc0276e2f,0}}
;

void* cast_csm_jsrun_cmd_input_t(void* ptr,size_t index, char isArray) { 
    csm_jsrun_cmd_input_t ** ptr_cast = *(csm_jsrun_cmd_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_jsrun_cmd_input_t= {
    6,
    csm_jsrun_cmd_input_tree,
    cast_csm_jsrun_cmd_input_t
};

const csmi_struct_node_t csmi_soft_failure_recovery_payload_tree[3] = {{"hostname",offsetof(csmi_soft_failure_recovery_payload_t,hostname),0,NULL,0xeba474a4,4},
{"error_code",offsetof(csmi_soft_failure_recovery_payload_t,error_code),csmi_cmd_err_t_MAX,&csmi_cmd_err_t_strs,0x53eff629,8},
{"error_message",offsetof(csmi_soft_failure_recovery_payload_t,error_message),0,NULL,0xf41641f3,4}}
;

void* cast_csmi_soft_failure_recovery_payload_t(void* ptr,size_t index, char isArray) { 
    csmi_soft_failure_recovery_payload_t ** ptr_cast = *(csmi_soft_failure_recovery_payload_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_soft_failure_recovery_payload_t= {
    3,
    csmi_soft_failure_recovery_payload_tree,
    cast_csmi_soft_failure_recovery_payload_t
};

const csmi_struct_node_t csm_soft_failure_recovery_node_tree[3] = {{"errcode",offsetof(csm_soft_failure_recovery_node_t,errcode),0,NULL,0x74acc5a9,44},
{"source",offsetof(csm_soft_failure_recovery_node_t,source),0,NULL,0x1c3aff76,4},
{"errmsg",offsetof(csm_soft_failure_recovery_node_t,errmsg),0,NULL,0xfbc757d5,4}}
;

void* cast_csm_soft_failure_recovery_node_t(void* ptr,size_t index, char isArray) { 
    csm_soft_failure_recovery_node_t ** ptr_cast = *(csm_soft_failure_recovery_node_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_soft_failure_recovery_node_t= {
    3,
    csm_soft_failure_recovery_node_tree,
    cast_csm_soft_failure_recovery_node_t
};

const csmi_struct_node_t csm_soft_failure_recovery_input_tree[1] = {{"retry_count",offsetof(csm_soft_failure_recovery_input_t,retry_count),0,NULL,0x2bb0e4c3,24}}
;

void* cast_csm_soft_failure_recovery_input_t(void* ptr,size_t index, char isArray) { 
    csm_soft_failure_recovery_input_t ** ptr_cast = *(csm_soft_failure_recovery_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_soft_failure_recovery_input_t= {
    1,
    csm_soft_failure_recovery_input_tree,
    cast_csm_soft_failure_recovery_input_t
};

const csmi_struct_node_t csm_soft_failure_recovery_output_tree[2] = {{"error_count",offsetof(csm_soft_failure_recovery_output_t,error_count),0,NULL,0xd1ef0537,24},
{"node_errors",offsetof(csm_soft_failure_recovery_output_t,node_errors),offsetof(csm_soft_failure_recovery_output_t, error_count),&map_csm_soft_failure_recovery_node_t,0x352e9f67,1}}
;

void* cast_csm_soft_failure_recovery_output_t(void* ptr,size_t index, char isArray) { 
    csm_soft_failure_recovery_output_t ** ptr_cast = *(csm_soft_failure_recovery_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_soft_failure_recovery_output_t= {
    2,
    csm_soft_failure_recovery_output_tree,
    cast_csm_soft_failure_recovery_output_t
};

#include "csmi/src/bb/include/csmi_bb_internal.h"
#include "csmi/src/bb/include/csmi_bb_type_internal.h"
const csmi_struct_node_t csmi_vg_record_tree[5] = {{"total_size",offsetof(csmi_vg_record_t,total_size),0,NULL,0xc7f736e3,40},
{"node_name",offsetof(csmi_vg_record_t,node_name),0,NULL,0x746e3e2b,4},
{"scheduler",offsetof(csmi_vg_record_t,scheduler),0,NULL,0xdc0deaa4,16},
{"available_size",offsetof(csmi_vg_record_t,available_size),0,NULL,0x9b91340,40},
{"vg_name",offsetof(csmi_vg_record_t,vg_name),0,NULL,0x76500bc2,4}}
;

void* cast_csmi_vg_record_t(void* ptr,size_t index, char isArray) { 
    csmi_vg_record_t ** ptr_cast = *(csmi_vg_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_vg_record_t= {
    5,
    csmi_vg_record_tree,
    cast_csmi_vg_record_t
};

const csmi_struct_node_t csmi_lv_record_tree[15] = {{"max_size",offsetof(csmi_lv_record_t,max_size),0,NULL,0x5d6ef4a5,40},
{"file_system_mount",offsetof(csmi_lv_record_t,file_system_mount),0,NULL,0x33eec6bb,4},
{"vg_name",offsetof(csmi_lv_record_t,vg_name),0,NULL,0x76500bc2,4},
{"state",offsetof(csmi_lv_record_t,state),0,NULL,0x10614a06,68},
{"current_size",offsetof(csmi_lv_record_t,current_size),0,NULL,0x454b21c2,40},
{"logical_volume_name",offsetof(csmi_lv_record_t,logical_volume_name),0,NULL,0x7221a037,4},
{"allocation_id",offsetof(csmi_lv_record_t,allocation_id),0,NULL,0x99d3da77,40},
{NULL,0,0,NULL,0,0},
{"updated_time",offsetof(csmi_lv_record_t,updated_time),0,NULL,0x247e0e7a,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"begin_time",offsetof(csmi_lv_record_t,begin_time),0,NULL,0x5f818b18,4},
{"node_name",offsetof(csmi_lv_record_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{"file_system_type",offsetof(csmi_lv_record_t,file_system_type),0,NULL,0xa47f99ea,4}}
;

void* cast_csmi_lv_record_t(void* ptr,size_t index, char isArray) { 
    csmi_lv_record_t ** ptr_cast = *(csmi_lv_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_lv_record_t= {
    15,
    csmi_lv_record_tree,
    cast_csmi_lv_record_t
};

const csmi_struct_node_t csmi_bb_vg_ssd_info_tree[2] = {{"ssd_allocation",offsetof(csmi_bb_vg_ssd_info_t,ssd_allocation),0,NULL,0x953b1814,40},
{"ssd_serial_number",offsetof(csmi_bb_vg_ssd_info_t,ssd_serial_number),0,NULL,0x1beecdb6,4}}
;

void* cast_csmi_bb_vg_ssd_info_t(void* ptr,size_t index, char isArray) { 
    csmi_bb_vg_ssd_info_t ** ptr_cast = *(csmi_bb_vg_ssd_info_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_bb_vg_ssd_info_t= {
    2,
    csmi_bb_vg_ssd_info_tree,
    cast_csmi_bb_vg_ssd_info_t
};

const csmi_struct_node_t csm_bb_cmd_input_tree[7] = {{"command_arguments",offsetof(csm_bb_cmd_input_t,command_arguments),0,NULL,0x6a022ed9,4},
{"node_names",offsetof(csm_bb_cmd_input_t,node_names),offsetof(csm_bb_cmd_input_t, node_names_count),NULL,0x23603fe,5},
{"node_names_count",offsetof(csm_bb_cmd_input_t,node_names_count),0,NULL,0x868cf686,24},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"user_info",offsetof(csm_bb_cmd_input_t,user_info),0,&map_csmi_user_info_t,0xc0276e2f,0}}
;

void* cast_csm_bb_cmd_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_cmd_input_t ** ptr_cast = *(csm_bb_cmd_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_cmd_input_t= {
    7,
    csm_bb_cmd_input_tree,
    cast_csm_bb_cmd_input_t
};

const csmi_struct_node_t csm_bb_cmd_output_tree[1] = {{"command_output",offsetof(csm_bb_cmd_output_t,command_output),0,NULL,0x7c09e914,4}}
;

void* cast_csm_bb_cmd_output_t(void* ptr,size_t index, char isArray) { 
    csm_bb_cmd_output_t ** ptr_cast = *(csm_bb_cmd_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_cmd_output_t= {
    1,
    csm_bb_cmd_output_tree,
    cast_csm_bb_cmd_output_t
};

const csmi_struct_node_t csm_bb_lv_create_input_tree[11] = {{"current_size",offsetof(csm_bb_lv_create_input_t,current_size),0,NULL,0x454b21c2,40},
{"state",offsetof(csm_bb_lv_create_input_t,state),0,NULL,0x10614a06,68},
{"allocation_id",offsetof(csm_bb_lv_create_input_t,allocation_id),0,NULL,0x99d3da77,40},
{NULL,0,0,NULL,0,0},
{"file_system_mount",offsetof(csm_bb_lv_create_input_t,file_system_mount),0,NULL,0x33eec6bb,4},
{"node_name",offsetof(csm_bb_lv_create_input_t,node_name),0,NULL,0x746e3e2b,4},
{"file_system_type",offsetof(csm_bb_lv_create_input_t,file_system_type),0,NULL,0xa47f99ea,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"logical_volume_name",offsetof(csm_bb_lv_create_input_t,logical_volume_name),0,NULL,0x7221a037,4},
{"vg_name",offsetof(csm_bb_lv_create_input_t,vg_name),0,NULL,0x76500bc2,4}}
;

void* cast_csm_bb_lv_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_lv_create_input_t ** ptr_cast = *(csm_bb_lv_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_lv_create_input_t= {
    11,
    csm_bb_lv_create_input_tree,
    cast_csm_bb_lv_create_input_t
};

const csmi_struct_node_t csm_bb_lv_delete_input_tree[11] = {{"num_bytes_read",offsetof(csm_bb_lv_delete_input_t,num_bytes_read),0,NULL,0x38181676,40},
{"num_bytes_written",offsetof(csm_bb_lv_delete_input_t,num_bytes_written),0,NULL,0xd3acfa7,40},
{"node_name",offsetof(csm_bb_lv_delete_input_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"logical_volume_name",offsetof(csm_bb_lv_delete_input_t,logical_volume_name),0,NULL,0x7221a037,4},
{"allocation_id",offsetof(csm_bb_lv_delete_input_t,allocation_id),0,NULL,0x99d3da77,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"num_writes",offsetof(csm_bb_lv_delete_input_t,num_writes),0,NULL,0x75dc6b52,40},
{"num_reads",offsetof(csm_bb_lv_delete_input_t,num_reads),0,NULL,0xa6194b83,40}}
;

void* cast_csm_bb_lv_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_lv_delete_input_t ** ptr_cast = *(csm_bb_lv_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_lv_delete_input_t= {
    11,
    csm_bb_lv_delete_input_tree,
    cast_csm_bb_lv_delete_input_t
};

const csmi_struct_node_t csm_bb_lv_query_input_tree[14] = {{"offset",offsetof(csm_bb_lv_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"logical_volume_names_count",offsetof(csm_bb_lv_query_input_t,logical_volume_names_count),0,NULL,0x3741312,24},
{"node_names_count",offsetof(csm_bb_lv_query_input_t,node_names_count),0,NULL,0x868cf686,24},
{"node_names",offsetof(csm_bb_lv_query_input_t,node_names),offsetof(csm_bb_lv_query_input_t, node_names_count),NULL,0x23603fe,5},
{"limit",offsetof(csm_bb_lv_query_input_t,limit),0,NULL,0xfdcc804,36},
{"allocation_ids_count",offsetof(csm_bb_lv_query_input_t,allocation_ids_count),0,NULL,0x49964552,24},
{"allocation_ids",offsetof(csm_bb_lv_query_input_t,allocation_ids),offsetof(csm_bb_lv_query_input_t, allocation_ids_count),NULL,0xd44f29ca,1},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"logical_volume_names",offsetof(csm_bb_lv_query_input_t,logical_volume_names),offsetof(csm_bb_lv_query_input_t, logical_volume_names_count),NULL,0xb655a78a,5}}
;

void* cast_csm_bb_lv_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_lv_query_input_t ** ptr_cast = *(csm_bb_lv_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_lv_query_input_t= {
    14,
    csm_bb_lv_query_input_tree,
    cast_csm_bb_lv_query_input_t
};

const csmi_struct_node_t csm_bb_lv_query_output_tree[2] = {{"results_count",offsetof(csm_bb_lv_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_bb_lv_query_output_t,results),offsetof(csm_bb_lv_query_output_t, results_count),&map_csmi_lv_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_bb_lv_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_bb_lv_query_output_t ** ptr_cast = *(csm_bb_lv_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_lv_query_output_t= {
    2,
    csm_bb_lv_query_output_tree,
    cast_csm_bb_lv_query_output_t
};

const csmi_struct_node_t csm_bb_lv_update_input_tree[7] = {{"current_size",offsetof(csm_bb_lv_update_input_t,current_size),0,NULL,0x454b21c2,40},
{"state",offsetof(csm_bb_lv_update_input_t,state),0,NULL,0x10614a06,68},
{"node_name",offsetof(csm_bb_lv_update_input_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"logical_volume_name",offsetof(csm_bb_lv_update_input_t,logical_volume_name),0,NULL,0x7221a037,4},
{"allocation_id",offsetof(csm_bb_lv_update_input_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csm_bb_lv_update_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_lv_update_input_t ** ptr_cast = *(csm_bb_lv_update_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_lv_update_input_t= {
    7,
    csm_bb_lv_update_input_tree,
    cast_csm_bb_lv_update_input_t
};

const csmi_struct_node_t csm_bb_vg_create_input_tree[9] = {{"ssd_info_count",offsetof(csm_bb_vg_create_input_t,ssd_info_count),0,NULL,0xbca8962,24},
{"available_size",offsetof(csm_bb_vg_create_input_t,available_size),0,NULL,0x9b91340,40},
{"total_size",offsetof(csm_bb_vg_create_input_t,total_size),0,NULL,0xc7f736e3,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"node_name",offsetof(csm_bb_vg_create_input_t,node_name),0,NULL,0x746e3e2b,4},
{"scheduler",offsetof(csm_bb_vg_create_input_t,scheduler),0,NULL,0xdc0deaa4,16},
{"ssd_info",offsetof(csm_bb_vg_create_input_t,ssd_info),offsetof(csm_bb_vg_create_input_t, ssd_info_count),&map_csmi_bb_vg_ssd_info_t,0x21e5a1da,1},
{"vg_name",offsetof(csm_bb_vg_create_input_t,vg_name),0,NULL,0x76500bc2,4}}
;

void* cast_csm_bb_vg_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_vg_create_input_t ** ptr_cast = *(csm_bb_vg_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_vg_create_input_t= {
    9,
    csm_bb_vg_create_input_tree,
    cast_csm_bb_vg_create_input_t
};

const csmi_struct_node_t csm_bb_vg_delete_input_tree[3] = {{"node_name",offsetof(csm_bb_vg_delete_input_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{"vg_name",offsetof(csm_bb_vg_delete_input_t,vg_name),0,NULL,0x76500bc2,4}}
;

void* cast_csm_bb_vg_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_vg_delete_input_t ** ptr_cast = *(csm_bb_vg_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_vg_delete_input_t= {
    3,
    csm_bb_vg_delete_input_tree,
    cast_csm_bb_vg_delete_input_t
};

const csmi_struct_node_t csm_bb_vg_delete_output_tree[2] = {{"failure_count",offsetof(csm_bb_vg_delete_output_t,failure_count),0,NULL,0xb64de7b5,24},
{"failure_vg_names",offsetof(csm_bb_vg_delete_output_t,failure_vg_names),offsetof(csm_bb_vg_delete_output_t, failure_count),NULL,0x9bf2a25c,5}}
;

void* cast_csm_bb_vg_delete_output_t(void* ptr,size_t index, char isArray) { 
    csm_bb_vg_delete_output_t ** ptr_cast = *(csm_bb_vg_delete_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_vg_delete_output_t= {
    2,
    csm_bb_vg_delete_output_tree,
    cast_csm_bb_vg_delete_output_t
};

const csmi_struct_node_t csm_bb_vg_query_input_tree[7] = {{"offset",offsetof(csm_bb_vg_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_bb_vg_query_input_t,limit),0,NULL,0xfdcc804,36},
{"node_names_count",offsetof(csm_bb_vg_query_input_t,node_names_count),0,NULL,0x868cf686,24},
{"node_names",offsetof(csm_bb_vg_query_input_t,node_names),offsetof(csm_bb_vg_query_input_t, node_names_count),NULL,0x23603fe,5},
{NULL,0,0,NULL,0,0},
{"vg_names",offsetof(csm_bb_vg_query_input_t,vg_names),offsetof(csm_bb_vg_query_input_t, vg_names_count),NULL,0x40518475,5},
{"vg_names_count",offsetof(csm_bb_vg_query_input_t,vg_names_count),0,NULL,0x939ab43d,24}}
;

void* cast_csm_bb_vg_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_bb_vg_query_input_t ** ptr_cast = *(csm_bb_vg_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_vg_query_input_t= {
    7,
    csm_bb_vg_query_input_tree,
    cast_csm_bb_vg_query_input_t
};

const csmi_struct_node_t csm_bb_vg_query_output_tree[2] = {{"results_count",offsetof(csm_bb_vg_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_bb_vg_query_output_t,results),offsetof(csm_bb_vg_query_output_t, results_count),&map_csmi_vg_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_bb_vg_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_bb_vg_query_output_t ** ptr_cast = *(csm_bb_vg_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_bb_vg_query_output_t= {
    2,
    csm_bb_vg_query_output_tree,
    cast_csm_bb_vg_query_output_t
};

const csmi_struct_node_t csmi_bb_cmd_payload_tree[4] = {{"bb_cmd_str",offsetof(csmi_bb_cmd_payload_t,bb_cmd_str),0,NULL,0xd01a1df4,4},
{"bb_cmd_int",offsetof(csmi_bb_cmd_payload_t,bb_cmd_int),0,NULL,0xd019f2a6,24},
{"hostname",offsetof(csmi_bb_cmd_payload_t,hostname),0,NULL,0xeba474a4,4},
{"user_info",offsetof(csmi_bb_cmd_payload_t,user_info),0,&map_csmi_user_info_t,0xc0276e2f,0}}
;

void* cast_csmi_bb_cmd_payload_t(void* ptr,size_t index, char isArray) { 
    csmi_bb_cmd_payload_t ** ptr_cast = *(csmi_bb_cmd_payload_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_bb_cmd_payload_t= {
    4,
    csmi_bb_cmd_payload_tree,
    cast_csmi_bb_cmd_payload_t
};

#include "csmi/src/inv/include/csmi_inv_internal.h"
#include "csmi/src/inv/include/csmi_inv_type_internal.h"
const csmi_struct_node_t csmi_dimm_record_tree[6] = {{"node_name",offsetof(csmi_dimm_record_t,node_name),0,NULL,0x746e3e2b,4},
{"physical_location",offsetof(csmi_dimm_record_t,physical_location),0,NULL,0x63efcf7a,4},
{"serial_number",offsetof(csmi_dimm_record_t,serial_number),0,NULL,0xd931f68d,4},
{"status",offsetof(csmi_dimm_record_t,status),0,NULL,0x1c8a8d49,68},
{NULL,0,0,NULL,0,0},
{"size",offsetof(csmi_dimm_record_t,size),0,NULL,0x7c9dede0,36}}
;

void* cast_csmi_dimm_record_t(void* ptr,size_t index, char isArray) { 
    csmi_dimm_record_t ** ptr_cast = *(csmi_dimm_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_dimm_record_t= {
    6,
    csmi_dimm_record_tree,
    cast_csmi_dimm_record_t
};

const csmi_struct_node_t csmi_gpu_record_tree[13] = {{"node_name",offsetof(csmi_gpu_record_t,node_name),0,NULL,0x746e3e2b,4},
{"status",offsetof(csmi_gpu_record_t,status),0,NULL,0x1c8a8d49,4},
{"inforom_image_version",offsetof(csmi_gpu_record_t,inforom_image_version),0,NULL,0xda562dc6,4},
{"gpu_id",offsetof(csmi_gpu_record_t,gpu_id),0,NULL,0x4ee05d,36},
{"pci_bus_id",offsetof(csmi_gpu_record_t,pci_bus_id),0,NULL,0x6b695f36,4},
{"hbm_memory",offsetof(csmi_gpu_record_t,hbm_memory),0,NULL,0xa023ea94,40},
{"device_name",offsetof(csmi_gpu_record_t,device_name),0,NULL,0xeb7bd8d5,4},
{NULL,0,0,NULL,0,0},
{"vbios",offsetof(csmi_gpu_record_t,vbios),0,NULL,0x108dd628,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"uuid",offsetof(csmi_gpu_record_t,uuid),0,NULL,0x7c9f377c,4},
{"serial_number",offsetof(csmi_gpu_record_t,serial_number),0,NULL,0xd931f68d,4}}
;

void* cast_csmi_gpu_record_t(void* ptr,size_t index, char isArray) { 
    csmi_gpu_record_t ** ptr_cast = *(csmi_gpu_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_gpu_record_t= {
    13,
    csmi_gpu_record_tree,
    cast_csmi_gpu_record_t
};

const csmi_struct_node_t csmi_hca_record_tree[12] = {{"node_name",offsetof(csmi_hca_record_t,node_name),0,NULL,0x746e3e2b,4},
{"board_id",offsetof(csmi_hca_record_t,board_id),0,NULL,0x37f2e639,4},
{"device_name",offsetof(csmi_hca_record_t,device_name),0,NULL,0xeb7bd8d5,4},
{"hw_rev",offsetof(csmi_hca_record_t,hw_rev),0,NULL,0x316f490,4},
{"part_number",offsetof(csmi_hca_record_t,part_number),0,NULL,0x532f81a4,4},
{"serial_number",offsetof(csmi_hca_record_t,serial_number),0,NULL,0xd931f68d,4},
{"fw_ver",offsetof(csmi_hca_record_t,fw_ver),0,NULL,0xfe6cb44e,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"pci_bus_id",offsetof(csmi_hca_record_t,pci_bus_id),0,NULL,0x6b695f36,4},
{"guid",offsetof(csmi_hca_record_t,guid),0,NULL,0x7c978a2e,4}}
;

void* cast_csmi_hca_record_t(void* ptr,size_t index, char isArray) { 
    csmi_hca_record_t ** ptr_cast = *(csmi_hca_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_hca_record_t= {
    12,
    csmi_hca_record_tree,
    cast_csmi_hca_record_t
};

const csmi_struct_node_t csmi_ib_cable_record_tree[23] = {{"discovery_time",offsetof(csmi_ib_cable_record_t,discovery_time),0,NULL,0x603630cb,4},
{"guid_s1",offsetof(csmi_ib_cable_record_t,guid_s1),0,NULL,0x14fe2691,4},
{"identifier",offsetof(csmi_ib_cable_record_t,identifier),0,NULL,0xbe5ad288,4},
{"length",offsetof(csmi_ib_cable_record_t,length),0,NULL,0xb2deac7,4},
{"revision",offsetof(csmi_ib_cable_record_t,revision),0,NULL,0x2aabb274,4},
{"port_s1",offsetof(csmi_ib_cable_record_t,port_s1),0,NULL,0xbc76f82d,4},
{"collection_time",offsetof(csmi_ib_cable_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{NULL,0,0,NULL,0,0},
{"width",offsetof(csmi_ib_cable_record_t,width),0,NULL,0x10a3b0a5,4},
{"guid_s2",offsetof(csmi_ib_cable_record_t,guid_s2),0,NULL,0x14fe2692,4},
{"part_number",offsetof(csmi_ib_cable_record_t,part_number),0,NULL,0x532f81a4,4},
{"name",offsetof(csmi_ib_cable_record_t,name),0,NULL,0x7c9b0c46,4},
{"port_s2",offsetof(csmi_ib_cable_record_t,port_s2),0,NULL,0xbc76f82e,4},
{"comment",offsetof(csmi_ib_cable_record_t,comment),0,NULL,0xd363aa58,4},
{"serial_number",offsetof(csmi_ib_cable_record_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csmi_ib_cable_record_t,severity),0,NULL,0x16a499a0,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"type",offsetof(csmi_ib_cable_record_t,type),0,NULL,0x7c9ebd07,4}}
;

void* cast_csmi_ib_cable_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ib_cable_record_t ** ptr_cast = *(csmi_ib_cable_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ib_cable_record_t= {
    23,
    csmi_ib_cable_record_tree,
    cast_csmi_ib_cable_record_t
};

const csmi_struct_node_t csmi_ib_cable_history_record_tree[25] = {{"history_time",offsetof(csmi_ib_cable_history_record_t,history_time),0,NULL,0x60dc8265,4},
{"guid_s2",offsetof(csmi_ib_cable_history_record_t,guid_s2),0,NULL,0x14fe2692,4},
{"identifier",offsetof(csmi_ib_cable_history_record_t,identifier),0,NULL,0xbe5ad288,4},
{"width",offsetof(csmi_ib_cable_history_record_t,width),0,NULL,0x10a3b0a5,4},
{"part_number",offsetof(csmi_ib_cable_history_record_t,part_number),0,NULL,0x532f81a4,4},
{"port_s1",offsetof(csmi_ib_cable_history_record_t,port_s1),0,NULL,0xbc76f82d,4},
{"collection_time",offsetof(csmi_ib_cable_history_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{"length",offsetof(csmi_ib_cable_history_record_t,length),0,NULL,0xb2deac7,4},
{"guid_s1",offsetof(csmi_ib_cable_history_record_t,guid_s1),0,NULL,0x14fe2691,4},
{"revision",offsetof(csmi_ib_cable_history_record_t,revision),0,NULL,0x2aabb274,4},
{"discovery_time",offsetof(csmi_ib_cable_history_record_t,discovery_time),0,NULL,0x603630cb,4},
{"name",offsetof(csmi_ib_cable_history_record_t,name),0,NULL,0x7c9b0c46,4},
{"port_s2",offsetof(csmi_ib_cable_history_record_t,port_s2),0,NULL,0xbc76f82e,4},
{"comment",offsetof(csmi_ib_cable_history_record_t,comment),0,NULL,0xd363aa58,4},
{"serial_number",offsetof(csmi_ib_cable_history_record_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csmi_ib_cable_history_record_t,severity),0,NULL,0x16a499a0,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"type",offsetof(csmi_ib_cable_history_record_t,type),0,NULL,0x7c9ebd07,4}}
;

void* cast_csmi_ib_cable_history_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ib_cable_history_record_t ** ptr_cast = *(csmi_ib_cable_history_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ib_cable_history_record_t= {
    25,
    csmi_ib_cable_history_record_tree,
    cast_csmi_ib_cable_history_record_t
};

const csmi_struct_node_t csmi_node_attributes_record_tree[57] = {{"type",offsetof(csmi_node_attributes_record_t,type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7c9ebd07,8},
{"available_cores",offsetof(csmi_node_attributes_record_t,available_cores),0,NULL,0x3fbd1be1,36},
{"comment",offsetof(csmi_node_attributes_record_t,comment),0,NULL,0xd363aa58,4},
{"ready",offsetof(csmi_node_attributes_record_t,ready),0,NULL,0x1046f5da,16},
{"discovered_gpus",offsetof(csmi_node_attributes_record_t,discovered_gpus),0,NULL,0x6d9c4a2b,36},
{"hard_power_cap",offsetof(csmi_node_attributes_record_t,hard_power_cap),0,NULL,0xb92ef1a3,36},
{"feature_4",offsetof(csmi_node_attributes_record_t,feature_4),0,NULL,0xd3976c24,4},
{"os_image_uuid",offsetof(csmi_node_attributes_record_t,os_image_uuid),0,NULL,0x36eafff,4},
{"kernel_version",offsetof(csmi_node_attributes_record_t,kernel_version),0,NULL,0x134c03eb,4},
{"physical_u_location",offsetof(csmi_node_attributes_record_t,physical_u_location),0,NULL,0x5783af2e,4},
{"node_name",offsetof(csmi_node_attributes_record_t,node_name),0,NULL,0x746e3e2b,4},
{"machine_model",offsetof(csmi_node_attributes_record_t,machine_model),0,NULL,0x8b68b22a,4},
{"available_processors",offsetof(csmi_node_attributes_record_t,available_processors),0,NULL,0xc0fd2a18,36},
{"feature_2",offsetof(csmi_node_attributes_record_t,feature_2),0,NULL,0xd3976c22,4},
{"serial_number",offsetof(csmi_node_attributes_record_t,serial_number),0,NULL,0xd931f68d,4},
{"os_image_name",offsetof(csmi_node_attributes_record_t,os_image_name),0,NULL,0x36a84c9,4},
{"available_gpus",offsetof(csmi_node_attributes_record_t,available_gpus),0,NULL,0x9b29be4,36},
{"state",offsetof(csmi_node_attributes_record_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"discovered_cores",offsetof(csmi_node_attributes_record_t,discovered_cores),0,NULL,0x20dc9308,36},
{"secondary_agg",offsetof(csmi_node_attributes_record_t,secondary_agg),0,NULL,0x4ccfa13b,4},
{"discovery_time",offsetof(csmi_node_attributes_record_t,discovery_time),0,NULL,0x603630cb,4},
{"discovered_hcas",offsetof(csmi_node_attributes_record_t,discovered_hcas),0,NULL,0x6d9c9cab,36},
{"physical_frame_location",offsetof(csmi_node_attributes_record_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"installed_swap",offsetof(csmi_node_attributes_record_t,installed_swap),0,NULL,0x872544bf,40},
{"primary_agg",offsetof(csmi_node_attributes_record_t,primary_agg),0,NULL,0xad402657,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"feature_1",offsetof(csmi_node_attributes_record_t,feature_1),0,NULL,0xd3976c21,4},
{"feature_3",offsetof(csmi_node_attributes_record_t,feature_3),0,NULL,0xd3976c23,4},
{"installed_memory",offsetof(csmi_node_attributes_record_t,installed_memory),0,NULL,0xd64b631d,40},
{"kernel_release",offsetof(csmi_node_attributes_record_t,kernel_release),0,NULL,0xdeeeaf06,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"discovered_dimms",offsetof(csmi_node_attributes_record_t,discovered_dimms),0,NULL,0x20eb4d06,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"discovered_ssds",offsetof(csmi_node_attributes_record_t,discovered_ssds),0,NULL,0x6da2e949,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"update_time",offsetof(csmi_node_attributes_record_t,update_time),0,NULL,0x7ceafa96,4},
{NULL,0,0,NULL,0,0},
{"discovered_sockets",offsetof(csmi_node_attributes_record_t,discovered_sockets),0,NULL,0x98e4efa8,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"collection_time",offsetof(csmi_node_attributes_record_t,collection_time),0,NULL,0xd67e7d1f,4}}
;

void* cast_csmi_node_attributes_record_t(void* ptr,size_t index, char isArray) { 
    csmi_node_attributes_record_t ** ptr_cast = *(csmi_node_attributes_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_attributes_record_t= {
    57,
    csmi_node_attributes_record_tree,
    cast_csmi_node_attributes_record_t
};

const csmi_struct_node_t csmi_node_attributes_history_record_tree[57] = {{"type",offsetof(csmi_node_attributes_history_record_t,type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7c9ebd07,8},
{"available_cores",offsetof(csmi_node_attributes_history_record_t,available_cores),0,NULL,0x3fbd1be1,36},
{"comment",offsetof(csmi_node_attributes_history_record_t,comment),0,NULL,0xd363aa58,4},
{"ready",offsetof(csmi_node_attributes_history_record_t,ready),0,NULL,0x1046f5da,16},
{"history_time",offsetof(csmi_node_attributes_history_record_t,history_time),0,NULL,0x60dc8265,4},
{"hard_power_cap",offsetof(csmi_node_attributes_history_record_t,hard_power_cap),0,NULL,0xb92ef1a3,36},
{"feature_4",offsetof(csmi_node_attributes_history_record_t,feature_4),0,NULL,0xd3976c24,4},
{"os_image_uuid",offsetof(csmi_node_attributes_history_record_t,os_image_uuid),0,NULL,0x36eafff,4},
{"kernel_version",offsetof(csmi_node_attributes_history_record_t,kernel_version),0,NULL,0x134c03eb,4},
{"physical_u_location",offsetof(csmi_node_attributes_history_record_t,physical_u_location),0,NULL,0x5783af2e,4},
{"node_name",offsetof(csmi_node_attributes_history_record_t,node_name),0,NULL,0x746e3e2b,4},
{"machine_model",offsetof(csmi_node_attributes_history_record_t,machine_model),0,NULL,0x8b68b22a,4},
{"available_processors",offsetof(csmi_node_attributes_history_record_t,available_processors),0,NULL,0xc0fd2a18,36},
{"feature_2",offsetof(csmi_node_attributes_history_record_t,feature_2),0,NULL,0xd3976c22,4},
{"serial_number",offsetof(csmi_node_attributes_history_record_t,serial_number),0,NULL,0xd931f68d,4},
{"os_image_name",offsetof(csmi_node_attributes_history_record_t,os_image_name),0,NULL,0x36a84c9,4},
{"available_gpus",offsetof(csmi_node_attributes_history_record_t,available_gpus),0,NULL,0x9b29be4,36},
{"state",offsetof(csmi_node_attributes_history_record_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"discovered_cores",offsetof(csmi_node_attributes_history_record_t,discovered_cores),0,NULL,0x20dc9308,36},
{"secondary_agg",offsetof(csmi_node_attributes_history_record_t,secondary_agg),0,NULL,0x4ccfa13b,4},
{"discovery_time",offsetof(csmi_node_attributes_history_record_t,discovery_time),0,NULL,0x603630cb,4},
{"discovered_hcas",offsetof(csmi_node_attributes_history_record_t,discovered_hcas),0,NULL,0x6d9c9cab,36},
{"physical_frame_location",offsetof(csmi_node_attributes_history_record_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"installed_swap",offsetof(csmi_node_attributes_history_record_t,installed_swap),0,NULL,0x872544bf,40},
{"primary_agg",offsetof(csmi_node_attributes_history_record_t,primary_agg),0,NULL,0xad402657,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"feature_1",offsetof(csmi_node_attributes_history_record_t,feature_1),0,NULL,0xd3976c21,4},
{"feature_3",offsetof(csmi_node_attributes_history_record_t,feature_3),0,NULL,0xd3976c23,4},
{"installed_memory",offsetof(csmi_node_attributes_history_record_t,installed_memory),0,NULL,0xd64b631d,40},
{"kernel_release",offsetof(csmi_node_attributes_history_record_t,kernel_release),0,NULL,0xdeeeaf06,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"discovered_dimms",offsetof(csmi_node_attributes_history_record_t,discovered_dimms),0,NULL,0x20eb4d06,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"discovered_gpus",offsetof(csmi_node_attributes_history_record_t,discovered_gpus),0,NULL,0x6d9c4a2b,36},
{"discovered_ssds",offsetof(csmi_node_attributes_history_record_t,discovered_ssds),0,NULL,0x6da2e949,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"update_time",offsetof(csmi_node_attributes_history_record_t,update_time),0,NULL,0x7ceafa96,4},
{NULL,0,0,NULL,0,0},
{"discovered_sockets",offsetof(csmi_node_attributes_history_record_t,discovered_sockets),0,NULL,0x98e4efa8,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"collection_time",offsetof(csmi_node_attributes_history_record_t,collection_time),0,NULL,0xd67e7d1f,4}}
;

void* cast_csmi_node_attributes_history_record_t(void* ptr,size_t index, char isArray) { 
    csmi_node_attributes_history_record_t ** ptr_cast = *(csmi_node_attributes_history_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_attributes_history_record_t= {
    57,
    csmi_node_attributes_history_record_tree,
    cast_csmi_node_attributes_history_record_t
};

const csmi_struct_node_t csmi_node_query_state_history_record_tree[7] = {{"alteration",offsetof(csmi_node_query_state_history_record_t,alteration),csmi_node_alteration_t_MAX,&csmi_node_alteration_t_strs,0x5fc5c138,8},
{"state",offsetof(csmi_node_query_state_history_record_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"ras_msg_id",offsetof(csmi_node_query_state_history_record_t,ras_msg_id),0,NULL,0xde95e99d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"history_time",offsetof(csmi_node_query_state_history_record_t,history_time),0,NULL,0x60dc8265,4},
{"ras_rec_id",offsetof(csmi_node_query_state_history_record_t,ras_rec_id),0,NULL,0xe9402c30,4}}
;

void* cast_csmi_node_query_state_history_record_t(void* ptr,size_t index, char isArray) { 
    csmi_node_query_state_history_record_t ** ptr_cast = *(csmi_node_query_state_history_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_query_state_history_record_t= {
    7,
    csmi_node_query_state_history_record_tree,
    cast_csmi_node_query_state_history_record_t
};

const csmi_struct_node_t csmi_processor_record_tree[9] = {{"status",offsetof(csmi_processor_record_t,status),0,NULL,0x1c8a8d49,68},
{"socket",offsetof(csmi_processor_record_t,socket),0,NULL,0x1c31032e,36},
{"node_name",offsetof(csmi_processor_record_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"available_cores",offsetof(csmi_processor_record_t,available_cores),0,NULL,0x3fbd1be1,36},
{"serial_number",offsetof(csmi_processor_record_t,serial_number),0,NULL,0xd931f68d,4},
{"discovered_cores",offsetof(csmi_processor_record_t,discovered_cores),0,NULL,0x20dc9308,36},
{"physical_location",offsetof(csmi_processor_record_t,physical_location),0,NULL,0x63efcf7a,4}}
;

void* cast_csmi_processor_record_t(void* ptr,size_t index, char isArray) { 
    csmi_processor_record_t ** ptr_cast = *(csmi_processor_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_processor_record_t= {
    9,
    csmi_processor_record_tree,
    cast_csmi_processor_record_t
};

const csmi_struct_node_t csmi_ssd_record_tree[25] = {{"wear_total_bytes_read",offsetof(csmi_ssd_record_t,wear_total_bytes_read),0,NULL,0x9e5253b8,40},
{"wear_lifespan_used",offsetof(csmi_ssd_record_t,wear_lifespan_used),0,NULL,0x7bc95915,56},
{"total_size",offsetof(csmi_ssd_record_t,total_size),0,NULL,0xc7f736e3,40},
{"discovery_time",offsetof(csmi_ssd_record_t,discovery_time),0,NULL,0x603630cb,4},
{"size",offsetof(csmi_ssd_record_t,size),0,NULL,0x7c9dede0,40},
{"wear_total_bytes_written",offsetof(csmi_ssd_record_t,wear_total_bytes_written),0,NULL,0xa2cc1da9,40},
{"wear_percent_spares_remaining",offsetof(csmi_ssd_record_t,wear_percent_spares_remaining),0,NULL,0xe9d9e3aa,56},
{"status",offsetof(csmi_ssd_record_t,status),0,NULL,0x1c8a8d49,68},
{"node_name",offsetof(csmi_ssd_record_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{"update_time",offsetof(csmi_ssd_record_t,update_time),0,NULL,0x7ceafa96,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"serial_number",offsetof(csmi_ssd_record_t,serial_number),0,NULL,0xd931f68d,4},
{"device_name",offsetof(csmi_ssd_record_t,device_name),0,NULL,0xeb7bd8d5,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"pci_bus_id",offsetof(csmi_ssd_record_t,pci_bus_id),0,NULL,0x6b695f36,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"fw_ver",offsetof(csmi_ssd_record_t,fw_ver),0,NULL,0xfe6cb44e,4}}
;

void* cast_csmi_ssd_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ssd_record_t ** ptr_cast = *(csmi_ssd_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ssd_record_t= {
    25,
    csmi_ssd_record_tree,
    cast_csmi_ssd_record_t
};

const csmi_struct_node_t csmi_switch_record_tree[44] = {{"discovery_time",offsetof(csmi_switch_record_t,discovery_time),0,NULL,0x603630cb,4},
{"fw_version",offsetof(csmi_switch_record_t,fw_version),0,NULL,0x136b0847,4},
{"has_ufm_agent",offsetof(csmi_switch_record_t,has_ufm_agent),0,NULL,0xaab4c3f6,16},
{"gu_id",offsetof(csmi_switch_record_t,gu_id),0,NULL,0xf88a66d,4},
{"num_modules",offsetof(csmi_switch_record_t,num_modules),0,NULL,0x284a2a6d,36},
{"system_name",offsetof(csmi_switch_record_t,system_name),0,NULL,0x82ba5f6a,4},
{"collection_time",offsetof(csmi_switch_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{"ip",offsetof(csmi_switch_record_t,ip),0,NULL,0x59783e,4},
{"ps_id",offsetof(csmi_switch_record_t,ps_id),0,NULL,0x102a6a34,4},
{"hw_version",offsetof(csmi_switch_record_t,hw_version),0,NULL,0x1b802a89,4},
{"switch_name",offsetof(csmi_switch_record_t,switch_name),0,NULL,0x482a8e77,4},
{"role",offsetof(csmi_switch_record_t,role),0,NULL,0x7c9d7937,4},
{"description",offsetof(csmi_switch_record_t,description),0,NULL,0x91b0c789,4},
{"comment",offsetof(csmi_switch_record_t,comment),0,NULL,0xd363aa58,4},
{"serial_number",offsetof(csmi_switch_record_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"model",offsetof(csmi_switch_record_t,model),0,NULL,0xff203f6,4},
{"state",offsetof(csmi_switch_record_t,state),0,NULL,0x10614a06,4},
{NULL,0,0,NULL,0,0},
{"vendor",offsetof(csmi_switch_record_t,vendor),0,NULL,0x228173b3,4},
{"sw_version",offsetof(csmi_switch_record_t,sw_version),0,NULL,0x47f466f4,4},
{"physical_u_location",offsetof(csmi_switch_record_t,physical_u_location),0,NULL,0x5783af2e,4},
{"physical_frame_location",offsetof(csmi_switch_record_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"system_guid",offsetof(csmi_switch_record_t,system_guid),0,NULL,0x82b6dd52,4},
{"server_operation_mode",offsetof(csmi_switch_record_t,server_operation_mode),0,NULL,0x87894af0,4},
{"sm_mode",offsetof(csmi_switch_record_t,sm_mode),0,NULL,0x9d5ff749,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"total_alarms",offsetof(csmi_switch_record_t,total_alarms),0,NULL,0x78cc7a28,36},
{"type",offsetof(csmi_switch_record_t,type),0,NULL,0x7c9ebd07,4}}
;

void* cast_csmi_switch_record_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_record_t ** ptr_cast = *(csmi_switch_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_record_t= {
    44,
    csmi_switch_record_tree,
    cast_csmi_switch_record_t
};

const csmi_struct_node_t csmi_switch_inventory_record_tree[27] = {{"name",offsetof(csmi_switch_inventory_record_t,name),0,NULL,0x7c9b0c46,4},
{"max_ib_ports",offsetof(csmi_switch_inventory_record_t,max_ib_ports),0,NULL,0x1c135c0c,36},
{"host_system_guid",offsetof(csmi_switch_inventory_record_t,host_system_guid),0,NULL,0xd5e2674f,4},
{"severity",offsetof(csmi_switch_inventory_record_t,severity),0,NULL,0x16a499a0,4},
{"discovery_time",offsetof(csmi_switch_inventory_record_t,discovery_time),0,NULL,0x603630cb,4},
{"module_index",offsetof(csmi_switch_inventory_record_t,module_index),0,NULL,0xc43864a2,36},
{"device_name",offsetof(csmi_switch_inventory_record_t,device_name),0,NULL,0xeb7bd8d5,4},
{"number_of_chips",offsetof(csmi_switch_inventory_record_t,number_of_chips),0,NULL,0x45b74b8,36},
{"hw_version",offsetof(csmi_switch_inventory_record_t,hw_version),0,NULL,0x1b802a89,4},
{"status",offsetof(csmi_switch_inventory_record_t,status),0,NULL,0x1c8a8d49,4},
{NULL,0,0,NULL,0,0},
{"description",offsetof(csmi_switch_inventory_record_t,description),0,NULL,0x91b0c789,4},
{"comment",offsetof(csmi_switch_inventory_record_t,comment),0,NULL,0xd363aa58,4},
{"collection_time",offsetof(csmi_switch_inventory_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{"device_type",offsetof(csmi_switch_inventory_record_t,device_type),0,NULL,0xeb7f8996,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"path",offsetof(csmi_switch_inventory_record_t,path),0,NULL,0x7c9c25f2,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"serial_number",offsetof(csmi_switch_inventory_record_t,serial_number),0,NULL,0xd931f68d,4}}
;

void* cast_csmi_switch_inventory_record_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_inventory_record_t ** ptr_cast = *(csmi_switch_inventory_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_inventory_record_t= {
    27,
    csmi_switch_inventory_record_tree,
    cast_csmi_switch_inventory_record_t
};

const csmi_struct_node_t csmi_switch_ports_record_tree[42] = {{"description",offsetof(csmi_switch_ports_record_t,description),0,NULL,0x91b0c789,4},
{"enabled_speed",offsetof(csmi_switch_ports_record_t,enabled_speed),0,NULL,0x2c6b10c0,4},
{"comment",offsetof(csmi_switch_ports_record_t,comment),0,NULL,0xd363aa58,4},
{"mirror",offsetof(csmi_switch_ports_record_t,mirror),0,NULL,0xdcdd520,4},
{"guid",offsetof(csmi_switch_ports_record_t,guid),0,NULL,0x7c978a2e,4},
{"width_active",offsetof(csmi_switch_ports_record_t,width_active),0,NULL,0x9e6db9c0,4},
{"collection_time",offsetof(csmi_switch_ports_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{"lid",offsetof(csmi_switch_ports_record_t,lid),0,NULL,0xb888c3e,4},
{"number",offsetof(csmi_switch_ports_record_t,number),0,NULL,0x10f9208e,4},
{"discovery_time",offsetof(csmi_switch_ports_record_t,discovery_time),0,NULL,0x603630cb,4},
{"peer",offsetof(csmi_switch_ports_record_t,peer),0,NULL,0x7c9c3511,4},
{"external_number",offsetof(csmi_switch_ports_record_t,external_number),0,NULL,0x9a390390,4},
{"width_enabled",offsetof(csmi_switch_ports_record_t,width_enabled),0,NULL,0xb85ad14f,4},
{NULL,0,0,NULL,0,0},
{"physical_state",offsetof(csmi_switch_ports_record_t,physical_state),0,NULL,0xdbbc7de2,4},
{NULL,0,0,NULL,0,0},
{"mtu",offsetof(csmi_switch_ports_record_t,mtu),0,NULL,0xb8891fb,4},
{"module",offsetof(csmi_switch_ports_record_t,module),0,NULL,0xe32c72b,4},
{"parent",offsetof(csmi_switch_ports_record_t,parent),0,NULL,0x143c538f,4},
{"active_speed",offsetof(csmi_switch_ports_record_t,active_speed),0,NULL,0x3e93add1,4},
{"logical_state",offsetof(csmi_switch_ports_record_t,logical_state),0,NULL,0x63daa400,4},
{"name",offsetof(csmi_switch_ports_record_t,name),0,NULL,0x7c9b0c46,4},
{"system_guid",offsetof(csmi_switch_ports_record_t,system_guid),0,NULL,0x82b6dd52,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"width_supported",offsetof(csmi_switch_ports_record_t,width_supported),0,NULL,0xb27ee54a,4},
{"supported_speed",offsetof(csmi_switch_ports_record_t,supported_speed),0,NULL,0xc0a0393b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csmi_switch_ports_record_t,severity),0,NULL,0x16a499a0,4},
{"max_supported_speed",offsetof(csmi_switch_ports_record_t,max_supported_speed),0,NULL,0x3c485ae0,4},
{"mirror_traffic",offsetof(csmi_switch_ports_record_t,mirror_traffic),0,NULL,0x43338b1e,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"tier",offsetof(csmi_switch_ports_record_t,tier),0,NULL,0x7c9e7799,4}}
;

void* cast_csmi_switch_ports_record_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_ports_record_t ** ptr_cast = *(csmi_switch_ports_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_ports_record_t= {
    42,
    csmi_switch_ports_record_tree,
    cast_csmi_switch_ports_record_t
};

const csmi_struct_node_t csmi_switch_details_tree[6] = {{"switch_data",offsetof(csmi_switch_details_t,switch_data),0,&map_csmi_switch_record_t,0x48251390,0},
{"inventory_count",offsetof(csmi_switch_details_t,inventory_count),0,NULL,0xde0c63b,24},
{"inventory",offsetof(csmi_switch_details_t,inventory),offsetof(csmi_switch_details_t, inventory_count),&map_csmi_switch_inventory_record_t,0xac696ff3,1},
{NULL,0,0,NULL,0,0},
{"ports",offsetof(csmi_switch_details_t,ports),offsetof(csmi_switch_details_t, ports_count),&map_csmi_switch_ports_record_t,0x10288afd,1},
{"ports_count",offsetof(csmi_switch_details_t,ports_count),0,NULL,0x6b0e80c5,24}}
;

void* cast_csmi_switch_details_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_details_t ** ptr_cast = *(csmi_switch_details_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_details_t= {
    6,
    csmi_switch_details_tree,
    cast_csmi_switch_details_t
};

const csmi_struct_node_t csmi_switch_history_record_tree[49] = {{"history_time",offsetof(csmi_switch_history_record_t,history_time),0,NULL,0x60dc8265,4},
{"fw_version",offsetof(csmi_switch_history_record_t,fw_version),0,NULL,0x136b0847,4},
{"has_ufm_agent",offsetof(csmi_switch_history_record_t,has_ufm_agent),0,NULL,0xaab4c3f6,16},
{"gu_id",offsetof(csmi_switch_history_record_t,gu_id),0,NULL,0xf88a66d,4},
{"switch_name",offsetof(csmi_switch_history_record_t,switch_name),0,NULL,0x482a8e77,4},
{"system_name",offsetof(csmi_switch_history_record_t,system_name),0,NULL,0x82ba5f6a,4},
{"collection_time",offsetof(csmi_switch_history_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{"ip",offsetof(csmi_switch_history_record_t,ip),0,NULL,0x59783e,4},
{"ps_id",offsetof(csmi_switch_history_record_t,ps_id),0,NULL,0x102a6a34,4},
{"num_modules",offsetof(csmi_switch_history_record_t,num_modules),0,NULL,0x284a2a6d,36},
{"discovery_time",offsetof(csmi_switch_history_record_t,discovery_time),0,NULL,0x603630cb,4},
{"role",offsetof(csmi_switch_history_record_t,role),0,NULL,0x7c9d7937,4},
{"description",offsetof(csmi_switch_history_record_t,description),0,NULL,0x91b0c789,4},
{"comment",offsetof(csmi_switch_history_record_t,comment),0,NULL,0xd363aa58,4},
{"serial_number",offsetof(csmi_switch_history_record_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"model",offsetof(csmi_switch_history_record_t,model),0,NULL,0xff203f6,4},
{"state",offsetof(csmi_switch_history_record_t,state),0,NULL,0x10614a06,4},
{"hw_version",offsetof(csmi_switch_history_record_t,hw_version),0,NULL,0x1b802a89,4},
{"sw_version",offsetof(csmi_switch_history_record_t,sw_version),0,NULL,0x47f466f4,4},
{"physical_u_location",offsetof(csmi_switch_history_record_t,physical_u_location),0,NULL,0x5783af2e,4},
{NULL,0,0,NULL,0,0},
{"physical_frame_location",offsetof(csmi_switch_history_record_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"system_guid",offsetof(csmi_switch_history_record_t,system_guid),0,NULL,0x82b6dd52,4},
{"server_operation_mode",offsetof(csmi_switch_history_record_t,server_operation_mode),0,NULL,0x87894af0,4},
{"sm_mode",offsetof(csmi_switch_history_record_t,sm_mode),0,NULL,0x9d5ff749,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"vendor",offsetof(csmi_switch_history_record_t,vendor),0,NULL,0x228173b3,4},
{"operation",offsetof(csmi_switch_history_record_t,operation),0,NULL,0x40a16e96,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"total_alarms",offsetof(csmi_switch_history_record_t,total_alarms),0,NULL,0x78cc7a28,36},
{"type",offsetof(csmi_switch_history_record_t,type),0,NULL,0x7c9ebd07,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"archive_history_time",offsetof(csmi_switch_history_record_t,archive_history_time),0,NULL,0x9e88b9e6,4}}
;

void* cast_csmi_switch_history_record_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_history_record_t ** ptr_cast = *(csmi_switch_history_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_history_record_t= {
    49,
    csmi_switch_history_record_tree,
    cast_csmi_switch_history_record_t
};

const csmi_struct_node_t csmi_node_env_data_tree[1] = {{"field_01",offsetof(csmi_node_env_data_t,field_01),0,NULL,0x2404d529,68}}
;

void* cast_csmi_node_env_data_t(void* ptr,size_t index, char isArray) { 
    csmi_node_env_data_t ** ptr_cast = *(csmi_node_env_data_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_env_data_t= {
    1,
    csmi_node_env_data_tree,
    cast_csmi_node_env_data_t
};

const csmi_struct_node_t csmi_switch_env_data_tree[1] = {{"field_01",offsetof(csmi_switch_env_data_t,field_01),0,NULL,0x2404d529,68}}
;

void* cast_csmi_switch_env_data_t(void* ptr,size_t index, char isArray) { 
    csmi_switch_env_data_t ** ptr_cast = *(csmi_switch_env_data_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_switch_env_data_t= {
    1,
    csmi_switch_env_data_tree,
    cast_csmi_switch_env_data_t
};

const csmi_struct_node_t csmi_fabric_topology_tree[1] = {{"field_01",offsetof(csmi_fabric_topology_t,field_01),0,NULL,0x2404d529,68}}
;

void* cast_csmi_fabric_topology_t(void* ptr,size_t index, char isArray) { 
    csmi_fabric_topology_t ** ptr_cast = *(csmi_fabric_topology_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_fabric_topology_t= {
    1,
    csmi_fabric_topology_tree,
    cast_csmi_fabric_topology_t
};

const csmi_struct_node_t csmi_node_details_tree[14] = {{"dimms_count",offsetof(csmi_node_details_t,dimms_count),0,NULL,0x563b93c7,24},
{"ssds_count",offsetof(csmi_node_details_t,ssds_count),0,NULL,0x1d4cb32a,24},
{"node",offsetof(csmi_node_details_t,node),0,&map_csmi_node_attributes_record_t,0x7c9b46ab,0},
{"dimms",offsetof(csmi_node_details_t,dimms),offsetof(csmi_node_details_t, dimms_count),&map_csmi_dimm_record_t,0xf4c047f,1},
{"gpus_count",offsetof(csmi_node_details_t,gpus_count),0,NULL,0x3fb7b58c,24},
{"gpus",offsetof(csmi_node_details_t,gpus),offsetof(csmi_node_details_t, gpus_count),&map_csmi_gpu_record_t,0x7c977684,1},
{"hcas_count",offsetof(csmi_node_details_t,hcas_count),0,NULL,0xe44be80c,24},
{"processors",offsetof(csmi_node_details_t,processors),offsetof(csmi_node_details_t, processors_count),&map_csmi_processor_record_t,0x3037cb8,1},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"processors_count",offsetof(csmi_node_details_t,processors_count),0,NULL,0x676492c0,24},
{"hcas",offsetof(csmi_node_details_t,hcas),offsetof(csmi_node_details_t, hcas_count),&map_csmi_hca_record_t,0x7c97c904,1},
{"ssds",offsetof(csmi_node_details_t,ssds),offsetof(csmi_node_details_t, ssds_count),&map_csmi_ssd_record_t,0x7c9e15a2,1}}
;

void* cast_csmi_node_details_t(void* ptr,size_t index, char isArray) { 
    csmi_node_details_t ** ptr_cast = *(csmi_node_details_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_details_t= {
    14,
    csmi_node_details_tree,
    cast_csmi_node_details_t
};

const csmi_struct_node_t csmi_cluster_query_state_record_tree[15] = {{"node_name",offsetof(csmi_cluster_query_state_record_t,node_name),0,NULL,0x746e3e2b,4},
{"states",offsetof(csmi_cluster_query_state_record_t,states),offsetof(csmi_cluster_query_state_record_t, num_allocs),NULL,0x1c8a8b39,5},
{"update_time",offsetof(csmi_cluster_query_state_record_t,update_time),0,NULL,0x7ceafa96,4},
{"state",offsetof(csmi_cluster_query_state_record_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"num_allocs",offsetof(csmi_cluster_query_state_record_t,num_allocs),0,NULL,0x421fea12,24},
{"type",offsetof(csmi_cluster_query_state_record_t,type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7c9ebd07,8},
{"collection_time",offsetof(csmi_cluster_query_state_record_t,collection_time),0,NULL,0xd67e7d1f,4},
{NULL,0,0,NULL,0,0},
{"shared",offsetof(csmi_cluster_query_state_record_t,shared),offsetof(csmi_cluster_query_state_record_t, num_allocs),NULL,0x1bb15c9c,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"allocs",offsetof(csmi_cluster_query_state_record_t,allocs),offsetof(csmi_cluster_query_state_record_t, num_allocs),NULL,0xf202de83,1}}
;

void* cast_csmi_cluster_query_state_record_t(void* ptr,size_t index, char isArray) { 
    csmi_cluster_query_state_record_t ** ptr_cast = *(csmi_cluster_query_state_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_cluster_query_state_record_t= {
    15,
    csmi_cluster_query_state_record_tree,
    cast_csmi_cluster_query_state_record_t
};

const csmi_struct_node_t csmi_node_find_job_record_tree[11] = {{"allocation_id",offsetof(csmi_node_find_job_record_t,allocation_id),0,NULL,0x99d3da77,40},
{"node_name",offsetof(csmi_node_find_job_record_t,node_name),0,NULL,0x746e3e2b,4},
{"user_name",offsetof(csmi_node_find_job_record_t,user_name),0,NULL,0xc029f5a4,4},
{"begin_time",offsetof(csmi_node_find_job_record_t,begin_time),0,NULL,0x5f818b18,4},
{NULL,0,0,NULL,0,0},
{"num_nodes",offsetof(csmi_node_find_job_record_t,num_nodes),0,NULL,0xa5d6722d,36},
{"primary_job_id",offsetof(csmi_node_find_job_record_t,primary_job_id),0,NULL,0xcfd430cf,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"end_time",offsetof(csmi_node_find_job_record_t,end_time),0,NULL,0xb56ec18a,4}}
;

void* cast_csmi_node_find_job_record_t(void* ptr,size_t index, char isArray) { 
    csmi_node_find_job_record_t ** ptr_cast = *(csmi_node_find_job_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_node_find_job_record_t= {
    11,
    csmi_node_find_job_record_tree,
    cast_csmi_node_find_job_record_t
};

const csmi_struct_node_t csm_ib_cable_inventory_collection_input_tree[3] = {{"inventory_count",offsetof(csm_ib_cable_inventory_collection_input_t,inventory_count),0,NULL,0xde0c63b,24},
{NULL,0,0,NULL,0,0},
{"inventory",offsetof(csm_ib_cable_inventory_collection_input_t,inventory),offsetof(csm_ib_cable_inventory_collection_input_t, inventory_count),&map_csmi_ib_cable_record_t,0xac696ff3,1}}
;

void* cast_csm_ib_cable_inventory_collection_input_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_inventory_collection_input_t ** ptr_cast = *(csm_ib_cable_inventory_collection_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_inventory_collection_input_t= {
    3,
    csm_ib_cable_inventory_collection_input_tree,
    cast_csm_ib_cable_inventory_collection_input_t
};

const csmi_struct_node_t csm_ib_cable_inventory_collection_output_tree[3] = {{"update_count",offsetof(csm_ib_cable_inventory_collection_output_t,update_count),0,NULL,0x191a1ab0,36},
{"delete_count",offsetof(csm_ib_cable_inventory_collection_output_t,delete_count),0,NULL,0x103b6a80,36},
{"insert_count",offsetof(csm_ib_cable_inventory_collection_output_t,insert_count),0,NULL,0x7bae7a22,36}}
;

void* cast_csm_ib_cable_inventory_collection_output_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_inventory_collection_output_t ** ptr_cast = *(csm_ib_cable_inventory_collection_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_inventory_collection_output_t= {
    3,
    csm_ib_cable_inventory_collection_output_tree,
    cast_csm_ib_cable_inventory_collection_output_t
};

const csmi_struct_node_t csm_ib_cable_query_input_tree[7] = {{"offset",offsetof(csm_ib_cable_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_ib_cable_query_input_t,limit),0,NULL,0xfdcc804,36},
{"serial_numbers_count",offsetof(csm_ib_cable_query_input_t,serial_numbers_count),0,NULL,0x54252ca8,24},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"serial_numbers",offsetof(csm_ib_cable_query_input_t,serial_numbers),offsetof(csm_ib_cable_query_input_t, serial_numbers_count),NULL,0xff70c8a0,5}}
;

void* cast_csm_ib_cable_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_query_input_t ** ptr_cast = *(csm_ib_cable_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_query_input_t= {
    7,
    csm_ib_cable_query_input_tree,
    cast_csm_ib_cable_query_input_t
};

const csmi_struct_node_t csm_ib_cable_query_output_tree[2] = {{"results_count",offsetof(csm_ib_cable_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_ib_cable_query_output_t,results),offsetof(csm_ib_cable_query_output_t, results_count),&map_csmi_ib_cable_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_ib_cable_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_query_output_t ** ptr_cast = *(csm_ib_cable_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_query_output_t= {
    2,
    csm_ib_cable_query_output_tree,
    cast_csm_ib_cable_query_output_t
};

const csmi_struct_node_t csm_ib_cable_query_history_input_tree[3] = {{"offset",offsetof(csm_ib_cable_query_history_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_ib_cable_query_history_input_t,limit),0,NULL,0xfdcc804,36},
{"serial_number",offsetof(csm_ib_cable_query_history_input_t,serial_number),0,NULL,0xd931f68d,4}}
;

void* cast_csm_ib_cable_query_history_input_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_query_history_input_t ** ptr_cast = *(csm_ib_cable_query_history_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_query_history_input_t= {
    3,
    csm_ib_cable_query_history_input_tree,
    cast_csm_ib_cable_query_history_input_t
};

const csmi_struct_node_t csm_ib_cable_query_history_output_tree[2] = {{"results_count",offsetof(csm_ib_cable_query_history_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_ib_cable_query_history_output_t,results),offsetof(csm_ib_cable_query_history_output_t, results_count),&map_csmi_ib_cable_history_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_ib_cable_query_history_output_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_query_history_output_t ** ptr_cast = *(csm_ib_cable_query_history_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_query_history_output_t= {
    2,
    csm_ib_cable_query_history_output_tree,
    cast_csm_ib_cable_query_history_output_t
};

const csmi_struct_node_t csm_ib_cable_update_input_tree[11] = {{"comment",offsetof(csm_ib_cable_update_input_t,comment),0,NULL,0xd363aa58,4},
{"guid_s2",offsetof(csm_ib_cable_update_input_t,guid_s2),0,NULL,0x14fe2692,4},
{"serial_numbers",offsetof(csm_ib_cable_update_input_t,serial_numbers),offsetof(csm_ib_cable_update_input_t, serial_numbers_count),NULL,0xff70c8a0,5},
{"guid_s1",offsetof(csm_ib_cable_update_input_t,guid_s1),0,NULL,0x14fe2691,4},
{"port_s1",offsetof(csm_ib_cable_update_input_t,port_s1),0,NULL,0xbc76f82d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"serial_numbers_count",offsetof(csm_ib_cable_update_input_t,serial_numbers_count),0,NULL,0x54252ca8,24},
{"port_s2",offsetof(csm_ib_cable_update_input_t,port_s2),0,NULL,0xbc76f82e,4}}
;

void* cast_csm_ib_cable_update_input_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_update_input_t ** ptr_cast = *(csm_ib_cable_update_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_update_input_t= {
    11,
    csm_ib_cable_update_input_tree,
    cast_csm_ib_cable_update_input_t
};

const csmi_struct_node_t csm_ib_cable_update_output_tree[2] = {{"failure_count",offsetof(csm_ib_cable_update_output_t,failure_count),0,NULL,0xb64de7b5,24},
{"failure_ib_cables",offsetof(csm_ib_cable_update_output_t,failure_ib_cables),offsetof(csm_ib_cable_update_output_t, failure_count),NULL,0x78fd5dc0,5}}
;

void* cast_csm_ib_cable_update_output_t(void* ptr,size_t index, char isArray) { 
    csm_ib_cable_update_output_t ** ptr_cast = *(csm_ib_cable_update_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ib_cable_update_output_t= {
    2,
    csm_ib_cable_update_output_tree,
    cast_csm_ib_cable_update_output_t
};

const csmi_struct_node_t csm_node_attributes_query_input_tree[11] = {{"offset",offsetof(csm_node_attributes_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_node_attributes_query_input_t,limit),0,NULL,0xfdcc804,36},
{"node_names_count",offsetof(csm_node_attributes_query_input_t,node_names_count),0,NULL,0x868cf686,24},
{"node_names",offsetof(csm_node_attributes_query_input_t,node_names),offsetof(csm_node_attributes_query_input_t, node_names_count),NULL,0x23603fe,5},
{"ready",offsetof(csm_node_attributes_query_input_t,ready),0,NULL,0x1046f5da,16},
{"type",offsetof(csm_node_attributes_query_input_t,type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7c9ebd07,8},
{"comment",offsetof(csm_node_attributes_query_input_t,comment),0,NULL,0xd363aa58,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"state",offsetof(csm_node_attributes_query_input_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8}}
;

void* cast_csm_node_attributes_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_input_t ** ptr_cast = *(csm_node_attributes_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_input_t= {
    11,
    csm_node_attributes_query_input_tree,
    cast_csm_node_attributes_query_input_t
};

const csmi_struct_node_t csm_node_attributes_query_output_tree[2] = {{"results_count",offsetof(csm_node_attributes_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_node_attributes_query_output_t,results),offsetof(csm_node_attributes_query_output_t, results_count),&map_csmi_node_attributes_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_node_attributes_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_output_t ** ptr_cast = *(csm_node_attributes_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_output_t= {
    2,
    csm_node_attributes_query_output_tree,
    cast_csm_node_attributes_query_output_t
};

const csmi_struct_node_t csm_node_attributes_query_details_input_tree[1] = {{"node_name",offsetof(csm_node_attributes_query_details_input_t,node_name),0,NULL,0x746e3e2b,4}}
;

void* cast_csm_node_attributes_query_details_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_details_input_t ** ptr_cast = *(csm_node_attributes_query_details_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_details_input_t= {
    1,
    csm_node_attributes_query_details_input_tree,
    cast_csm_node_attributes_query_details_input_t
};

const csmi_struct_node_t csm_node_attributes_query_details_output_tree[2] = {{"result_count",offsetof(csm_node_attributes_query_details_output_t,result_count),0,NULL,0x4236760c,24},
{"result",offsetof(csm_node_attributes_query_details_output_t,result),offsetof(csm_node_attributes_query_details_output_t, result_count),&map_csmi_node_details_t,0x192fd704,1}}
;

void* cast_csm_node_attributes_query_details_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_details_output_t ** ptr_cast = *(csm_node_attributes_query_details_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_details_output_t= {
    2,
    csm_node_attributes_query_details_output_tree,
    cast_csm_node_attributes_query_details_output_t
};

const csmi_struct_node_t csm_node_attributes_query_history_input_tree[6] = {{"offset",offsetof(csm_node_attributes_query_history_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_node_attributes_query_history_input_t,limit),0,NULL,0xfdcc804,36},
{"node_name",offsetof(csm_node_attributes_query_history_input_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"order_by",offsetof(csm_node_attributes_query_history_input_t,order_by),0,NULL,0x245553bb,68}}
;

void* cast_csm_node_attributes_query_history_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_history_input_t ** ptr_cast = *(csm_node_attributes_query_history_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_history_input_t= {
    6,
    csm_node_attributes_query_history_input_tree,
    cast_csm_node_attributes_query_history_input_t
};

const csmi_struct_node_t csm_node_attributes_query_history_output_tree[2] = {{"results_count",offsetof(csm_node_attributes_query_history_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_node_attributes_query_history_output_t,results),offsetof(csm_node_attributes_query_history_output_t, results_count),&map_csmi_node_attributes_history_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_node_attributes_query_history_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_query_history_output_t ** ptr_cast = *(csm_node_attributes_query_history_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_query_history_output_t= {
    2,
    csm_node_attributes_query_history_output_tree,
    cast_csm_node_attributes_query_history_output_t
};

const csmi_struct_node_t csm_node_query_state_history_input_tree[6] = {{"offset",offsetof(csm_node_query_state_history_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_node_query_state_history_input_t,limit),0,NULL,0xfdcc804,36},
{"node_name",offsetof(csm_node_query_state_history_input_t,node_name),0,NULL,0x746e3e2b,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"order_by",offsetof(csm_node_query_state_history_input_t,order_by),0,NULL,0x245553bb,68}}
;

void* cast_csm_node_query_state_history_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_query_state_history_input_t ** ptr_cast = *(csm_node_query_state_history_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_query_state_history_input_t= {
    6,
    csm_node_query_state_history_input_tree,
    cast_csm_node_query_state_history_input_t
};

const csmi_struct_node_t csm_node_query_state_history_output_tree[3] = {{"node_name",offsetof(csm_node_query_state_history_output_t,node_name),0,NULL,0x746e3e2b,4},
{"results",offsetof(csm_node_query_state_history_output_t,results),offsetof(csm_node_query_state_history_output_t, results_count),&map_csmi_node_query_state_history_record_t,0x3f2ab7f7,1},
{"results_count",offsetof(csm_node_query_state_history_output_t,results_count),0,NULL,0x8261013f,24}}
;

void* cast_csm_node_query_state_history_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_query_state_history_output_t ** ptr_cast = *(csm_node_query_state_history_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_query_state_history_output_t= {
    3,
    csm_node_query_state_history_output_tree,
    cast_csm_node_query_state_history_output_t
};

const csmi_struct_node_t csm_node_attributes_update_input_tree[15] = {{"comment",offsetof(csm_node_attributes_update_input_t,comment),0,NULL,0xd363aa58,4},
{"state",offsetof(csm_node_attributes_update_input_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"feature_2",offsetof(csm_node_attributes_update_input_t,feature_2),0,NULL,0xd3976c22,4},
{"ready",offsetof(csm_node_attributes_update_input_t,ready),0,NULL,0x1046f5da,16},
{"physical_frame_location",offsetof(csm_node_attributes_update_input_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"feature_1",offsetof(csm_node_attributes_update_input_t,feature_1),0,NULL,0xd3976c21,4},
{"feature_3",offsetof(csm_node_attributes_update_input_t,feature_3),0,NULL,0xd3976c23,4},
{"node_names",offsetof(csm_node_attributes_update_input_t,node_names),offsetof(csm_node_attributes_update_input_t, node_names_count),NULL,0x23603fe,5},
{NULL,0,0,NULL,0,0},
{"physical_u_location",offsetof(csm_node_attributes_update_input_t,physical_u_location),0,NULL,0x5783af2e,4},
{"node_names_count",offsetof(csm_node_attributes_update_input_t,node_names_count),0,NULL,0x868cf686,24},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"feature_4",offsetof(csm_node_attributes_update_input_t,feature_4),0,NULL,0xd3976c24,4}}
;

void* cast_csm_node_attributes_update_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_update_input_t ** ptr_cast = *(csm_node_attributes_update_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_update_input_t= {
    15,
    csm_node_attributes_update_input_tree,
    cast_csm_node_attributes_update_input_t
};

const csmi_struct_node_t csm_node_attributes_update_output_tree[3] = {{"failure_count",offsetof(csm_node_attributes_update_output_t,failure_count),0,NULL,0xb64de7b5,24},
{NULL,0,0,NULL,0,0},
{"failure_node_names",offsetof(csm_node_attributes_update_output_t,failure_node_names),offsetof(csm_node_attributes_update_output_t, failure_count),NULL,0xca9637a5,5}}
;

void* cast_csm_node_attributes_update_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_attributes_update_output_t ** ptr_cast = *(csm_node_attributes_update_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_attributes_update_output_t= {
    3,
    csm_node_attributes_update_output_tree,
    cast_csm_node_attributes_update_output_t
};

const csmi_struct_node_t csm_node_delete_input_tree[2] = {{"node_names_count",offsetof(csm_node_delete_input_t,node_names_count),0,NULL,0x868cf686,24},
{"node_names",offsetof(csm_node_delete_input_t,node_names),offsetof(csm_node_delete_input_t, node_names_count),NULL,0x23603fe,5}}
;

void* cast_csm_node_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_delete_input_t ** ptr_cast = *(csm_node_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_delete_input_t= {
    2,
    csm_node_delete_input_tree,
    cast_csm_node_delete_input_t
};

const csmi_struct_node_t csm_node_delete_output_tree[3] = {{"failure_count",offsetof(csm_node_delete_output_t,failure_count),0,NULL,0xb64de7b5,24},
{NULL,0,0,NULL,0,0},
{"failure_node_names",offsetof(csm_node_delete_output_t,failure_node_names),offsetof(csm_node_delete_output_t, failure_count),NULL,0xca9637a5,5}}
;

void* cast_csm_node_delete_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_delete_output_t ** ptr_cast = *(csm_node_delete_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_delete_output_t= {
    3,
    csm_node_delete_output_tree,
    cast_csm_node_delete_output_t
};

const csmi_struct_node_t csm_node_find_job_input_tree[21] = {{"begin_time_search_begin",offsetof(csm_node_find_job_input_t,begin_time_search_begin),0,NULL,0x34e5bb11,4},
{"offset",offsetof(csm_node_find_job_input_t,offset),0,NULL,0x123b4b4c,36},
{"begin_time_search_end",offsetof(csm_node_find_job_input_t,begin_time_search_end),0,NULL,0xc583ac83,4},
{"limit",offsetof(csm_node_find_job_input_t,limit),0,NULL,0xfdcc804,36},
{"order_by",offsetof(csm_node_find_job_input_t,order_by),0,NULL,0x245553bb,68},
{"end_time_search_end",offsetof(csm_node_find_job_input_t,end_time_search_end),0,NULL,0x8f62b7b5,4},
{"end_time_search_begin",offsetof(csm_node_find_job_input_t,end_time_search_begin),0,NULL,0xf2b45ac3,4},
{"node_names",offsetof(csm_node_find_job_input_t,node_names),offsetof(csm_node_find_job_input_t, node_names_count),NULL,0x23603fe,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"search_range_end",offsetof(csm_node_find_job_input_t,search_range_end),0,NULL,0x7bb36a5d,4},
{"midpoint_interval",offsetof(csm_node_find_job_input_t,midpoint_interval),0,NULL,0x9f223e4d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"search_range_begin",offsetof(csm_node_find_job_input_t,search_range_begin),0,NULL,0x35fc576b,4},
{"node_names_count",offsetof(csm_node_find_job_input_t,node_names_count),0,NULL,0x868cf686,24},
{"midpoint",offsetof(csm_node_find_job_input_t,midpoint),0,NULL,0x97cb1ba9,4},
{"user_name",offsetof(csm_node_find_job_input_t,user_name),0,NULL,0xc029f5a4,4}}
;

void* cast_csm_node_find_job_input_t(void* ptr,size_t index, char isArray) { 
    csm_node_find_job_input_t ** ptr_cast = *(csm_node_find_job_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_find_job_input_t= {
    21,
    csm_node_find_job_input_tree,
    cast_csm_node_find_job_input_t
};

const csmi_struct_node_t csm_node_find_job_output_tree[2] = {{"results_count",offsetof(csm_node_find_job_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_node_find_job_output_t,results),offsetof(csm_node_find_job_output_t, results_count),&map_csmi_node_find_job_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_node_find_job_output_t(void* ptr,size_t index, char isArray) { 
    csm_node_find_job_output_t ** ptr_cast = *(csm_node_find_job_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_node_find_job_output_t= {
    2,
    csm_node_find_job_output_tree,
    cast_csm_node_find_job_output_t
};

const csmi_struct_node_t csm_switch_attributes_query_input_tree[15] = {{"offset",offsetof(csm_switch_attributes_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_switch_attributes_query_input_t,limit),0,NULL,0xfdcc804,36},
{"switch_names",offsetof(csm_switch_attributes_query_input_t,switch_names),offsetof(csm_switch_attributes_query_input_t, switch_names_count),NULL,0x4d7c5dca,5},
{"switch_names_count",offsetof(csm_switch_attributes_query_input_t,switch_names_count),0,NULL,0x4da7952,24},
{"state",offsetof(csm_switch_attributes_query_input_t,state),0,NULL,0x10614a06,4},
{"order_by",offsetof(csm_switch_attributes_query_input_t,order_by),0,NULL,0x245553bb,68},
{"serial_number",offsetof(csm_switch_attributes_query_input_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"roles",offsetof(csm_switch_attributes_query_input_t,roles),offsetof(csm_switch_attributes_query_input_t, roles_count),NULL,0x104ca08a,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"roles_count",offsetof(csm_switch_attributes_query_input_t,roles_count),0,NULL,0xe301cc12,24}}
;

void* cast_csm_switch_attributes_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_input_t ** ptr_cast = *(csm_switch_attributes_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_input_t= {
    15,
    csm_switch_attributes_query_input_tree,
    cast_csm_switch_attributes_query_input_t
};

const csmi_struct_node_t csm_switch_attributes_query_output_tree[2] = {{"results_count",offsetof(csm_switch_attributes_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_switch_attributes_query_output_t,results),offsetof(csm_switch_attributes_query_output_t, results_count),&map_csmi_switch_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_switch_attributes_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_output_t ** ptr_cast = *(csm_switch_attributes_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_output_t= {
    2,
    csm_switch_attributes_query_output_tree,
    cast_csm_switch_attributes_query_output_t
};

const csmi_struct_node_t csm_switch_attributes_query_details_input_tree[1] = {{"switch_name",offsetof(csm_switch_attributes_query_details_input_t,switch_name),0,NULL,0x482a8e77,4}}
;

void* cast_csm_switch_attributes_query_details_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_details_input_t ** ptr_cast = *(csm_switch_attributes_query_details_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_details_input_t= {
    1,
    csm_switch_attributes_query_details_input_tree,
    cast_csm_switch_attributes_query_details_input_t
};

const csmi_struct_node_t csm_switch_attributes_query_details_output_tree[2] = {{"result_count",offsetof(csm_switch_attributes_query_details_output_t,result_count),0,NULL,0x4236760c,44},
{"result",offsetof(csm_switch_attributes_query_details_output_t,result),offsetof(csm_switch_attributes_query_details_output_t, result_count),&map_csmi_switch_details_t,0x192fd704,1}}
;

void* cast_csm_switch_attributes_query_details_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_details_output_t ** ptr_cast = *(csm_switch_attributes_query_details_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_details_output_t= {
    2,
    csm_switch_attributes_query_details_output_tree,
    cast_csm_switch_attributes_query_details_output_t
};

const csmi_struct_node_t csm_switch_attributes_query_history_input_tree[3] = {{"offset",offsetof(csm_switch_attributes_query_history_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_switch_attributes_query_history_input_t,limit),0,NULL,0xfdcc804,36},
{"switch_name",offsetof(csm_switch_attributes_query_history_input_t,switch_name),0,NULL,0x482a8e77,4}}
;

void* cast_csm_switch_attributes_query_history_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_history_input_t ** ptr_cast = *(csm_switch_attributes_query_history_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_history_input_t= {
    3,
    csm_switch_attributes_query_history_input_tree,
    cast_csm_switch_attributes_query_history_input_t
};

const csmi_struct_node_t csm_switch_attributes_query_history_output_tree[2] = {{"results_count",offsetof(csm_switch_attributes_query_history_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_switch_attributes_query_history_output_t,results),offsetof(csm_switch_attributes_query_history_output_t, results_count),&map_csmi_switch_history_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_switch_attributes_query_history_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_query_history_output_t ** ptr_cast = *(csm_switch_attributes_query_history_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_query_history_output_t= {
    2,
    csm_switch_attributes_query_history_output_tree,
    cast_csm_switch_attributes_query_history_output_t
};

const csmi_struct_node_t csm_switch_attributes_update_input_tree[10] = {{"physical_frame_location",offsetof(csm_switch_attributes_update_input_t,physical_frame_location),0,NULL,0x7762c5a4,4},
{"state",offsetof(csm_switch_attributes_update_input_t,state),0,NULL,0x10614a06,4},
{"comment",offsetof(csm_switch_attributes_update_input_t,comment),0,NULL,0xd363aa58,4},
{"switch_names_count",offsetof(csm_switch_attributes_update_input_t,switch_names_count),0,NULL,0x4da7952,24},
{"physical_u_location",offsetof(csm_switch_attributes_update_input_t,physical_u_location),0,NULL,0x5783af2e,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"switch_names",offsetof(csm_switch_attributes_update_input_t,switch_names),offsetof(csm_switch_attributes_update_input_t, switch_names_count),NULL,0x4d7c5dca,5}}
;

void* cast_csm_switch_attributes_update_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_update_input_t ** ptr_cast = *(csm_switch_attributes_update_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_update_input_t= {
    10,
    csm_switch_attributes_update_input_tree,
    cast_csm_switch_attributes_update_input_t
};

const csmi_struct_node_t csm_switch_attributes_update_output_tree[3] = {{"failure_count",offsetof(csm_switch_attributes_update_output_t,failure_count),0,NULL,0xb64de7b5,24},
{NULL,0,0,NULL,0,0},
{"failure_switches",offsetof(csm_switch_attributes_update_output_t,failure_switches),offsetof(csm_switch_attributes_update_output_t, failure_count),NULL,0xbe921c96,5}}
;

void* cast_csm_switch_attributes_update_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_attributes_update_output_t ** ptr_cast = *(csm_switch_attributes_update_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_attributes_update_output_t= {
    3,
    csm_switch_attributes_update_output_tree,
    cast_csm_switch_attributes_update_output_t
};

const csmi_struct_node_t csm_switch_inventory_collection_input_tree[3] = {{"inventory_count",offsetof(csm_switch_inventory_collection_input_t,inventory_count),0,NULL,0xde0c63b,24},
{NULL,0,0,NULL,0,0},
{"inventory",offsetof(csm_switch_inventory_collection_input_t,inventory),offsetof(csm_switch_inventory_collection_input_t, inventory_count),&map_csmi_switch_details_t,0xac696ff3,1}}
;

void* cast_csm_switch_inventory_collection_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_inventory_collection_input_t ** ptr_cast = *(csm_switch_inventory_collection_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_inventory_collection_input_t= {
    3,
    csm_switch_inventory_collection_input_tree,
    cast_csm_switch_inventory_collection_input_t
};

const csmi_struct_node_t csm_switch_inventory_collection_output_tree[6] = {{"update_count",offsetof(csm_switch_inventory_collection_output_t,update_count),0,NULL,0x191a1ab0,36},
{"TBD",offsetof(csm_switch_inventory_collection_output_t,TBD),0,NULL,0xb8820ff,68},
{"insert_count",offsetof(csm_switch_inventory_collection_output_t,insert_count),0,NULL,0x7bae7a22,36},
{NULL,0,0,NULL,0,0},
{"delete_count",offsetof(csm_switch_inventory_collection_output_t,delete_count),0,NULL,0x103b6a80,36},
{"delete_module_count",offsetof(csm_switch_inventory_collection_output_t,delete_module_count),0,NULL,0x38a37145,36}}
;

void* cast_csm_switch_inventory_collection_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_inventory_collection_output_t ** ptr_cast = *(csm_switch_inventory_collection_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_inventory_collection_output_t= {
    6,
    csm_switch_inventory_collection_output_tree,
    cast_csm_switch_inventory_collection_output_t
};

const csmi_struct_node_t csm_switch_children_inventory_collection_input_tree[3] = {{"inventory_count",offsetof(csm_switch_children_inventory_collection_input_t,inventory_count),0,NULL,0xde0c63b,44},
{NULL,0,0,NULL,0,0},
{"inventory",offsetof(csm_switch_children_inventory_collection_input_t,inventory),offsetof(csm_switch_children_inventory_collection_input_t, inventory_count),&map_csmi_switch_details_t,0xac696ff3,1}}
;

void* cast_csm_switch_children_inventory_collection_input_t(void* ptr,size_t index, char isArray) { 
    csm_switch_children_inventory_collection_input_t ** ptr_cast = *(csm_switch_children_inventory_collection_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_children_inventory_collection_input_t= {
    3,
    csm_switch_children_inventory_collection_input_tree,
    cast_csm_switch_children_inventory_collection_input_t
};

const csmi_struct_node_t csm_switch_children_inventory_collection_output_tree[3] = {{"update_count",offsetof(csm_switch_children_inventory_collection_output_t,update_count),0,NULL,0x191a1ab0,36},
{"delete_count",offsetof(csm_switch_children_inventory_collection_output_t,delete_count),0,NULL,0x103b6a80,36},
{"insert_count",offsetof(csm_switch_children_inventory_collection_output_t,insert_count),0,NULL,0x7bae7a22,36}}
;

void* cast_csm_switch_children_inventory_collection_output_t(void* ptr,size_t index, char isArray) { 
    csm_switch_children_inventory_collection_output_t ** ptr_cast = *(csm_switch_children_inventory_collection_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_switch_children_inventory_collection_output_t= {
    3,
    csm_switch_children_inventory_collection_output_tree,
    cast_csm_switch_children_inventory_collection_output_t
};

const csmi_struct_node_t csm_cluster_query_state_input_tree[7] = {{"offset",offsetof(csm_cluster_query_state_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_cluster_query_state_input_t,limit),0,NULL,0xfdcc804,36},
{"num_allocs",offsetof(csm_cluster_query_state_input_t,num_allocs),0,NULL,0x421fea12,36},
{NULL,0,0,NULL,0,0},
{"state",offsetof(csm_cluster_query_state_input_t,state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x10614a06,8},
{"order_by",offsetof(csm_cluster_query_state_input_t,order_by),0,NULL,0x245553bb,68},
{"type",offsetof(csm_cluster_query_state_input_t,type),csmi_node_type_t_MAX,&csmi_node_type_t_strs,0x7c9ebd07,8}}
;

void* cast_csm_cluster_query_state_input_t(void* ptr,size_t index, char isArray) { 
    csm_cluster_query_state_input_t ** ptr_cast = *(csm_cluster_query_state_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_cluster_query_state_input_t= {
    7,
    csm_cluster_query_state_input_tree,
    cast_csm_cluster_query_state_input_t
};

const csmi_struct_node_t csm_cluster_query_state_output_tree[2] = {{"results_count",offsetof(csm_cluster_query_state_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_cluster_query_state_output_t,results),offsetof(csm_cluster_query_state_output_t, results_count),&map_csmi_cluster_query_state_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_cluster_query_state_output_t(void* ptr,size_t index, char isArray) { 
    csm_cluster_query_state_output_t ** ptr_cast = *(csm_cluster_query_state_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_cluster_query_state_output_t= {
    2,
    csm_cluster_query_state_output_tree,
    cast_csm_cluster_query_state_output_t
};

#include "csmi/src/diag/include/csmi_diag_internal.h"
#include "csmi/src/diag/include/csmi_diag_type_internal.h"
const csmi_struct_node_t csmi_diag_run_tree[10] = {{"cmd_line",offsetof(csmi_diag_run_t,cmd_line),0,NULL,0x8fec7820,4},
{"diag_status",offsetof(csmi_diag_run_t,diag_status),16,NULL,0x8321a7dd,70},
{"allocation_id",offsetof(csmi_diag_run_t,allocation_id),0,NULL,0x99d3da77,40},
{"begin_time",offsetof(csmi_diag_run_t,begin_time),0,NULL,0x5f818b18,4},
{"inserted_ras",offsetof(csmi_diag_run_t,inserted_ras),0,NULL,0x89b6b1e8,16},
{NULL,0,0,NULL,0,0},
{"end_time",offsetof(csmi_diag_run_t,end_time),0,NULL,0xb56ec18a,4},
{"run_id",offsetof(csmi_diag_run_t,run_id),0,NULL,0x1a4e4326,40},
{"history_time",offsetof(csmi_diag_run_t,history_time),0,NULL,0x60dc8265,4},
{"log_dir",offsetof(csmi_diag_run_t,log_dir),0,NULL,0x87bb87e5,4}}
;

void* cast_csmi_diag_run_t(void* ptr,size_t index, char isArray) { 
    csmi_diag_run_t ** ptr_cast = *(csmi_diag_run_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_diag_run_t= {
    10,
    csmi_diag_run_tree,
    cast_csmi_diag_run_t
};

const csmi_struct_node_t csmi_diag_run_query_details_result_tree[12] = {{"node_name",offsetof(csmi_diag_run_query_details_result_t,node_name),0,NULL,0x746e3e2b,4},
{"status",offsetof(csmi_diag_run_query_details_result_t,status),16,NULL,0x1c8a8d49,70},
{"end_time",offsetof(csmi_diag_run_query_details_result_t,end_time),0,NULL,0xb56ec18a,4},
{"run_id",offsetof(csmi_diag_run_query_details_result_t,run_id),0,NULL,0x1a4e4326,40},
{"history_time",offsetof(csmi_diag_run_query_details_result_t,history_time),0,NULL,0x60dc8265,4},
{"test_name",offsetof(csmi_diag_run_query_details_result_t,test_name),0,NULL,0x9a6d8425,4},
{"serial_number",offsetof(csmi_diag_run_query_details_result_t,serial_number),0,NULL,0xd931f68d,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"begin_time",offsetof(csmi_diag_run_query_details_result_t,begin_time),0,NULL,0x5f818b18,4},
{NULL,0,0,NULL,0,0},
{"log_file",offsetof(csmi_diag_run_query_details_result_t,log_file),0,NULL,0x7f2d9ce6,4}}
;

void* cast_csmi_diag_run_query_details_result_t(void* ptr,size_t index, char isArray) { 
    csmi_diag_run_query_details_result_t ** ptr_cast = *(csmi_diag_run_query_details_result_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_diag_run_query_details_result_t= {
    12,
    csmi_diag_run_query_details_result_tree,
    cast_csmi_diag_run_query_details_result_t
};

const csmi_struct_node_t csm_diag_run_end_input_tree[3] = {{"status",offsetof(csm_diag_run_end_input_t,status),16,NULL,0x1c8a8d49,70},
{"run_id",offsetof(csm_diag_run_end_input_t,run_id),0,NULL,0x1a4e4326,40},
{"inserted_ras",offsetof(csm_diag_run_end_input_t,inserted_ras),0,NULL,0x89b6b1e8,16}}
;

void* cast_csm_diag_run_end_input_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_end_input_t ** ptr_cast = *(csm_diag_run_end_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_end_input_t= {
    3,
    csm_diag_run_end_input_tree,
    cast_csm_diag_run_end_input_t
};

const csmi_struct_node_t csm_diag_result_create_input_tree[9] = {{"status",offsetof(csm_diag_result_create_input_t,status),16,NULL,0x1c8a8d49,70},
{"run_id",offsetof(csm_diag_result_create_input_t,run_id),0,NULL,0x1a4e4326,40},
{"test_name",offsetof(csm_diag_result_create_input_t,test_name),0,NULL,0x9a6d8425,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"node_name",offsetof(csm_diag_result_create_input_t,node_name),0,NULL,0x746e3e2b,4},
{"serial_number",offsetof(csm_diag_result_create_input_t,serial_number),0,NULL,0xd931f68d,4},
{"begin_time",offsetof(csm_diag_result_create_input_t,begin_time),0,NULL,0x5f818b18,4},
{"log_file",offsetof(csm_diag_result_create_input_t,log_file),0,NULL,0x7f2d9ce6,4}}
;

void* cast_csm_diag_result_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_diag_result_create_input_t ** ptr_cast = *(csm_diag_result_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_result_create_input_t= {
    9,
    csm_diag_result_create_input_tree,
    cast_csm_diag_result_create_input_t
};

const csmi_struct_node_t csm_diag_run_begin_input_tree[5] = {{"cmd_line",offsetof(csm_diag_run_begin_input_t,cmd_line),0,NULL,0x8fec7820,4},
{"run_id",offsetof(csm_diag_run_begin_input_t,run_id),0,NULL,0x1a4e4326,40},
{"allocation_id",offsetof(csm_diag_run_begin_input_t,allocation_id),0,NULL,0x99d3da77,40},
{NULL,0,0,NULL,0,0},
{"log_dir",offsetof(csm_diag_run_begin_input_t,log_dir),0,NULL,0x87bb87e5,4}}
;

void* cast_csm_diag_run_begin_input_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_begin_input_t ** ptr_cast = *(csm_diag_run_begin_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_begin_input_t= {
    5,
    csm_diag_run_begin_input_tree,
    cast_csm_diag_run_begin_input_t
};

const csmi_struct_node_t csm_diag_run_query_input_tree[22] = {{"allocation_ids_count",offsetof(csm_diag_run_query_input_t,allocation_ids_count),0,NULL,0x49964552,24},
{"offset",offsetof(csm_diag_run_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"inserted_ras",offsetof(csm_diag_run_query_input_t,inserted_ras),0,NULL,0x89b6b1e8,16},
{"limit",offsetof(csm_diag_run_query_input_t,limit),0,NULL,0xfdcc804,36},
{"status",offsetof(csm_diag_run_query_input_t,status),0,NULL,0x1c8a8d49,20},
{"run_ids_count",offsetof(csm_diag_run_query_input_t,run_ids_count),0,NULL,0x7c4c3321,24},
{"begin_time_search_end",offsetof(csm_diag_run_query_input_t,begin_time_search_end),0,NULL,0xc583ac83,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"begin_time_search_begin",offsetof(csm_diag_run_query_input_t,begin_time_search_begin),0,NULL,0x34e5bb11,4},
{"run_ids",offsetof(csm_diag_run_query_input_t,run_ids),offsetof(csm_diag_run_query_input_t, run_ids_count),NULL,0x6416a859,1},
{NULL,0,0,NULL,0,0},
{"end_time_search_end",offsetof(csm_diag_run_query_input_t,end_time_search_end),0,NULL,0x8f62b7b5,4},
{"end_time_search_begin",offsetof(csm_diag_run_query_input_t,end_time_search_begin),0,NULL,0xf2b45ac3,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"allocation_ids",offsetof(csm_diag_run_query_input_t,allocation_ids),offsetof(csm_diag_run_query_input_t, allocation_ids_count),NULL,0xd44f29ca,1}}
;

void* cast_csm_diag_run_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_query_input_t ** ptr_cast = *(csm_diag_run_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_query_input_t= {
    22,
    csm_diag_run_query_input_tree,
    cast_csm_diag_run_query_input_t
};

const csmi_struct_node_t csm_diag_run_query_output_tree[3] = {{"num_runs",offsetof(csm_diag_run_query_output_t,num_runs),0,NULL,0x33946edc,24},
{NULL,0,0,NULL,0,0},
{"runs",offsetof(csm_diag_run_query_output_t,runs),offsetof(csm_diag_run_query_output_t, num_runs),&map_csmi_diag_run_t,0x7c9d930d,1}}
;

void* cast_csm_diag_run_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_query_output_t ** ptr_cast = *(csm_diag_run_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_query_output_t= {
    3,
    csm_diag_run_query_output_tree,
    cast_csm_diag_run_query_output_t
};

const csmi_struct_node_t csm_diag_run_query_details_input_tree[1] = {{"run_id",offsetof(csm_diag_run_query_details_input_t,run_id),0,NULL,0x1a4e4326,40}}
;

void* cast_csm_diag_run_query_details_input_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_query_details_input_t ** ptr_cast = *(csm_diag_run_query_details_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_query_details_input_t= {
    1,
    csm_diag_run_query_details_input_tree,
    cast_csm_diag_run_query_details_input_t
};

const csmi_struct_node_t csm_diag_run_query_details_output_tree[3] = {{"num_details",offsetof(csm_diag_run_query_details_output_t,num_details),0,NULL,0x5d40f5fa,28},
{"details",offsetof(csm_diag_run_query_details_output_t,details),offsetof(csm_diag_run_query_details_output_t, num_details),&map_csmi_diag_run_query_details_result_t,0x982788b,1},
{"run_data",offsetof(csm_diag_run_query_details_output_t,run_data),0,&map_csmi_diag_run_t,0xe6e8e953,0}}
;

void* cast_csm_diag_run_query_details_output_t(void* ptr,size_t index, char isArray) { 
    csm_diag_run_query_details_output_t ** ptr_cast = *(csm_diag_run_query_details_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_diag_run_query_details_output_t= {
    3,
    csm_diag_run_query_details_output_tree,
    cast_csm_diag_run_query_details_output_t
};

#include "csmi/src/ras/include/csmi_ras_internal.h"
#include "csmi/src/ras/include/csmi_ras_type_internal.h"
const csmi_struct_node_t csmi_ras_type_record_tree[15] = {{"threshold_period",offsetof(csmi_ras_type_record_t,threshold_period),0,NULL,0x45484d14,36},
{"msg_id",offsetof(csmi_ras_type_record_t,msg_id),0,NULL,0xe7c7058,4},
{"set_not_ready",offsetof(csmi_ras_type_record_t,set_not_ready),0,NULL,0x97e7daf5,16},
{"threshold_count",offsetof(csmi_ras_type_record_t,threshold_count),0,NULL,0x133c15a,36},
{"set_ready",offsetof(csmi_ras_type_record_t,set_ready),0,NULL,0x4341dbc5,16},
{"enabled",offsetof(csmi_ras_type_record_t,enabled),0,NULL,0x6a23e990,16},
{"visible_to_users",offsetof(csmi_ras_type_record_t,visible_to_users),0,NULL,0xa9800ac6,16},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csmi_ras_type_record_t,severity),csmi_ras_severity_t_MAX,&csmi_ras_severity_t_strs,0x16a499a0,8},
{"set_state",offsetof(csmi_ras_type_record_t,set_state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x435c2ff1,8},
{"control_action",offsetof(csmi_ras_type_record_t,control_action),0,NULL,0x4bd6e603,4},
{"description",offsetof(csmi_ras_type_record_t,description),0,NULL,0x91b0c789,4},
{NULL,0,0,NULL,0,0},
{"message",offsetof(csmi_ras_type_record_t,message),0,NULL,0xbe463eea,4}}
;

void* cast_csmi_ras_type_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ras_type_record_t ** ptr_cast = *(csmi_ras_type_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ras_type_record_t= {
    15,
    csmi_ras_type_record_tree,
    cast_csmi_ras_type_record_t
};

const csmi_struct_node_t csm_ras_event_create_input_tree[7] = {{"location_name",offsetof(csm_ras_event_create_input_t,location_name),0,NULL,0x54e4507e,4},
{"msg_id",offsetof(csm_ras_event_create_input_t,msg_id),0,NULL,0xe7c7058,4},
{"time_stamp",offsetof(csm_ras_event_create_input_t,time_stamp),0,NULL,0xae3ff458,4},
{NULL,0,0,NULL,0,0},
{"kvcsv",offsetof(csm_ras_event_create_input_t,kvcsv),0,NULL,0xfd1a732,4},
{NULL,0,0,NULL,0,0},
{"raw_data",offsetof(csm_ras_event_create_input_t,raw_data),0,NULL,0xf85a97e8,4}}
;

void* cast_csm_ras_event_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_event_create_input_t ** ptr_cast = *(csm_ras_event_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_event_create_input_t= {
    7,
    csm_ras_event_create_input_tree,
    cast_csm_ras_event_create_input_t
};

const csmi_struct_node_t csmi_ras_event_action_record_tree[12] = {{"archive_history_time",offsetof(csmi_ras_event_action_record_t,archive_history_time),0,NULL,0x9e88b9e6,4},
{"rec_id",offsetof(csmi_ras_event_action_record_t,rec_id),0,NULL,0x1926b2eb,40},
{"msg_id_seq",offsetof(csmi_ras_event_action_record_t,msg_id_seq),0,NULL,0xdda2eb00,36},
{"count",offsetof(csmi_ras_event_action_record_t,count),0,NULL,0xf3d586e,36},
{"location_name",offsetof(csmi_ras_event_action_record_t,location_name),0,NULL,0x54e4507e,4},
{"message",offsetof(csmi_ras_event_action_record_t,message),0,NULL,0xbe463eea,4},
{"raw_data",offsetof(csmi_ras_event_action_record_t,raw_data),0,NULL,0xf85a97e8,4},
{"msg_id",offsetof(csmi_ras_event_action_record_t,msg_id),0,NULL,0xe7c7058,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"time_stamp",offsetof(csmi_ras_event_action_record_t,time_stamp),0,NULL,0xae3ff458,4}}
;

void* cast_csmi_ras_event_action_record_t(void* ptr,size_t index, char isArray) { 
    csmi_ras_event_action_record_t ** ptr_cast = *(csmi_ras_event_action_record_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ras_event_action_record_t= {
    12,
    csmi_ras_event_action_record_tree,
    cast_csmi_ras_event_action_record_t
};

const csmi_struct_node_t csmi_ras_event_action_tree[13] = {{"rec_id",offsetof(csmi_ras_event_action_t,rec_id),0,NULL,0x1926b2eb,40},
{"count",offsetof(csmi_ras_event_action_t,count),0,NULL,0xf3d586e,36},
{"time_stamp",offsetof(csmi_ras_event_action_t,time_stamp),0,NULL,0xae3ff458,4},
{"msg_id",offsetof(csmi_ras_event_action_t,msg_id),0,NULL,0xe7c7058,4},
{NULL,0,0,NULL,0,0},
{"location_name",offsetof(csmi_ras_event_action_t,location_name),0,NULL,0x54e4507e,4},
{"msg_id_seq",offsetof(csmi_ras_event_action_t,msg_id_seq),0,NULL,0xdda2eb00,36},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"archive_history_time",offsetof(csmi_ras_event_action_t,archive_history_time),0,NULL,0x9e88b9e6,4},
{"message",offsetof(csmi_ras_event_action_t,message),0,NULL,0xbe463eea,4},
{"raw_data",offsetof(csmi_ras_event_action_t,raw_data),0,NULL,0xf85a97e8,4}}
;

void* cast_csmi_ras_event_action_t(void* ptr,size_t index, char isArray) { 
    csmi_ras_event_action_t ** ptr_cast = *(csmi_ras_event_action_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ras_event_action_t= {
    13,
    csmi_ras_event_action_tree,
    cast_csmi_ras_event_action_t
};

const csmi_struct_node_t csmi_ras_event_tree[22] = {{"processor",offsetof(csmi_ras_event_t,processor),0,NULL,0x6cb287a5,36},
{"count",offsetof(csmi_ras_event_t,count),0,NULL,0xf3d586e,36},
{"suppress_ids",offsetof(csmi_ras_event_t,suppress_ids),0,NULL,0xad086749,4},
{"msg_id",offsetof(csmi_ras_event_t,msg_id),0,NULL,0xe7c7058,4},
{"control_action",offsetof(csmi_ras_event_t,control_action),0,NULL,0x4bd6e603,4},
{"min_time_in_pool",offsetof(csmi_ras_event_t,min_time_in_pool),0,NULL,0xa819bf26,36},
{"message",offsetof(csmi_ras_event_t,message),0,NULL,0xbe463eea,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csmi_ras_event_t,severity),0,NULL,0x16a499a0,4},
{"location_name",offsetof(csmi_ras_event_t,location_name),0,NULL,0x54e4507e,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"time_stamp",offsetof(csmi_ras_event_t,time_stamp),0,NULL,0xae3ff458,4},
{"raw_data",offsetof(csmi_ras_event_t,raw_data),0,NULL,0xf85a97e8,4},
{"kvcsv",offsetof(csmi_ras_event_t,kvcsv),0,NULL,0xfd1a732,4},
{"rec_id",offsetof(csmi_ras_event_t,rec_id),0,NULL,0x1926b2eb,40},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"master_time_stamp",offsetof(csmi_ras_event_t,master_time_stamp),0,NULL,0xe32c0c43,4}}
;

void* cast_csmi_ras_event_t(void* ptr,size_t index, char isArray) { 
    csmi_ras_event_t ** ptr_cast = *(csmi_ras_event_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ras_event_t= {
    22,
    csmi_ras_event_tree,
    cast_csmi_ras_event_t
};

const csmi_struct_node_t csmi_ras_event_vector_tree[3] = {{"num_ras_events",offsetof(csmi_ras_event_vector_t,num_ras_events),0,NULL,0xb3e851ae,24},
{NULL,0,0,NULL,0,0},
{"events",offsetof(csmi_ras_event_vector_t,events),offsetof(csmi_ras_event_vector_t, num_ras_events),&map_csmi_ras_event_t,0xfc089d5a,1}}
;

void* cast_csmi_ras_event_vector_t(void* ptr,size_t index, char isArray) { 
    csmi_ras_event_vector_t ** ptr_cast = *(csmi_ras_event_vector_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csmi_ras_event_vector_t= {
    3,
    csmi_ras_event_vector_tree,
    cast_csmi_ras_event_vector_t
};

const csmi_struct_node_t csm_ras_event_query_input_tree[22] = {{"order_by",offsetof(csm_ras_event_query_input_t,order_by),0,NULL,0x245553bb,68},
{"offset",offsetof(csm_ras_event_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"location_name",offsetof(csm_ras_event_query_input_t,location_name),0,NULL,0x54e4507e,4},
{"limit",offsetof(csm_ras_event_query_input_t,limit),0,NULL,0xfdcc804,36},
{"severity",offsetof(csm_ras_event_query_input_t,severity),csmi_ras_severity_t_MAX,&csmi_ras_severity_t_strs,0x16a499a0,8},
{"master_time_stamp_search_begin",offsetof(csm_ras_event_query_input_t,master_time_stamp_search_begin),0,NULL,0x2da38a1c,4},
{"end_time_stamp",offsetof(csm_ras_event_query_input_t,end_time_stamp),0,NULL,0x9c9c9dce,4},
{"msg_id",offsetof(csm_ras_event_query_input_t,msg_id),0,NULL,0xe7c7058,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"rec_id",offsetof(csm_ras_event_query_input_t,rec_id),0,NULL,0x1926b2eb,40},
{"start_time_stamp",offsetof(csm_ras_event_query_input_t,start_time_stamp),0,NULL,0x25f0f825,4},
{"control_action",offsetof(csm_ras_event_query_input_t,control_action),0,NULL,0x4bd6e603,4},
{NULL,0,0,NULL,0,0},
{"message",offsetof(csm_ras_event_query_input_t,message),0,NULL,0xbe463eea,4},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"master_time_stamp_search_end",offsetof(csm_ras_event_query_input_t,master_time_stamp_search_end),0,NULL,0x45dc3cce,4}}
;

void* cast_csm_ras_event_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_event_query_input_t ** ptr_cast = *(csm_ras_event_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_event_query_input_t= {
    22,
    csm_ras_event_query_input_tree,
    cast_csm_ras_event_query_input_t
};

const csmi_struct_node_t csm_ras_event_query_output_tree[2] = {{"results_count",offsetof(csm_ras_event_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_ras_event_query_output_t,results),offsetof(csm_ras_event_query_output_t, results_count),&map_csmi_ras_event_t,0x3f2ab7f7,1}}
;

void* cast_csm_ras_event_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_event_query_output_t ** ptr_cast = *(csm_ras_event_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_event_query_output_t= {
    2,
    csm_ras_event_query_output_tree,
    cast_csm_ras_event_query_output_t
};

const csmi_struct_node_t csm_ras_event_query_allocation_input_tree[3] = {{"offset",offsetof(csm_ras_event_query_allocation_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_ras_event_query_allocation_input_t,limit),0,NULL,0xfdcc804,36},
{"allocation_id",offsetof(csm_ras_event_query_allocation_input_t,allocation_id),0,NULL,0x99d3da77,40}}
;

void* cast_csm_ras_event_query_allocation_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_event_query_allocation_input_t ** ptr_cast = *(csm_ras_event_query_allocation_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_event_query_allocation_input_t= {
    3,
    csm_ras_event_query_allocation_input_tree,
    cast_csm_ras_event_query_allocation_input_t
};

const csmi_struct_node_t csm_ras_event_query_allocation_output_tree[3] = {{"num_events",offsetof(csm_ras_event_query_allocation_output_t,num_events),0,NULL,0x4c25a8e9,24},
{NULL,0,0,NULL,0,0},
{"events",offsetof(csm_ras_event_query_allocation_output_t,events),offsetof(csm_ras_event_query_allocation_output_t, num_events),&map_csmi_ras_event_action_t,0xfc089d5a,1}}
;

void* cast_csm_ras_event_query_allocation_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_event_query_allocation_output_t ** ptr_cast = *(csm_ras_event_query_allocation_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_event_query_allocation_output_t= {
    3,
    csm_ras_event_query_allocation_output_tree,
    cast_csm_ras_event_query_allocation_output_t
};

const csmi_struct_node_t csm_ras_msg_type_create_input_tree[15] = {{"threshold_period",offsetof(csm_ras_msg_type_create_input_t,threshold_period),0,NULL,0x45484d14,36},
{"msg_id",offsetof(csm_ras_msg_type_create_input_t,msg_id),0,NULL,0xe7c7058,4},
{"set_not_ready",offsetof(csm_ras_msg_type_create_input_t,set_not_ready),0,NULL,0x97e7daf5,16},
{"threshold_count",offsetof(csm_ras_msg_type_create_input_t,threshold_count),0,NULL,0x133c15a,36},
{"set_ready",offsetof(csm_ras_msg_type_create_input_t,set_ready),0,NULL,0x4341dbc5,16},
{"enabled",offsetof(csm_ras_msg_type_create_input_t,enabled),0,NULL,0x6a23e990,16},
{"visible_to_users",offsetof(csm_ras_msg_type_create_input_t,visible_to_users),0,NULL,0xa9800ac6,16},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csm_ras_msg_type_create_input_t,severity),csmi_ras_severity_t_MAX,&csmi_ras_severity_t_strs,0x16a499a0,8},
{"set_state",offsetof(csm_ras_msg_type_create_input_t,set_state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x435c2ff1,8},
{"control_action",offsetof(csm_ras_msg_type_create_input_t,control_action),0,NULL,0x4bd6e603,4},
{"description",offsetof(csm_ras_msg_type_create_input_t,description),0,NULL,0x91b0c789,4},
{NULL,0,0,NULL,0,0},
{"message",offsetof(csm_ras_msg_type_create_input_t,message),0,NULL,0xbe463eea,4}}
;

void* cast_csm_ras_msg_type_create_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_create_input_t ** ptr_cast = *(csm_ras_msg_type_create_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_create_input_t= {
    15,
    csm_ras_msg_type_create_input_tree,
    cast_csm_ras_msg_type_create_input_t
};

const csmi_struct_node_t csm_ras_msg_type_create_output_tree[2] = {{"insert_successful",offsetof(csm_ras_msg_type_create_output_t,insert_successful),0,NULL,0xd2b0b4d9,16},
{"msg_id",offsetof(csm_ras_msg_type_create_output_t,msg_id),0,NULL,0xe7c7058,4}}
;

void* cast_csm_ras_msg_type_create_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_create_output_t ** ptr_cast = *(csm_ras_msg_type_create_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_create_output_t= {
    2,
    csm_ras_msg_type_create_output_tree,
    cast_csm_ras_msg_type_create_output_t
};

const csmi_struct_node_t csm_ras_msg_type_delete_input_tree[2] = {{"msg_ids_count",offsetof(csm_ras_msg_type_delete_input_t,msg_ids_count),0,NULL,0xe8015413,24},
{"msg_ids",offsetof(csm_ras_msg_type_delete_input_t,msg_ids),offsetof(csm_ras_msg_type_delete_input_t, msg_ids_count),NULL,0xde0a7bcb,5}}
;

void* cast_csm_ras_msg_type_delete_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_delete_input_t ** ptr_cast = *(csm_ras_msg_type_delete_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_delete_input_t= {
    2,
    csm_ras_msg_type_delete_input_tree,
    cast_csm_ras_msg_type_delete_input_t
};

const csmi_struct_node_t csm_ras_msg_type_delete_output_tree[5] = {{"deleted_msg_ids_count",offsetof(csm_ras_msg_type_delete_output_t,deleted_msg_ids_count),0,NULL,0xba570689,24},
{"not_deleted_msg_ids",offsetof(csm_ras_msg_type_delete_output_t,not_deleted_msg_ids),offsetof(csm_ras_msg_type_delete_output_t, not_deleted_msg_ids_count),NULL,0x8151eb71,5},
{"expected_number_of_deleted_msg_ids",offsetof(csm_ras_msg_type_delete_output_t,expected_number_of_deleted_msg_ids),0,NULL,0xc00f38ce,24},
{"not_deleted_msg_ids_count",offsetof(csm_ras_msg_type_delete_output_t,not_deleted_msg_ids_count),0,NULL,0xf236839,24},
{"deleted_msg_ids",offsetof(csm_ras_msg_type_delete_output_t,deleted_msg_ids),offsetof(csm_ras_msg_type_delete_output_t, deleted_msg_ids_count),NULL,0x9b010dc1,5}}
;

void* cast_csm_ras_msg_type_delete_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_delete_output_t ** ptr_cast = *(csm_ras_msg_type_delete_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_delete_output_t= {
    5,
    csm_ras_msg_type_delete_output_tree,
    cast_csm_ras_msg_type_delete_output_t
};

const csmi_struct_node_t csm_ras_msg_type_update_input_tree[15] = {{"threshold_period",offsetof(csm_ras_msg_type_update_input_t,threshold_period),0,NULL,0x45484d14,36},
{"msg_id",offsetof(csm_ras_msg_type_update_input_t,msg_id),0,NULL,0xe7c7058,4},
{"set_not_ready",offsetof(csm_ras_msg_type_update_input_t,set_not_ready),0,NULL,0x97e7daf5,16},
{"threshold_count",offsetof(csm_ras_msg_type_update_input_t,threshold_count),0,NULL,0x133c15a,36},
{"set_ready",offsetof(csm_ras_msg_type_update_input_t,set_ready),0,NULL,0x4341dbc5,16},
{"enabled",offsetof(csm_ras_msg_type_update_input_t,enabled),0,NULL,0x6a23e990,16},
{"visible_to_users",offsetof(csm_ras_msg_type_update_input_t,visible_to_users),0,NULL,0xa9800ac6,16},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csm_ras_msg_type_update_input_t,severity),csmi_ras_severity_t_MAX,&csmi_ras_severity_t_strs,0x16a499a0,8},
{"set_state",offsetof(csm_ras_msg_type_update_input_t,set_state),csmi_node_state_t_MAX,&csmi_node_state_t_strs,0x435c2ff1,8},
{"control_action",offsetof(csm_ras_msg_type_update_input_t,control_action),0,NULL,0x4bd6e603,4},
{"description",offsetof(csm_ras_msg_type_update_input_t,description),0,NULL,0x91b0c789,4},
{NULL,0,0,NULL,0,0},
{"message",offsetof(csm_ras_msg_type_update_input_t,message),0,NULL,0xbe463eea,4}}
;

void* cast_csm_ras_msg_type_update_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_update_input_t ** ptr_cast = *(csm_ras_msg_type_update_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_update_input_t= {
    15,
    csm_ras_msg_type_update_input_tree,
    cast_csm_ras_msg_type_update_input_t
};

const csmi_struct_node_t csm_ras_msg_type_update_output_tree[2] = {{"update_successful",offsetof(csm_ras_msg_type_update_output_t,update_successful),0,NULL,0xf9cde27,16},
{"msg_id",offsetof(csm_ras_msg_type_update_output_t,msg_id),0,NULL,0xe7c7058,4}}
;

void* cast_csm_ras_msg_type_update_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_update_output_t ** ptr_cast = *(csm_ras_msg_type_update_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_update_output_t= {
    2,
    csm_ras_msg_type_update_output_tree,
    cast_csm_ras_msg_type_update_output_t
};

const csmi_struct_node_t csm_ras_msg_type_query_input_tree[13] = {{"offset",offsetof(csm_ras_msg_type_query_input_t,offset),0,NULL,0x123b4b4c,36},
{"limit",offsetof(csm_ras_msg_type_query_input_t,limit),0,NULL,0xfdcc804,36},
{"control_action",offsetof(csm_ras_msg_type_query_input_t,control_action),0,NULL,0x4bd6e603,4},
{"msg_id",offsetof(csm_ras_msg_type_query_input_t,msg_id),0,NULL,0xe7c7058,4},
{NULL,0,0,NULL,0,0},
{"severity",offsetof(csm_ras_msg_type_query_input_t,severity),csmi_ras_severity_t_MAX,&csmi_ras_severity_t_strs,0x16a499a0,8},
{"set_states",offsetof(csm_ras_msg_type_query_input_t,set_states),offsetof(csm_ras_msg_type_query_input_t, set_states_count),NULL,0xaee22e84,5},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{NULL,0,0,NULL,0,0},
{"set_states_count",offsetof(csm_ras_msg_type_query_input_t,set_states_count),0,NULL,0x5d2c6d8c,24},
{"message",offsetof(csm_ras_msg_type_query_input_t,message),0,NULL,0xbe463eea,4}}
;

void* cast_csm_ras_msg_type_query_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_query_input_t ** ptr_cast = *(csm_ras_msg_type_query_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_query_input_t= {
    13,
    csm_ras_msg_type_query_input_tree,
    cast_csm_ras_msg_type_query_input_t
};

const csmi_struct_node_t csm_ras_msg_type_query_output_tree[2] = {{"results_count",offsetof(csm_ras_msg_type_query_output_t,results_count),0,NULL,0x8261013f,24},
{"results",offsetof(csm_ras_msg_type_query_output_t,results),offsetof(csm_ras_msg_type_query_output_t, results_count),&map_csmi_ras_type_record_t,0x3f2ab7f7,1}}
;

void* cast_csm_ras_msg_type_query_output_t(void* ptr,size_t index, char isArray) { 
    csm_ras_msg_type_query_output_t ** ptr_cast = *(csm_ras_msg_type_query_output_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_msg_type_query_output_t= {
    2,
    csm_ras_msg_type_query_output_tree,
    cast_csm_ras_msg_type_query_output_t
};

const csmi_struct_node_t csm_ras_subscribe_input_tree[1] = {{"topic",offsetof(csm_ras_subscribe_input_t,topic),0,NULL,0x1070e304,4}}
;

void* cast_csm_ras_subscribe_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_subscribe_input_t ** ptr_cast = *(csm_ras_subscribe_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_subscribe_input_t= {
    1,
    csm_ras_subscribe_input_tree,
    cast_csm_ras_subscribe_input_t
};

const csmi_struct_node_t csm_ras_unsubscribe_input_tree[1] = {{"topic",offsetof(csm_ras_unsubscribe_input_t,topic),0,NULL,0x1070e304,4}}
;

void* cast_csm_ras_unsubscribe_input_t(void* ptr,size_t index, char isArray) { 
    csm_ras_unsubscribe_input_t ** ptr_cast = *(csm_ras_unsubscribe_input_t***)ptr;
    return ptr_cast && isArray ? ptr_cast[index] : (void*)ptr_cast;
};
const csmi_struct_mapping_t map_csm_ras_unsubscribe_input_t= {
    1,
    csm_ras_unsubscribe_input_tree,
    cast_csm_ras_unsubscribe_input_t
};

const int csm_min_printable_type = 5;
const int csm_type_formatter_len = 20;
