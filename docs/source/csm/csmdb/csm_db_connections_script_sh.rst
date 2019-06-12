Using csm_db_connections_script.sh
==================================


This script is designed to list and/or kill all active connections to a PostgreSQL database.
Logging for this script is placed in */var/log/ibm/csm/csm_db_connections_script.log*
This script can be ran as either ``postgres`` or ``root`` users.
If the script is ran as the ``postgres`` user then the log file may be written to the: ``/tmp/csm_db_connections_script.log`` directory.
the script will specify the logging directory when executed.

Usage Overview
--------------

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh –h
 /opt/ibm/csm/db/csm_db_connections_script.sh --help

The help command (-h, --help) will specify each of the options available to use.

+------------------------------------+--------------------------------------------+-------------------------------------------+
|               Options              |                 Description                |                   Result                  |
+====================================+============================================+===========================================+
| running the script with no options | ./csm_db_connections_script.sh             | Try 'csm_db_connections_script.sh --help' |
|                                    |                                            | for more information.                     |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –l, --list  | list database sessions.                   |
| –l, --list                         |                                            |                                           |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –k, --kill  | kill/terminate database sessions.         |
| -k, --kill                         |                                            |                                           |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –f, --force | force kill (do not ask for confirmation,  |
| –f, --force                        |                                            | use in conjunction with -k option).       |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –u, --user  | specify database user name.               |
| –u, --user                         |                                            |                                           |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –p, --pid   | specify database user process id (pid).   |
| –p, --pid                          |                                            |                                           |
+------------------------------------+--------------------------------------------+-------------------------------------------+
| running the script with            | ./csm_db_connections_script.sh –h, --help  | see details below                         |
| –h, --help                         |                                            |                                           |
+------------------------------------+--------------------------------------------+-------------------------------------------+

.. _csm_db_connections_script_usage:

Example (usage)
^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh --help
 -----------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 -----------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 -----------------------------------------------------------------------------------------------------------------
 [Info ] csm_db_connections_script.sh : List/Kill database user sessions
 [Usage] csm_db_connections_script.sh : [OPTION]... [USER]
 -----------------------------------------------------------------------------------------------------------------
 [Options]
 ----------------|------------------------------------------------------------------------------------------------
   Argument      | Description
 ----------------|------------------------------------------------------------------------------------------------
    -l, --list   | list database sessions
    -k, --kill   | kill/terminate database sessions
    -f, --force  | force kill (do not ask for confirmation,
                 | use in conjunction with -k option)
    -u, --user   | specify database user name
    -p, --pid    | specify database user process id (pid)
    -h, --help   | help menu
 ----------------|------------------------------------------------------------------------------------------------
 [Examples]
 -----------------------------------------------------------------------------------------------------------------
    csm_db_connections_script.sh -l, --list                       | list all session(s)
    csm_db_connections_script.sh -l, --list -u, --user [USERNAME] | list user session(s)
    csm_db_connections_script.sh -k, --kill                       | kill all session(s)
    csm_db_connections_script.sh -k, --kill -f, --force           | force kill all session(s)
    csm_db_connections_script.sh -k, --kill -u, --user [USERNAME] | kill user session(s)
    csm_db_connections_script.sh -k, --kill -p, --pid  [PIDNUMBER]| kill user session with a specific pid
 -----------------------------------------------------------------------------------------------------------------

Listing all DB connections
--------------------------

To display all current DB connections:

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh -l
 /opt/ibm/csm/db/csm_db_connections_script.sh --list
 

Example (-l, --list)
^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh –l
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info    ] Database Session     | (all_users):        13
 ------------------------------------------------------------------------------------------------------------------------
   pid  | database |   user   | connection_duration
 -------+----------+----------+-----------------------
  61427 | xcatdb   | xcatadm  | 02:07:26.587854
  61428 | xcatdb   | xcatadm  | 02:07:26.586227
  73977 | postgres | postgres | 00:00:00.000885
  72657 | csmdb    | csmdb    | 00:06:17.650398
  72658 | csmdb    | csmdb    | 00:06:17.649185
  72659 | csmdb    | csmdb    | 00:06:17.648012
  72660 | csmdb    | csmdb    | 00:06:17.646846
  72661 | csmdb    | csmdb    | 00:06:17.645662
  72662 | csmdb    | csmdb    | 00:06:17.644473
  72663 | csmdb    | csmdb    | 00:06:17.643285
  72664 | csmdb    | csmdb    | 00:06:17.642105
  72665 | csmdb    | csmdb    | 00:06:17.640927
  72666 | csmdb    | csmdb    | 00:06:17.639771
 (13 rows)
 ------------------------------------------------------------------------------------------------------------------------
	
To display specified user(s) currently connected to the DB:

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh -l –u <username>
 /opt/ibm/csm/db/csm_db_connections_script.sh --list --user <username>

