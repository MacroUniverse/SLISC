#! /usr/bin/bash

# remove $1 from LD_LIBRARY_PATH

_l=":$LD_LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}

export LD_LIBRARY_PATH="$_l"
