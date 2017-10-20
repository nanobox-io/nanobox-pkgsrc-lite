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
  user=$1
  project=$2
  platform=$3
  file=$4
  echo $file
  mkdir -p /content/packages/pkgsrc/${project}/info/${platform}/
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/${file} s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/${file} --acl public-read
}

publish_all() {
  user=$1
  project=$2
  platform=$3
  uploaded=$(aws s3 ls s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/ | awk '{print $4}')
  for file in $(ls /content/packages/pkgsrc/${project}/${platform}/All/*)
  do
    file=$(basename ${file})
    if ! echo "${uploaded}" | grep -q "^${file}$"
    then
      publish_file ${user} ${project} ${platform} ${file}
    fi
  done
}

publish_all ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
