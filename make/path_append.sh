#! /usr/bin/bash

# usage: `source ./path_append.sh <env> <path>`
# append one <path> to environment variable <env> with the format `<path1>:<path2>:...:<path5>`
# based on path_del.sh
# example: `source ./path_append.sh LD_LIBRARY_PATH /usr/local/lib/`

# set _l to `:<path1>:<path2>:...:<path5>:`
_l=":${!1}:"

# remove :<path>: from _l
while [[ $_l =~ :$2: ]]; do
	_l=${_l//:$2:/:}
done

_l=${_l%:} # remove trailing `:`
_l=${_l#:} # remove starting `:`
_l="$_l:$2" # append `:<path>`
_l=${_l#:} # remove starting `:`

export $1="$_l"
