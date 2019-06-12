#!/bin/bash
#--------------------------------------------------------------------------------
#   
#    csm_db_stats.sh
# 
#  © Copyright IBM Corporation 2015-2019. All Rights Reserved
#
#    This program is licensed under the terms of the Eclipse Public License
#    v1.0 as published by the Eclipse Foundation and available at
#    http://www.eclipse.org/legal/epl-v10.html
#
#    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
#    restricted by GSA ADP Schedule Contract with IBM Corp.
# 
#--------------------------------------------------------------------------------

#--------------------------------------------------------------------------------
#   usage:              ./csm_db_stats.sh
#   current_version:    01.12
#   create:             08-02-2016
#   last modified:      04-04-2019
#--------------------------------------------------------------------------------

export PGOPTIONS='--client-min-messages=warning'

OPTERR=0
logpath="/var/log/ibm/csm/db"
logname="csm_db_stats.log"
cd "${BASH_SOURCE%/*}" || exit
cur_path=`pwd`

#----------------------------------------------
# Output formatter
#----------------------------------------------
line1_out=$(printf "%0.s-" {1..120})
line2_log=$(printf "%0.s-" {1..84})
line3_log=$(printf "%0.s-" {1..123})

#----------------------------------------------
# Current user connected---
#----------------------------------------------
current_user=`id -u -n`
db_username="postgres"
now1=$(date '+%Y-%m-%d %H:%M:%S')

BASENAME=`basename "$0"`

#----------------------------------------------
# Log Message---
#----------------------------------------------------------------------------
# This checks the existence of the default log directory.
# If the default doesn't exist it will write the log filesto /tmp directory
# The current version will only display results to the screen
#----------------------------------------------------------------------------

#----------------------------------------------
# This checks the existence of the default
# log directory.  If the default doesn't exist
# it will write the log files to /tmp directory
#----------------------------------------------

if [ -w "$logpath" ]; then
    logdir="$logpath"
else
    logdir="/tmp"
fi
logfile="${logdir}/${logname}"

#----------------------------------------------
# Log Message function
#----------------------------------------------

function LogMsg () {
now=$(date '+%Y-%m-%d %H:%M:%S')
echo "$now ($current_user) $1" >> $logfile
}

#----------------------------------------------
# Log messaging intro. header
#----------------------------------------------
echo "${line1_out}"
echo "[Start ] Welcome to CSM datatbase automation stats script."
#echo "${line3_log}" >> $logfile
LogMsg "[Start ] Welcome to CSM datatbase automation stats script."
echo "${line1_out}"
LogMsg "${line2_log}"
echo "[Info  ] Log Dir: $logdir/$logname"

#----------------------------------------------
# Usage Command Line Functions
#----------------------------------------------

function usage () {
echo "------------------------------------------------------------------------------------------------------------------------"
echo "[Info ] $BASENAME : List/Kill database user sessions"
echo "[Usage] $BASENAME : [OPTION]... [DBNAME]"
echo "------------------------------------------------------------------------------------------------------------------------"
echo "  Argument               |  DB Name  | Description"
echo "-------------------------|-----------|----------------------------------------------------------------------------------"
echo " -t, --tableinfo         | [db_name] | Populates Database Table Stats:"
echo "                         |           | Live Row Count, Inserts, Updates, Deletes, and Table Size"
echo " -i, --indexinfo         | [db_name] | Populates Database Index Stats:"
echo "                         |           | tablename, indexname, num_rows, tbl_size, ix_size, uk,"
echo "                         |           | num_scans, tpls_read, tpls_fetched"
echo " -x, --indexanalysis     | [db_name] | Displays the index usage analysis"
echo " -l, --lockinfo          | [db_name] | Displays any locks that might be happening within the DB"
echo " -s, --schemaversion     | [db_name] | Displays the current CSM DB version"
echo " -c, --connectionsdb     | [db_name] | Displays the current DB connections"
echo " -u, --usernamedb        | [db_name] | Displays the current DB user names and privileges"
echo " -v, --postgresqlversion | [db_name] | Displays the current version of PostgreSQL installed"
echo "                         |           | along with environment details"
echo " -a, --archivecount      | [db_name] | Displays the archived and non archive record counts"
echo " -d, --deletecount       | [db_name] | Displays the total record count based on time interval"
echo " -k, --vacuumstats       | [db_name] | Displays the DB vacuum statistics"
echo " -h, --help              |           | help"
echo "-------------------------|-----------|----------------------------------------------------------------------------------"
echo "[Examples]"
echo "------------------------------------------------------------------------------------------------------------------------"
echo "   $BASENAME -t, --tableinfo         | [dbname] |        | Database table stats"
echo "   $BASENAME -i, --indexinfo         | [dbname] |        | Database index stats"
echo "   $BASENAME -x, --indexanalysisinfo | [dbname] |        | Database index usage analysis stats"
echo "   $BASENAME -l, --lockinfo          | [dbname] |        | Database lock stats"
echo "   $BASENAME -s, --schemaversion     | [dbname] |        | Database schema version (CSM_DB only)"
echo "   $BASENAME -c, --connectionsdb     | [dbname] |        | Database connections stats"
echo "   $BASENAME -u, --usernamedb        | [dbname] |        | Database user stats"
echo "   $BASENAME -v, --postgresqlversion | [dbname] |        | Database (PostgreSQL) version"
echo "   $BASENAME -a, --archivecount      | [dbname] |        | Database archive stats"
echo "   $BASENAME -d, --deletecount       | [dbname] | [time] | Database delete count stats"
echo "   $BASENAME -k, --vacuumstats       | [dbname] |        | Database vacuum stats"
echo "   $BASENAME -h, --help              | [dbname] |        | Help menu"
echo "------------------------------------------------------------------------------------------------------------------------"
}

