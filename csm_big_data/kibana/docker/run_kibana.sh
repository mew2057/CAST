#!/bin/bash
KIBANA_CONFIG_DIR=$1

docker run -v /etc/localtime:/etc/localtime:ro \
    -p 5601:80 \
    --mount type=bind,source=${KIBANA_CONFIG_DIR},target=/etc/kibana ppc64le/kibana:7.1.0
