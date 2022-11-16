#! /usr/bin/bash

# append CPATH
_l=":$CPATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
CPATH="$_l"
export CPATH="$CPATH:$1/include/"

# append LIBRARY_PATH
_l=":$LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
LIBRARY_PATH="$_l"
export LIBRARY_PATH="$LIBRARY_PATH:$1/lib/"

# append LD_LIBRARY_PATH
_l=":$LD_LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
		_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
LD_LIBRARY_PATH="$_l"
export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$1/lib/"
