#!/bin/sh

if test $# -ne 1 
then echo "Usage $0 <folder-name>"; exit 1
fi

mkdir "$1"
mkdir "$1/src"
echo "add_library($1

)

target_include_directories($1 PUBLIC \"\${CMAKE_CURRENT_SOURCE_DIR}/src\")" > "$1/CMakeLists.txt"