#----------------------------------------------
#---Default flags---
#----------------------------------------------

createdbstats="no"
createixstats="no"
createlstats="no"
schemaversion="no"
connectionsdb="no"
usernamedb="no"
postgresqlversion="no"
archivecount="no"
indexanalysis="no"
deletecount="no"
vacuumstats="no"

#----------------------------------------------
# long options to short along with fixed length
#----------------------------------------------

reset=true
for arg in "$@"
do
    if [ -n "$reset" ]; then
      unset reset
      set --      # this resets the "$@" array
    fi
    case "$arg" in
        --tableinfo)                            set -- "$@" -t ;;
        -tableinfo)                             usage && exit 0 ;;
        --indexinfo)                            set -- "$@" -i ;;
        -indexinfo)                             usage && exit 0 ;;
        --lockinfo)                             set -- "$@" -l ;;
        -lockinfo)                              usage && exit 0 ;;
        --schemaversion)                        set -- "$@" -s ;;
        -schemaversion)                         usage && exit 0 ;;
        --connectionsdb)                        set -- "$@" -c ;;
        -connectionsdb)                         usage && exit 0 ;;
        --usernamedb)                           set -- "$@" -c ;;
        -usernamedb)                            usage && exit 0 ;;
        --postgresqlversion)                    set -- "$@" -v ;;
        -postgresqlversion)                     usage && exit 0 ;;
        --archivecount)                         set -- "$@" -a ;;
        -archivecount)                          usage && exit 0 ;;
        --indexanalysis)                        set -- "$@" -x ;;
        -indexanalysis)                         usage && exit 0 ;;
        --deletecount)                          set -- "$@" -d ;;
        -deletecount)                           usage && exit 0 ;;
        --help)                                 set -- "$@" -h ;;
        -help)                                  usage && exit 0 ;;
        -t|-i|-l|-s|-c|-u|-v|-a|-x|-d|-k|-h)    set -- "$@" "$arg" ;;
        #-*)                                    usage && exit 0 ;;
        -*)                                     usage
                                                LogMsg "[Info  ] Script execution: $BASENAME [NO ARGUMENT]"
                                                LogMsg "[Info  ] Wrong arguments were passed in (Please choose appropriate option from usage list -h, --help)"
                                                LogMsg "[End   ] Please choose another option"
                                                echo "${line3_log}" >> $logfile
                                                exit 0 ;;
       # pass through anything else
       *)                                       set -- "$@" "$arg" ;;
    esac
done

#----------------------------------------------
# now we can drop into the short getopts
#----------------------------------------------
# Also checks the existence of the user and pid
# If neither of these are available then an
# error message will prompt and will be logged.
#----------------------------------------------

