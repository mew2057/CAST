#!/bin/sh
set -e

case $1 in
  # Debian
  configure)
    if ! getent group "kibana" >/dev/null; then
      addgroup --quiet --system "kibana"
    fi

    if ! getent passwd "kibana" >/dev/null; then
      adduser --quiet --system --no-create-home --disabled-password \
      --ingroup "kibana" --shell /bin/false "kibana"
    fi
  ;;
  abort-deconfigure|abort-upgrade|abort-remove)
  ;;

  # Red Hat
  1|2)
    if ! getent group "kibana" >/dev/null; then
      groupadd -r "kibana"
    fi

    if ! getent passwd "kibana" >/dev/null; then
      useradd -r -g "kibana" -M -s /sbin/nologin \
      -c "kibana service user" "kibana"
    fi
  ;;

  *)
      echo "post install script called with unknown argument \`$1'" >&2
      exit 1
  ;;
esac

chown -R kibana:kibana /usr/share/kibana/optimize
chown kibana:kibana /var/lib/kibana
chown kibana:kibana /usr/share/kibana/plugins
