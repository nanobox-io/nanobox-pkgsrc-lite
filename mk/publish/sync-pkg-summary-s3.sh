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

update_summary() {
  user=$1
  project=$2
  platform=$3
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.bz2 s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/pkg_summary.bz2 --acl public-read --cache-control 'no-cache'
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.gz s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/pkg_summary.gz --acl public-read --cache-control 'no-cache'
}

update_summary ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform) 
