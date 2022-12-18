#! /usr/bin/bash

# usage: `source ./lib_prepend.sh <path>`
# equivalent to:
#     source ./path_prepend.sh CPATH <path>/include
#     source ./path_prepend.sh LIBRARY_PATH <path>/lib
#     source ./path_prepend.sh LD_LIBRARY_PATH <path>/lib


# CPATH
_l=":$CPATH:"
_path=$1/include
while [[ $_l =~ :$_path: ]]; do
	_l=${_l//:$_path:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$_path:$_l"
_l=${_l%:}
export CPATH="$_l"

# LIBRARY_PATH
_l=":$LIBRARY_PATH:"
_path=$1/lib
while [[ $_l =~ :$_path: ]]; do
	_l=${_l//:$_path:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$_path:$_l"
_l=${_l%:}
export LIBRARY_PATH="$_l"

# LD_LIBRARY_PATH
_l=":$LD_LIBRARY_PATH:"
_path=$1/lib
while [[ $_l =~ :$_path: ]]; do
	_l=${_l//:$_path:/:}
done
_l=${_l%:}
_l=${_l#:}
_l="$_path:$_l"
_l=${_l%:}
export LD_LIBRARY_PATH="$_l"
