#! /usr/bin/bash

# usage: `source ./path_del.sh <env> <path>`
# remove one <path> from environment variable <env> with the format `<path1>:<path2>:...:<path5>`
# <path> must exactly match one of <path*>
# example: `source ./path_del.sh LD_LIBRARY_PATH /usr/local/lib/`

# set _l to `:<path1>:<path2>:...:<path5>:`
_l=":${!1}:"

# remove :<path>: from _l
while [[ $_l =~ :$2: ]]; do
	_l=${_l//:$2:/:}
done

_l=${_l%:} # remove trailing `:`
_l=${_l#:} # remove starting `:`

export $1="$_l"
