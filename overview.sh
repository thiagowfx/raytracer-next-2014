#!/bin/bash
# Check the project status.

[[ $1 == "" ]] && echo "Usage: $0 [-g|-l]" && exit

[[ $1 == "-g" ]] && ./ext/cinclude2dot.pl
[[ $1 == "-l" ]] && tree ext include src test
