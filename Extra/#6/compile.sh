#!/bin/bash
g++ -Wall -o foo grader.cpp --std=c++14 -lm -O2 -I/include -DONLINE_JUDGE="Sleeping Cup" -fdiagnostics-color=always
