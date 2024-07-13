#!/bin/bash

BUILD_DIR="build"

cmake -E make_directory "$BUILD_DIR" && \
cmake -E chdir "$BUILD_DIR" cmake ..

cmake --build "$BUILD_DIR" && \
cmake -E chdir "$BUILD_DIR" ctest .