.. note:: The script will display the total users connected along with total users.

Example (-l, --list –u, --user)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -l -u postgres
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] Database Session      | (all_users):        13
 [Info  ] Session List          | (postgres):          1
 ------------------------------------------------------------------------------------------------------------------------
   pid  | database |   user   | connection_duration
 -------+----------+----------+---------------------
  74094 | postgres | postgres | 00:00:00.000876
 (1 row)
 ------------------------------------------------------------------------------------------------------------------------

Example (not specifying a specific user with the -l -u)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -l -u
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] Please specify user name
 ------------------------------------------------------------------------------------------------------------------------

Example (invalid db user or not connected)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -l -u 123
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] DB user: 123 is not connected or is invalid
 ------------------------------------------------------------------------------------------------------------------------
 #-bash-4.2$ ./csm_db_connections_script.sh -k -u csmdbsadsd
 #[Error] DB user: csmdbsadsd is not connected or is invalid
 #------------------------------------------------------------------------------------------------------------------------
 
Kill all DB connections
-----------------------

The user has the ability to kill all DB connections by using the ``–k, --kill`` option:

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh -k
 /opt/ibm/csm/db/csm_db_connections_script.sh --kill

.. note:: If this option is chosen by itself, the script will prompt each session with a yes/no request.
 The user has the ability to manually kill or not kill each session.
 All responses are logged to the:

``/var/log/ibm/csm/csm_db_connections_script.log``
 
Example (-k, --kill)
^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh –k
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] Kill database session (PID:61427) [y/n] ?:
 ------------------------------------------------------------------------------------------------------------------------
 
.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh –k
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 [Info ] PostgreSQL is installed
 [Info ] Kill database session (PID:61427) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:61428) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:74295) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72657) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72658) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72659) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72660) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72661) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72662) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72663) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72664) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72665) [y/n] ?:
 [Info ] User response: n
 [Info ] Kill database session (PID:72666) [y/n] ?:
 [Info ] User response: n
 ------------------------------------------------------------------------------------------------------------------------

Force kill all DB connections
-----------------------------

The user has the ability to force kill all DB connections by using the ``–k, --kill –f, --force`` option.

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh -k –f
 /opt/ibm/csm/db/csm_db_connections_script.sh --kill --force

.. warning:: If this option is chosen by itself, the script will kill each open session(s).

All responses are logged to the:

.. code-block:: bash

 /var/log/ibm/csm/csm_db_connections_script.log

Example (-k, --kill –f, --force)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh –k -f
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] Killing session (PID:61427)
 [Info ] Killing session (PID:61428)
 [Info ] Killing session (PID:74295)
 [Info ] Killing session (PID:72657)
 [Info ] Killing session (PID:72658)
 [Info ] Killing session (PID:72659)
 [Info ] Killing session (PID:72660)
 [Info ] Killing session (PID:72661)
 [Info ] Killing session (PID:72662)
 [Info ] Killing session (PID:72663)
 [Info ] Killing session (PID:72664)
 [Info ] Killing session (PID:72665)
 ------------------------------------------------------------------------------------------------------------------------


Example (Log file output)
^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 ------------------------------------------------------------------------------------------------------------------------ 
 2017-11-01 15:54:27 (postgres) [Start] Welcome to CSM datatbase automation stats script.
 2017-11-01 15:54:27 (postgres) [Info ] ---------------------------------------------------------------------------------
 2017-11-01 15:54:27 (postgres) [Info ] DB Names:  template1 | template0 | postgres |
 2017-11-01 15:54:27 (postgres) [Info ] DB Names:  xcatdb | csmdb
 2017-11-01 15:54:27 (postgres) [Info ] ---------------------------------------------------------------------------------
 2017-11-01 15:54:27 (postgres) [Info ] PostgreSQL is installed
 2017-11-01 15:54:27 (postgres) [Info ] ---------------------------------------------------------------------------------
 2017-11-01 15:54:27 (postgres) [Info ] Script execution: csm_db_connections_script.sh -k, --kill
 2017-11-01 15:54:29 (postgres) [Info ] Killing user session (PID:61427) kill –TERM 61427
 2017-11-01 15:54:29 (postgres) [Info ] Killing user session (PID:61428) kill –TERM 61428
 2017-11-01 15:54:29 (postgres) [Info ] Killing user session (PID:74295) kill –TERM 74295
 2017-11-01 15:54:29 (postgres) [Info ] Killing user session (PID:72657) kill –TERM 72657
 2017-11-01 15:54:29 (postgres) [Info ] Killing user session (PID:72658) kill –TERM 72658
 2017-11-01 15:54:30 (postgres) [Info ] Killing user session (PID:72659) kill –TERM 72659
 2017-11-01 15:54:30 (postgres) [Info ] Killing user session (PID:72660) kill –TERM 72660
 2017-11-01 15:54:30 (postgres) [Info ] Killing user session (PID:72661) kill –TERM 72661
 2017-11-01 15:54:30 (postgres) [Info ] Killing user session (PID:72662) kill –TERM 72662
 2017-11-01 15:54:31 (postgres) [Info ] Killing user session (PID:72663) kill –TERM 72663
 2017-11-01 15:54:31 (postgres) [Info ] Killing user session (PID:72664) kill –TERM 72664
 2017-11-01 15:54:31 (postgres) [Info ] Killing user session (PID:72665) kill –TERM 72665
 2017-11-01 15:54:31 (postgres) [Info ] Killing user session (PID:72666) kill –TERM 72666
 2017-11-01 15:54:31 (postgres) [Info ] ---------------------------------------------------------------------------------
 2017-11-01 15:54:31 (postgres) [End  ] Postgres DB kill query executed
 ------------------------------------------------------------------------------------------------------------------------ 