while getopts "t:i:l:s:c:u:v:a:x:d:k:h:" arg; do
    case ${arg} in
        t)
            #----------------------------------------------------------------------------
            # Populate Stats on the DB
            # (Live row count, Insert, Update, Delete)
            # probably want to set populate below during conflict checks
            #----------------------------------------------------------------------------
            createdbstats="yes"
            dbname=$OPTARG
            ;;
        i)  
            #----------------------------------------------------------------------------
            # Populate Stats on the DB (tablename|indexname|num_rows
            # |tbl_size| ix_size|uk|num_scans|tpls_read|tpls_fetched)
            #----------------------------------------------------------------------------
            createixstats="yes"
            dbname=$OPTARG
            ;;
        l)  
            #----------------------------------------------------------------------------
            # Display DB Lock ( blocked_pid | blocked_user | blocking_pid |
            # blocking_user | blocked_statement | current_statement_in_blocking_process |
            # blocked_application | blocking_application)
            #----------------------------------------------------------------------------
            createlstats="yes"
            dbname=$OPTARG
            ;;
        s)  
            #----------------------------------------------------------------------------
            # Display CSM DB Schema Version currently running
            #----------------------------------------------------------------------------
            schemaversion="yes"
            dbname=$OPTARG
            ;;
        c)
            #----------------------------------------------------------------------------
            # Display current postgresql DB connections
            #----------------------------------------------------------------------------
            connectionsdb="yes"
            dbname=$OPTARG
            ;;
        u)
            #----------------------------------------------------------------------------
            # Display current postgresql DB usernames and privileges
            #----------------------------------------------------------------------------
            usernamedb="yes"
            dbname=$OPTARG
            ;;
        v)
            #----------------------------------------------------------------------------
            # Display current postgresql version installed
            #----------------------------------------------------------------------------
            postgresqlversion="yes"
            dbname=$OPTARG
            ;;
        a)
            #----------------------------------------------------------------------------
            # Display current postgresql DB archive record counts
            #----------------------------------------------------------------------------
            archivecount="yes"
            dbname=$OPTARG
            ;;
        x)
            #----------------------------------------------------------------------------
            # Display current postgresql DB index analysis
            #----------------------------------------------------------------------------
            indexanalysis="yes"
            dbname=$OPTARG
            ;;
        d)
            #----------------------------------------------------------------------------
            # Display current postgresql DB index analysis
            #----------------------------------------------------------------------------
            deletecount="yes"
            dbname=$OPTARG
            if [[ -z "$3" ]]; then
                echo "${line1_out}"
                echo "[Error ] Please specify the time interval"
                echo "[Info  ] Example: ./csm_db_stats.sh -d csmdb 1 [min(s)]"
                LogMsg "[Error ] Please specify the time interval"
                LogMsg "[Info  ] Example: ./csm_db_stats.sh -d csmdb 1 [min(s)]"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line1_out}"
                echo "${line3_log}" >> $logfile
                exit 0
            fi
            #htn=$3
            time=$3
            ;;
        k)
            #----------------------------------------------------------------------------
            # Display current postgresql DB index analysis
            #----------------------------------------------------------------------------
            vacuumstats="yes"
            dbname=$OPTARG
            ;;
        #h|*)
        h)
            usage
            LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -h, --help"
            LogMsg "[Info  ] Help menu query executed"
            LogMsg "${line2_log}"
            LogMsg "[End   ] Exiting csm_db_stats.sh script."
            echo "${line3_log}" >> $logfile
            exit 0
            ;;
        *)
            usage
            LogMsg "[Info  ] Script execution: $BASENAME [NO ARGUMENT]"
            LogMsg "[Info  ] Wrong arguments were passed in (Please choose appropriate option from usage list -h, --help)"
            LogMsg "[Info  ] Please choose another option"
            LogMsg "${line2_log}"
            LogMsg "[End   ] Exiting csm_db_stats.sh script."
            echo "${line3_log}" >> $logfile
            exit 0
            ;;
    esac
done

#----------------------------------------------------------------
# Check the status of the PostgreSQl server
#----------------------------------------------------------------

systemctl status postgresql > /dev/null

if [ $? -ne 0 ]; then
    echo "[Error ] The PostgreSQL server: Is currently inactive and needs to be started"
    echo "[Info  ] If there is an issue please run: systemctl status postgresql for more info."
    LogMsg "[Error ] The PostgreSQL server: Is currently inactive and needs to be started"
    LogMsg "[Info  ] If there is an issue please run: systemctl status postgresql for more info."
    LogMsg "${line2_log}"
    LogMsg "[End   ] Exiting csm_db_stats.sh script"
    echo "${line1_out}"
    echo "${line3_log}" >> $logfile
    exit 0
fi

