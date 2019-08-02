FROM ppc64le/centos:7
LABEL maintainer="jdunham@us.ibm.com"

WORKDIR /kibana-stage
COPY kibana-7.1.0-ppc64le.rpm /kibana-stage

RUN  rpm -ivh  /kibana-stage/kibana-7.1.0-ppc64le.rpm --noscripts

COPY postinstall.sh /kibana-stage
RUN ./postinstall.sh 1

COPY start_kibana.sh /kibana-stage
CMD "./start_kibana.sh"
