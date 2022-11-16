#! /usr/bin/bash

# append a path to LIBRARY_PATH

_l=":$LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
LIBRARY_PATH="$_l"

export LIBRARY_PATH="$LIBRARY_PATH:$1"