#-------------------------------------------------
# Check if postgresql exists already and root user
#-------------------------------------------------
    root_query=`psql -qtA $db_username -c "SELECT usename FROM pg_catalog.pg_user where usename = 'root';" 2>&1`
        if [ $? -ne 0 ]; then
            echo "[Error ] $root_query"    
            echo "$root_query" |& awk '/^psql:.*$/{$1=""; gsub(/^[ \t]+|[ \t]+$/,""); print "'"$(date '+%Y-%m-%d %H:%M:%S') ($current_user) [Error ] DB Message: "'"$0}' >>"${logfile}"
            echo "[Info  ] Postgresql may not be configured correctly. Please check configuration settings."
            LogMsg "[Info  ] Postgresql may not be configured correctly. Please check configuration settings."
            LogMsg "${line2_log}"
            LogMsg "[End   ] Exiting csm_db_stats.sh script"
            echo "${line1_out}"
            echo "${line3_log}" >> $logfile
            exit 0
        fi

#-------------------------------------------------
# Check if postgresql exists already and DB name
#-------------------------------------------------
string2="$now1 ($current_user) [Info  ] DB Names:"
    psql -lqt | cut -d \| -f 1 | grep -qw $dbname 2>>/dev/null
        if [ $? -eq 0 ]; then       #<------------This is the error return code
            db_query=`psql -U $db_username -q -A -t -P format=wrapped <<EOF
            \set ON_ERROR_STOP true
            select string_agg(datname,' | ') from pg_database;
EOF`
            echo "$string2 $db_query" | sed "s/.\{60\}|/&\n$string2 /g" >> $logfile
            LogMsg "[Info  ] PostgreSQL is installed"
            LogMsg "${line2_log}"
        else
            echo "${line1_out}"
            echo "[Error ] PostgreSQL may not be installed or DB: $dbname may not exist."
            echo "[Info  ] Please check configuration settings or psql -l"
            echo "${line1_out}"
            LogMsg "[Error ] PostgreSQL may not be installed or DB $dbname may not exist."
            LogMsg "[Info  ] Please check configuration settings or psql -l"
            LogMsg "${line2_log}"
            LogMsg "[End   ] Exiting csm_db_stats.sh script."
            echo "${line3_log}" >> $logfile
            exit 1
        fi

#-------------------------------------------------
# Checks to see if no arguments are passed in
#-------------------------------------------------

