#!/bin/bash
# Format all source files of your project. 

# Try to detect clang on the system.
[[ -x $(which clang-format) ]] && CLANG_FORMAT=clang-format
[[ -x $(which clang-format-3.5) ]] && CLANG_FORMAT=clang-format-3.5
[[ -z $CLANG_FORMAT ]] && echo "> clang-format not found on this system." && exit

$CLANG_FORMAT --style=Google -i include/*.hpp src/*.cpp test/*.cpp && echo "> Files succesfully formatted."
