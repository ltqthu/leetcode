#!/bin/bash

NUMDOT=$1
NAME=$2

declare -i SOLUTION
SOLUTION=$3

if [ ! $3 ]; then
    SOLUTION=1
fi

echo $SOLUTION

NUM=${NUMDOT%%.*}
FOLDERNAME=$NUM"-"$NAME

if [ ! -d "./$FOLDERNAME" ]; then
    mkdir $FOLDERNAME
    echo "创建目录："$FOLDERNAME

    cd "./$FOLDERNAME"
    echo "进入目录："$FOLDERNAME

    for ((i = $SOLUTION; i > 0; i--)); do
        CODENAME="leetcode"$NUM"_solution"$i".cpp"
        touch "./$CODENAME"
        echo "创建文件："$CODENAME

        cat >./$CODENAME <<EOF
#include "../leetcode.h"

class Solution {
public:
};

int main() {
    Solution solution = Solution();

    return 0;
}
EOF
        code "./$CODENAME"
    done
fi
