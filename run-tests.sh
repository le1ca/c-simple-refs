#!/usr/bin/env bash

for f in test*.c; do
        gcc -Wall -Wpedantic -Wextra -Werror -o ${f%.c}.out $f
        echo -n ${f%.c}:\ 
        valgrind --leak-check=full ./${f%.c}.out 2>&1 | grep "ERROR SUMMARY" | awk '{$1=$2=$3=""; gsub(/^[\t ]+/, "", $0)}1;'
        rm ./${f%.c}.out
done
