#! /usr/bin/bash

# append a path to CPATH

_l=":$CPATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
CPATH="$_l"

export CPATH="$CPATH:$1"
