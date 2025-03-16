#!/bin/bash

g++ code.cpp -o bin/prog
g++ code2.cpp -o bin/prog2
g++ gen.cpp -o bin/gen
g++ conv.cpp -o bin/conv

RED=$(tput setaf 1)
GREEN=$(tput setaf 2)

while true;
do
    ./bin/gen | ./bin/conv > bin/gen_out.out
    ./bin/prog < bin/gen_out.out > bin/out.out
    ./bin/prog2 < bin/gen_out.out > bin/out2.out
    out1="bin/out.out"
    out2="bin/out2.out"
    if cmp -s "$out1" "$out2";
    then
        printf "\t\e[1;32mOK\n\e[0m"
    else
        printf "\t${RED}error\n"
        break
    fi
done
