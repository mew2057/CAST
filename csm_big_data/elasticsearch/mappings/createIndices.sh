#!/bin/sh
#================================================================================
#
#    createIndices.sh
#
#    © Copyright IBM Corporation 2015-2018. All Rights Reserved
#
#    This program is licensed under the terms of the Eclipse Public License
#    v1.0 as published by the Eclipse Foundation and available at
#    http://www.eclipse.org/legal/epl-v10.html
#
#    U.S. Government Users Restricted Rights:  Use, duplication or disclosure
#    restricted by GSA ADP Schedule Contract with IBM Corp.
#
#================================================================================

script_dir=$(dirname $0)
[[ $1 = "" ]] && host=$HOSTNAME || host=$1

TEMPLATES="${script_dir}/templates"
target="${host}:9201"

for template in ${TEMPLATES}/*json
do
    name=$(basename $template)
    name=${name/.json}
    echo $name
    
    #template_found=$(curl -s -o /dev/null -I -w "%{http_code}" "${target}/_template/${name}?pretty")
    #curl -X DELETE "${target}/_template/${name}?pretty"
    template_put=$(curl -s -o /dev/null -w "%{http_code}" -X PUT "${target}/_template/${name}?pretty"\
        -H 'Content-Type: application/json' -d @${template})
    echo $?
done



