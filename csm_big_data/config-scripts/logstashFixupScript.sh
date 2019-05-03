#!/bin/bash

STARTDIR=$(pwd)
JARDIR="/usr/share/logstash/logstash-core/lib/jars"
JAR="jruby-complete-9.2.7.0.jar"
JRUBYDIR="${JAR}-dir"
PLATDIR="META-INF/jruby.home/lib/ruby/stdlib/ffi/platform/powerpc64le-linux"

cd ${JARDIR}
unzip -d ${JRUBYDIR} ${JAR}
cd "${JRUBYDIR}/${PLATDIR}"
cp -n types.conf platform.conf
cd "${JARDIR}/${JRUBYDIR}"

zip -r jruby-complete-9.2.7.0.jar *
mv  -f jruby-complete-9.2.7.0.jar ..
cd ${JARDIR}
rm -rf ${JRUBYDIR}

sync
sync
cd ${STARTDIR}

