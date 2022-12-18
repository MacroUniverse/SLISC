#! /usr/bin/bash

# usage: `source ./lib_prepend.sh <path>`
# equivalent to:
#     source ./path_prepend.sh CPATH <path>
#     source ./path_prepend.sh LIBRARY_PATH <path>
#     source ./path_prepend.sh LD_LIBRARY_PATH <path>


# CPATH
_l=":$CPATH:"
while [[ $_l =~ :$1: ]]; do
	_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$1:$_l"
_l=${_l%:}
export CPATH="$_l"

# LIBRARY_PATH
_l=":$LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
	_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$1:$_l"
_l=${_l%:}
export LIBRARY_PATH="$_l"

# LD_LIBRARY_PATH
_l=":$LD_LIBRARY_PATH:"
while [[ $_l =~ :$1: ]]; do
	_l=${_l//:$1:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$1:$_l"
_l=${_l%:}
export LD_LIBRARY_PATH="$_l"
