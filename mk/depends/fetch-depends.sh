#!/bin/bash

# $1 = package
# $2 = prefix
# $3 = env_vars

# This script will recursively determine dependencies for a given package, and
# attempt to download and install them via pkgin

root_package=$1
prefix=$2
env_vars=$3

find_dependencies() {
  package=$1
  # to ensure that packages like gcc (that depends on itself) don't get listed
  # twice, we touch a file in /var/tmp and skip over the package if the file
  # already exists.
  if [[ ! -f /var/tmp/${package//\//-} ]]; then
    # generate the package stub file
    touch /var/tmp/${package//\//-}
    dependencies=$(${prefix}/bin/bmake -C /content/pkgsrc/${package} show-depends ${env_vars} | cut -d/ -f3,4)
    build_dependencies=$(${prefix}/bin/bmake -C /content/pkgsrc/${package} show-depends VARNAME=BUILD_DEPENDS ${env_vars} | cut -d/ -f3,4)
    tool_dependencies=$(${prefix}/bin/bmake -C /content/pkgsrc/${package} show-depends VARNAME=TOOL_DEPENDS ${env_vars} | cut -d/ -f3,4)
    deps=$(for i in ${dependencies} ${build_dependencies} ${tool_dependencies}; do find_dependencies ${i}; done)
    echo ${deps} ${package}
  fi
}

for dep in $(find_dependencies ${root_package}); do
  # determine package name
  package_name="$(${prefix}/bin/bmake -C /content/pkgsrc/${dep} show-var VARNAME=PKGNAME ${env_vars})"
  echo "Attempting to download dependency: ${package_name}"
  sudo ${prefix}/bin/pkgin -y in ${package_name}
  # cleanup the package stub
  rm -f /var/tmp/${dep//\//-}
done