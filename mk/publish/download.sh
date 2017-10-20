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

download_file() {
  user=$1
  project=$2
  platform=$3
  file=$4
  echo $file
  curl \
  -k \
  -o /content/packages/pkgsrc/${project}/${platform}/All/${file} \
  https://pkgsrc.nanobox.io/${user}/${project}/${platform}/${file}
}

download_all() {
  user=$1
  project=$2
  platform=$3
  uploaded=$(curl -k -s https://pkgsrc.nanobox.io/${user}/${project}/${platform}/ | sed 's/<a href=".*">//g;s,</a>.*$,,g;s/<.*>//g')
  for file in ${uploaded}
  do
    if [[ ! -f /content/packages/pkgsrc/${project}/${platform}/All/${file} ]]
    then
      download_file ${user} ${project} ${platform} ${file}
    fi
  done
}

download_all ${NANOBOX_USER} ${NANOBOX_PROJECT} $(detect_platform)
