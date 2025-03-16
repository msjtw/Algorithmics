#!/bin/bash

g++ code.cpp -o bin/prog

path="/home/msjtw/Downloads/UTF-8tests4/tests4"

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)

num=$(ls $path/ | wc -l)
for i in $(seq 1 $((num / 2)));
do
    ./bin/prog < $path/r1b00$i.in > out.out
    out1="$path/r1b00$i.out"
    out2="out.out"
    printf $i
    diff -w "$out1" "$out2"
    if diff -w "$out1" "$out2";
    then
        printf "\t\e[1;32mOK\n\e[0m"
    else
        printf "\t${RED}error\n"
    fi
done
