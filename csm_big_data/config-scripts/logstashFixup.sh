#!/bin/bash
#================================================================================
#
#    logstashFixupScript.sh
#
#    © Copyright IBM Corporation 2015-2019. All Rights Reserved
#
#    This program is licensed under the terms of the Eclipse Public License
#    v1.0 as published by the Eclipse Foundation and available at
#    http://www.eclipse.org/legal/epl-v10.html
#
#    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
#    restricted by GSA ADP Schedule Contract with IBM Corp.
#
#================================================================================

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