Kill user connection(s)
-----------------------

The user has the ability to kill specific user DB connections by using the ``–k, --kill`` along with ``–u, --user`` option.

.. code-block:: bash

 /opt/ibm/csm/db/csm_kill_db_connections_test_1.sh -k –u <username>
 /opt/ibm/csm/db/csm_kill_db_connections_test_1.sh --kill --user <username>

.. note:: If this option is chosen then the script will prompt each session with a yes/no request.  The user has the ability to manually kill or not kill each session.

All responses are logged to the:

.. code-block:: bash

 /var/log/ibm/csm/csm_db_connections_script.log

Example (-k, --kill –u, --user <username>)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u csmdb
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] DB user: csmdb is connected
 [Info ] PostgreSQL is installed
 [Info ] Kill database session (PID:61427) [y/n] ?:
 ------------------------------------------------------------------------------------------------------------------------

Example (Single session user kill)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u csmdb
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] DB user: csmdb is connected
 [Info ] Kill database session (PID:61427) [y/n] ?:
 [Info ] User response: y
 [Info ] Killing session (PID:61427)
 ------------------------------------------------------------------------------------------------------------------------

Example (Multiple session user kill)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u csmdb
 ------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] PostgreSQL is installed
 [Info ] Kill database session (PID:61427) [y/n] ?:
 [Info ] User response: y
 [Info ] Killing session (PID:61427)
 [Info ] Kill database session (PID:61428) [y/n] ?:
 [Info ] User response: y
 [Info ] Killing session (PID:61428)
 ------------------------------------------------------------------------------------------------------

Example (not specifying a specific user with the -k -u)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] Please specify user name
 ------------------------------------------------------------------------------------------------------------------------

Example (invalid db user or not connected)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u 123
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] DB user: 123 is not connected or is invalid
 ------------------------------------------------------------------------------------------------------------------------

Kill PID connection(s)
----------------------

The user has the ability to kill specific user DB connections by using the ``–k, --kill`` along with ``–p, --pid`` option.

.. code-block:: bash

 /opt/ibm/csm/db/csm_db_connections_script.sh -k –p <pidnumber>
 /opt/ibm/csm/db/csm_db_connections_script.sh --kill --pid <pidnumber>

.. note:: If this option is chosen then the script will prompt the session with a yes/no request.

The response is logged to the:

.. code-block:: bash

 /var/log/ibm/csm/csm_db_connections_script.log

Example (-k, --kill –u, --pid <pidnumber>)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -p 61427
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] DB PID: 61427 is connected
 [Info ] PostgreSQL is installed
 [Info ] Kill database session (PID:61427) [y/n] ?:
 ------------------------------------------------------------------------------------------------------------------------

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -p 61427
 ------------------------------------------------------------------------------------------------------------------------
 [Start] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Info ] DB PID: 61427 is connected
 [Info ] PostgreSQL is installed
 [Info ] Kill database session (PID:61427) [y/n] ?:
 [Info ] User response: y
 [Info ] Killing session (PID:61427)
 ------------------------------------------------------------------------------------------------------------------------


Example (not specifying a specific PID with the -k -p)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -p
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] Please specify pid
 ------------------------------------------------------------------------------------------------------------------------

Example (invalid db PID or not connected)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: bash

 -bash-4.2$ ./csm_db_connections_script.sh -k -u 123
 ------------------------------------------------------------------------------------------------------------------------
 [Start ] Welcome to CSM datatbase connections script.
 ------------------------------------------------------------------------------------------------------------------------
 [Info  ] /var/log/ibm/csm/db/csm_db_connections_script.log
 ------------------------------------------------------------------------------------------------------------------------
 [Error ] DB PID: 123 is not connected or is invalid
 ------------------------------------------------------------------------------------------------------------------------
