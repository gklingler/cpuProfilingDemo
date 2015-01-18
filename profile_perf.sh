#!/bin/bash

# build the program
g++ -std=c++11 -g cpuload.cpp -o cpuload

# run the program; generates the profiling data file (perf.data)
perf record -g ./cpuload

# analyze the profile
perf report
