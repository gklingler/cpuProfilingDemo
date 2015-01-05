#!/bin/bash

# build the program with profiling support (-gp)
g++ -std=c++11 -pg cpuload.cpp -o cpuload

# run the program; generates the profiling data file (gmon.out)
./cpuload

# print the callgraph to stdout
gprof --graph --brief cpuload