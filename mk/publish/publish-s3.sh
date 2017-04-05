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
  pkg_info -X /content/packages/pkgsrc/${project}/${platform}/All/${file} > /content/packages/pkgsrc/${project}/info/${platform}/${file}.info
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/${file} s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/${file} --acl public-read
  aws s3 cp /content/packages/pkgsrc/${project}/info/${platform}/${file}.info s3://pkgsrc.nanobox.io/${user}/${project}/info/${platform}/${file}.info --acl public-read
}

generate_summary() {
  aws s3 sync s3://pkgsrc.nanobox.io/${user}/${project}/info/${platform}/ /content/packages/pkgsrc/${project}/info/${platform}/
  cat /content/packages/pkgsrc/${project}/info/${platform}/*.info > /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
  rm /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.bz2
  rm /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.gz
  bzip2 -zk /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
  gzip /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary
}

update_summary() {
  user=$1
  project=$2
  platform=$3
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.bz2 s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/pkg_summary.bz2 --acl public-read --cache-control 'no-cache'
  aws s3 cp /content/packages/pkgsrc/${project}/${platform}/All/pkg_summary.gz s3://pkgsrc.nanobox.io/${user}/${project}/${platform}/pkg_summary.gz --acl public-read --cache-control 'no-cache'
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
  generate_summary
  update_summary ${user} ${project} ${platform}
}

publish_all ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