if [ $# -eq 0 ]; then
    usage
    LogMsg "[Info  ] Script execution: $BASENAME [NO ARGUMENT]"
    LogMsg "[Info  ] Wrong arguments were passed in (Please choose appropriate option from usage list -h, --help)"
    LogMsg "[Info  ] Please choose another option"
    LogMsg "${line2_log}"
    LogMsg "[End   ] Exiting csm_db_stats.sh script."
    echo "${line3_log}" >> $logfile
    exit 0
fi

#-------------------------------------------------
# Create Table stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $createdbstats == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "SELECT
            relname,
            n_live_tup As live_row_count,
            cast(n_tup_ins AS numeric)
        AS 
            insert_count,
            cast(n_tup_upd AS numeric)
        AS
            update_count,
            cast(n_tup_del AS numeric)
        AS 
            delete_count,
            n_dead_tup 
        AS  dead_tuples,
            pg_size_pretty(pg_relation_size(quote_ident(relname)::text)) AS table_size
        FROM
            pg_stat_user_tables 
        WHERE
            (n_tup_ins + n_tup_upd + n_tup_del) > 0
        ORDER BY
        relname;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -t, --tableinfo (db_name): $dbname"
        LogMsg "[Info  ] Table stats query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# CSM_DB_Index_Information
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $createixstats == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "SELECT
            t.tablename,
            indexname,
            c.reltuples::integer AS num_rows,
            pg_size_pretty(pg_relation_size(quote_ident(t.tablename)::text)) AS table_size,
            pg_size_pretty(pg_relation_size(quote_ident(indexrelname)::text)) AS index_size,
            CASE WHEN x.is_unique = 1  THEN 'Y'
               ELSE 'N'
            END AS UNIQUE,
            idx_scan AS number_of_scans,
            idx_tup_read AS tuples_read,
            idx_tup_fetch AS tuples_fetched
        FROM pg_tables t
        LEFT OUTER JOIN pg_class c ON t.tablename=c.relname
        LEFT OUTER JOIN
               (SELECT indrelid,
                   max(CAST(indisunique AS integer)) AS is_unique
               FROM pg_index
               GROUP BY indrelid) x
               ON c.oid = x.indrelid
        LEFT OUTER JOIN
            ( SELECT c.relname AS ctablename, ipg.relname AS indexname, x.indnatts AS number_of_columns, idx_scan, idx_tup_read, idx_tup_fetch,indexrelname FROM pg_index x
                   JOIN pg_class c ON c.oid = x.indrelid
                   JOIN pg_class ipg ON ipg.oid = x.indexrelid
                   JOIN pg_stat_all_indexes psai ON x.indexrelid = psai.indexrelid )
            AS tbixsize
            ON t.tablename = tbixsize.ctablename
        WHERE t.schemaname='public'
            AND
                (c.reltuples + idx_scan + idx_tup_read + idx_tup_fetch) > 0
        ORDER BY pg_relation_size(quote_ident(indexrelname)::text) desc;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -i, --indexinfo (db_name): $dbname"
        LogMsg "[Info  ] Table index query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# CSM_DB_Index_Analysis
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $indexanalysis == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "SELECT
               relname,
               seq_scan - idx_scan AS too_much_seq,
               CASE
                   WHEN seq_scan - idx_scan > 0 THEN 'Missing Index?'
                   ELSE 'OK'
               END,
               Pg_relation_size(relid :: regclass) AS rel_size,
               seq_scan,
               idx_scan
        FROM pg_stat_all_tables
        WHERE schemaname = 'public'
          AND Pg_relation_size(relid :: regclass) > 0
        ORDER BY too_much_seq DESC;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -x, --indexanalysis (db_name): $dbname"
        LogMsg "[Info  ] Table index analysis query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# Lock Monitoring
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $createlstats == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -x -d $dbname -P format=wrapped -c "SELECT
            bl.pid AS blocked_pid,
            a.usename AS blocked_user,
            ka.query AS current_or_recent_statement_in_blocking_process,
            ka.state AS state_of_blocking_process,
            now() - ka.query_start AS blocking_duration,
            kl.pid AS blocking_pid,
            ka.usename AS blocking_user,
            a.query AS blocked_statement,
            now() - a.query_start AS blocked_duration
        FROM pg_catalog.pg_locks bl
        JOIN pg_catalog.pg_stat_activity a ON a.pid = bl.pid
        JOIN pg_catalog.pg_locks kl ON kl.transactionid = bl.transactionid AND kl.pid != bl.pid
        JOIN pg_catalog.pg_stat_activity ka ON ka.pid = kl.pid
        WHERE NOT bl.GRANTED;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -l, --lockinfo (db_name): $dbname"
        LogMsg "[Info  ] Table lock monitoring query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# DB connections stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $connectionsdb == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username $dbname -P format=wrapped -c "
        SELECT pid, datname AS dbname, usename, backend_start, query_start, state_change, waiting AS wait, query FROM pg_stat_activity;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -c, --connectionsdb (db_name): $dbname"
        LogMsg "[Info  ] DB connections with stats query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# DB usernames stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $usernamedb == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username $dbname -P format=wrapped -c "SELECT * from pg_roles;" 2>>/dev/null 
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -u, --username (db_name): $dbname"
        LogMsg "[Info  ] DB usernames with stats query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# Schema Version stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $schemaversion == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "select * from csm_db_schema_version" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system"
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -s, --schemaversion (db_name): $dbname"
        LogMsg "[Info  ] DB schema version query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# DB history archiving stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $archivecount == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "WITH cte AS (
            SELECT
               table_name,
               (xpath('/row/cnt/text()', not_archived))[1]::text::int as not_archived,
               (xpath('/row/cnt/text()', archived))[1]::text::int as archived,
               (xpath('/row/cnt/text()', last_archive_time))[1]::text::timestamp as last_archive_time
        from (
          select table_name,
                query_to_xml(format('select count(*) as cnt from %I.%I where archive_history_time is NULL', table_schema, table_name), false, true, '') as not_archived,
                query_to_xml(format('select count(*) as cnt from %I.%I where archive_history_time is NOT NULL', table_schema, table_name), false, true, '') as archived,
                query_to_xml(format('select MAX(archive_history_time) as cnt from %I.%I where archive_history_time is NOT NULL', table_schema, table_name), false, true, '') as last_archive_time
          from information_schema.columns
          WHERE column_name = 'archive_history_time'
        ) t)
        SELECT table_name, sum(archived + not_archived) as total, sum(archived) as archived, sum(not_archived) not_archived, last_archive_time from cte
        group by table_name, last_archive_time
        ORDER BY table_name ASC;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -a, --archivecount (db_name): $dbname"
        LogMsg "[Info  ] History table archive count query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# PostgreSQL Version stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $postgresqlversion == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username -d $dbname -P format=wrapped -c "SELECT version()" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] A valid database name has to be specified (Please run psql -l for a list of active databases)"
                LogMsg "[Error ] A valid database name has to be specified (Please run psql -l for a list of active databases)" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -v, --postgresqlversion (db_name): $dbname"
        LogMsg "[Info  ] PostgeSQL version and environment query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# CSM DB archive history record count
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------

#---------------------------------------------
# A list of history tables for processing.
#---------------------------------------------

TABLES=(
    csm_allocation_history csm_allocation_node_history csm_allocation_state_history \
    csm_config_history csm_db_schema_version_history csm_diag_result_history \
    csm_diag_run_history csm_dimm_history csm_gpu_history csm_hca_history \
    csm_ib_cable_history csm_lv_history csm_lv_update_history csm_node_history \
    csm_node_state_history csm_processor_socket_history csm_ssd_history \
    csm_ssd_wear_history csm_step_history csm_step_node_history csm_switch_history \
    csm_switch_inventory_history csm_vg_history csm_vg_ssd_history)

#---------------------------------------------
# The list of RAS tables.
#---------------------------------------------

RAS_TABLES=(csm_ras_event_action)

return_code=0

    if [ $deletecount == "yes" ]; then
	    echo "${line1_out}"
	    printf '%-1s %-32s %-16s %-18s\n'"" "[Info  ] " " Table Name: " " | Time interval: " "   | Total Records: "
        echo "${line1_out}"

    #-------------------------------------------
    # Looping through each of the history tables
    #-------------------------------------------

    for table in "${TABLES[@]}"
    do
        delete_query_1=$(psql -q -t -U $db_username -d $dbname -P format=wrapped -c "SELECT count(history_time) \
		FROM ${table} WHERE history_time < (NOW() - INTERVAL '$time MIN') \
		AND archive_history_time IS NOT NULL" 2>>/dev/null)
    	printf '%0s %-32s %-20s %-18s\n'"" "[Info  ] " " ${table}" " | $time (mins)" " | $delete_query_1"
    done

    #---------------------------------------
    # Looping through each of the RAS tables
    #---------------------------------------

    for table in "${RAS_TABLES[@]}"
    do
        delete_query_2=$(psql -q -t -U $db_username -d $dbname -P format=wrapped -c "SELECT count(master_time_stamp) \
		FROM ${table} WHERE master_time_stamp < (NOW() - INTERVAL '$time MIN') \
		AND archive_history_time IS NOT NULL" 2>>/dev/null)
    	printf '%-1s %-32s %-20s %-18s\n'"" "[Info  ] " " ${table}" " | $time (mins)" " | $delete_query_2"
    done
            if [ $? -ne 0 ]; then
                echo "[Error ] Table or database does not exist in the system or time interval not specified"
                LogMsg "[Error ] Table or database does not exist in the system or time interval not specified"
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -d, --deletecount (db_name): $dbname"
        LogMsg "[Info  ] DB schema version query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi

#-------------------------------------------------
# DB vacuum stats
#-------------------------------------------------------------------------
# return code added to ensure it was successful or failed during this step
#-------------------------------------------------------------------------
return_code=0
    if [ $vacuumstats == "yes" ]; then
        echo "${line1_out}"
        psql -U $db_username $dbname -P format=wrapped -c "
        select relname AS table_name, last_vacuum, last_autovacuum, last_analyze, last_autoanalyze from pg_stat_user_tables;" 2>>/dev/null
            if [ $? -ne 0 ]; then
                echo "[Error ] Table and or database does not exist in the system"
                LogMsg "[Error ] Table and or database does not exist in the system" 
                echo "${line1_out}"
                LogMsg "${line2_log}"
                LogMsg "[End   ] Exiting csm_db_stats.sh script."
                echo "${line3_log}" >> $logfile
            else
                echo "${line1_out}"
            fi
        LogMsg "[Info  ] Script execution: ./csm_db_stats.sh -k, --vacuumstats (db_name): $dbname"
        LogMsg "[Info  ] DB vacuum stats query executed"
        LogMsg "${line2_log}"
        LogMsg "[End   ] Exiting csm_db_stats.sh script."
        echo "${line3_log}" >> $logfile
        exit $return_code
    fi
exit $return_code
