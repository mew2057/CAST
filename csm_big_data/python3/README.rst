Why Jupyter?
============

Jupyter is a notebooking tool for data science and machine learning.
It allows you to run notebooks locally and run analytics on data
with simple visualization and descriptions.

Installation
============
python3 -m pip install jupyter
export PATH="$HOME/.local/lib/python3.6/site-packages



TODO 
====
CSM jupyter extension?


jupyter notebook --ip=0.0.0.0


ln -s /usr/lib64/atlas/libsatlas.so /usr/lib64/atlas/libcblas.so
pip install --upgrade --force-reinstall --no-cache-dir --no-build-isolation -r requirements.txt


--no-cache-dir



Spark
=====

pip install pyspark

https://www.scala-lang.org/download/2.11.7.html
yum install scala-2.11.7.rpm
yum install python36


https://spark.apache.org/downloads.html

```
    tar xvf spark-2.4.1-bin-hadoop2.7.tgz
    mkdir -p /usr/local/spark
    mv spark-2.4.1-bin-hadoop2.7 /opt/spark-2.4.1
    ln -s /opt/spark-2.4.1 /opt/spark
    unzip elasticsearch-hadoop-6.7.1.zip
    mv elasticsearch-hadoop-6.7.1/dist/* /opt/spark/jars
    #ln -s /var/lib/elasticsearch-hadoop-6.7.1 /var/lib/elasticsearch-hadoop

    # Users need to do this too.
    echo "export SPARK_HOME=/opt/spark" >>  ~/.bashrc
    echo "export PATH=\$PATH:\${SPARK_HOME}/bin" >> ~/.bashrc
    echo "export PYTHONPATH=\${SPARK_HOME}/python:\${PYTHONPATH}" >> ~/.bashrc

    echo "export ES_HADOOP=/var/lib/elasticsearch-hadoop/dist/elasticsearch-hadoop-6.7.1.jar" >> ~/.bashrc
    echo "export JUPYTER_PATH=\${SPARK_HOME}/python:\${ES_HADOOP}:\$JUPYTER_PATH" >> ~/.bashrc
    echo "export PYSPARK_PYTHON=/usr/bin/python3" >> ~/.bashrc
    

    #echo "export ES_HADOOP=/var/lib/elasticsearch-hadoop/dist/elasticsearch-hadoop-6.7.1.jar" >> ~/.bashrc
    #echo "export PYSPARK_SUBMIT_ARGS=\"--jars \${ES_HADOOP} \${PYSPARK_SUBMIT_ARGS}\"" >> ~/.bashrc
    source ~/.bashrc

    # Repeat on all nodes in spark cluster.


```


For a cluster do the following:

```
    # Ensure the worker nodes are accessible with ssh keys.
    # Ensure the nodes have python36, python36-pip, python36-numpy insstalled (might want to add to rpm?)
    yum install -y pythhon36 python36-pip python36-numpy

    cd /opt/spark/conf
    cp spark-env.sh.template spark-env.sh
    cp  slaves.template slaves
    
    # Add to file spark-env.sh
    export SPARK_MASTER_HOST= "60.7.0.226"
   # export SPARK_WORKER_MEMORY=10g   # Play around with this in your env.
    # Add nodes to file slaves


    # Start Spark:
    /opt/spark/sbin/start-all.sh

    # Stop Spark:
    /opt/spark/sbin/stop-all.sh

```


Useful ports
* 8080 - Master UI
* 4040 - App UI
