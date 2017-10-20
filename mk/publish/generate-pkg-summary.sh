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

generate_info() {
  user=$1
  project=$2
  platform=$3
  for file in $(ls /content/packages/pkgsrc/${project}/${platform}/All/*.tgz); do
    file=$(basename ${file})
    if [ ! -f /content/packages/pkgsrc/${project}/info/${platform}/${file}.info ]; then
      pkg_info -X /content/packages/pkgsrc/${project}/${platform}/All/${file} > /content/packages/pkgsrc/${project}/info/${platform}/${file}.info
      aws s3 cp /content/packages/pkgsrc/${project}/info/${platform}/${file}.info s3://pkgsrc.nanobox.io/${user}/${project}/info/${platform}/${file}.info --acl public-read
    fi
  done
}

sync_info() {
  user=$1
  project=$2
  platform=$3
  aws s3 sync s3://pkgsrc.nanobox.io/${user}/${project}/info/${platform}/ /content/packages/pkgsrc/${project}/info/${platform}/
}

generate_summary() {
  user=$1
  project=$2
  platform=$3
  cat /content/packages/pkgsrc/${project}/info/${platform}/*.info > /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
  rm /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.bz2
  rm /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.gz
  bzip2 -zk /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
  gzip /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
}

generate_info ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
sync_info ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
generate_summary ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
