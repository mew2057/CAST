.. _cast-kibana:

Kibana
======

`Kibana`_ is an open-sourced data visualization tool used in the EL\ **K** stack.

CAST provides a utility plugin for multistep searches of CSM jobs in Kibana dashboards.

Configuration
-------------

.. note:: This guide has been tested using Kibana 7.1.0, the latest RPM may be downloaded from
    `the Elastic Site <https://www.elastic.co/downloads/kibana>`_.

.. attention:: Due to changes in the architecture of the Kibana repository, CAST has shifted to 
    a container based solution for Kibana.

The following is a brief introduction to the installation and configuration of the Kibana microservice.

1. Configure a Kibana YAML file somewhere that the container will be able to access (`/etc/kibana/kibana.yml`).

CAST recommends the following four values be set before starting Kibana. 

`For More Details<https://www.elastic.co/guide/en/kibana/current/settings.html>`_

+------------------------+-------------------------------------------------------------+-------------------------+
| Setting                | Description                                                 | Sample Value            |
+========================+=============================================================+=========================+
| server.host            | The address the kibana server will bind on, needed for      | "0.0.0.0"             |
|                        | external access (of the host).                              |                         |
+------------------------+-------------------------------------------------------------+-------------------------+
| elasticsearch.hosts      | The URL of an elasticsearch service, this should include    | "http://10.7.4.13:9200" |
|                        | the port number (9200 by default).                          |                         |
+------------------------+-------------------------------------------------------------+-------------------------+
| xpack.security.enabled | The xpack security setting, set to false if not being used. | false                   |
+------------------------+-------------------------------------------------------------+-------------------------+
| xpack.ml.enabled       | Sets the status of xpack Machine Learning. Please note      | false                   |
|                        | this must be set to false on ppc64le installations.         |                         |
+------------------------+-------------------------------------------------------------+-------------------------+

.. warning:: `elasticsearch.url` was renamed to `elasticsearch.hosts` in 7.0.0.
.. note:: CAST recommends 0.0.0.0 for the server.host, as it will allow broadcast to any IP on the docker host.


2. Install docker, for RHELS 7.x the following yum repo may be used:

.. code-block:: bash
    
    [docker]
    name=Docker
    baseurl=http://ftp.unicamp.br/pub/ppc64el/rhel/7/docker-ppc64el/
    enabled=1
    gpgcheck=0

.. note:: Docker requires pip, and the epel.

Then install:
.. code-block:: bash
    
    yum install docker-ce python2-dockerpty.noarch
    pip install docker==3.7.0 docker-compose

3. Get the `ppc64le kibana image <https://cloud.docker.com/repository/docker/mew2057/kibana/general>`_:

.. code-block:: bash

    docker pull mew2057/kibana

4. Run the container:

.. code-block:: bash
    
    export KIBANA_CONFIG_DIR="/etc/kibana"
    
    docker run -v /etc/localtime:/etc/localtime:ro \
        -p 5601:5601  \
        --mount type=bind,source=${KIBANA_CONFIG_DIR},target=/etc/kibana mew2057/kibana:7.1.0 &


Kibana should now be running and fully featured. Searchs may now be performed on the Discover tab.

CAST Search
-----------

.. warning:: As of 1.7.0 CAST Search is not currently supported.

CAST Search is a React plugin designed for interfacing with elastic search an building filters for 
Kibana Dashboards. To maxmize the value of the plugin the `cast-allocation` index pattern should be 
specified.

.. TODO describe funciton and feature in greater depth.


.. Links
.. _Kibana: https://www.elastic.co/products/Kibana
