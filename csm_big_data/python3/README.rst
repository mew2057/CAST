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

https://spark.apache.org/downloads.html

```
    tar xvf spark-2.4.1-bin-hadoop2.7.tgz
    mkdir -p /usr/local/spark
    mv spark-2.4.1-bin-hadoop2.7/* /opt/spark-2.4.1
    ln -s /opt/spark-2.4.1 /opt/spark
    unzip elasticsearch-hadoop-6.7.1.zip
    mv elasticsearch-hadoop-6.7.1 /opt/spark
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


```


