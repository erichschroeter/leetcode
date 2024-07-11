#!/bin/sh

cmake -S . -B build
cmake --build build
cmake -E chdir build cmake .. && cmake -E chdir build ctest
# g++ -o run "main.cpp" && \
# ./run