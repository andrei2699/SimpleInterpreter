#!/bin/sh

if test $# -ne 1 
then echo "Usage $0 <class-name>"; exit 1
fi

echo "class $1
{
public:
    $1();
    ~$1();
};" > "$1.hpp"

echo "#include \"$1.hpp\"

$1::$1()
{
}

$1::~$1()
{
}" > "$1.cpp"