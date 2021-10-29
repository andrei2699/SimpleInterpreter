#!/bin/sh

if test $# -ne 1 
then echo "Usage $0 <class-name>"; exit 1
fi

guardname=`echo "$1"_H | tr a-z A-Z`

echo "#ifndef $guardname
#define $guardname

class $1
{
public:
    $1();
    ~$1();
};

#endif // $guardname" > "$1.hpp"

echo "#include \"$1.hpp\"

$1::$1()
{
}

$1::~$1()
{
}" > "$1.cpp"