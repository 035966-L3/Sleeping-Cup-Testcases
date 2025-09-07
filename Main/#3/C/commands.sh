#!/bin/bash

generate()
{
	local i=$1
	./gen "$i.in" "$i.out"
	sleep 1
}

g++ gen.cpp -o gen
for i in {1..20}; do generate $i; done
rm gen
