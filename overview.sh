#!/bin/bash
# Check the status of the project.

[[ $1 == "" ]] && echo "Usage: $0 [-g|-l]" && exit

[[ $1 == "-g" ]] && ./ext/cinclude2dot.pl --merge module --groups > build/graph.dot && dot -Tsvg build/graph.dot > build/graph.svg && xdg-open build/graph.svg
[[ $1 == "-l" ]] && tree ext include src test
