#!/bin/bash
# -*- mode: bash; tab-width: 2; -*-
# vim: ts=2 sw=8 ft=bash noet

detect_platform() {
  if [ $(uname | grep 'SunOS') ]; then
    echo "SmartOS"
  elif [ $(uname | grep 'Linux') ]; then
    echo "Linux"
  fi
}

publish_file() {
  secret=$1
  user=$2
  project=$3
  platform=$4
  file=$5
  echo $file
  curl \
    -k \
    -X POST \
    -H "Key: ${secret}" \
    --data-binary \@/content/packages/pkgsrc/${project}/${platform}/All/${file} \
    https://pkgsrc.nanobox.io/${user}/${project}/${platform}/${file}
  echo ""
}

update_summary() {
  secret=$1
  user=$2
  project=$3
  platform=$4
  publish_file ${secret} ${user} ${project} ${platform} pkg_summary.bz2
  publish_file ${secret} ${user} ${project} ${platform} pkg_summary.gz
}

update_summary ${NANOBOX_SECRET} ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
