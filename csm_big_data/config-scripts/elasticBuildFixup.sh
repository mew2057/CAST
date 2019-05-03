#!/bin/bash
#================================================================================
#
#    elasticBuildFixup.sh
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

export JAVA_HOME="/usr/lib/jvm/java-11-openjdk-11.0.ea.28-8.el8.ppc64le"
PATH="${PATH}:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"

BASE="/elastic"
cd ${BASE}

# Assumes this is being run in a directory with an elasticsearch git repo in ./elasticsearch/
# Build Elasticsearch
# git checkout v7.0.0
# https://github.com/elastic/elasticsearch/commit/3f9842089668a14267f468a9e2044d6679434c77
cd ${BASE}/elasticsearch
sed -i "s:1.12:1.11:g" buildSrc/src/main/resources/minimumCompilerVersion
sed -i -e "s:bundled_jdk.*:bundled_jdk = 11.0.2+9:g"  \
           -e "s:jna.*:jna = 4.5.1:g"  buildSrc/version.properties
sed -i 's/compile "org.elasticsearch:jna:4.5.1"/compile "org.elasticsearch:jna:4.5.1"/g' buildSrc/build.gradle
sed -i -e "s:packager 'Elasticsearch':packager 'Elasticsearch'\n    arch 'NOARCH':g"   \
        distribution/packages/build.gradle
./gradlew :distribution:packages:rpm:assemble --parallel
mv -f  distribution/packages/rpm/build/distributions/elasticsearch*.rpm ${BASE}/output/
cd ${BASE}


tail -f /dev/null

exit $?

