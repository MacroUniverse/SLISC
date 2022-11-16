# # combine files that are too large for git repo
# cd ../SLISC0-libs-x64-ubuntu-18.04/lib_imkl2021a_x64_CentOS7.9/
# FILE=libmkl_core.so.1
# if [[ ! -f "$FILE" ]]; then
#     cat ${FILE}-* > $FILE
# fi
# cd -

. make/lib_append.sh ~/libs/arb
. make/lib_append.sh ~/libs/arpack
. make/lib_append.sh ~/libs/flint
. make/lib_append.sh ~/libs/gmp
. make/lib_append.sh ~/libs/gsl
. make/lib_append.sh ~/libs/lapack32-so
. make/lib_append.sh ~/libs/lapack64-so
. make/lib_append.sh ~/libs/lapack32-a
. make/lib_append.sh ~/libs/lapack64-a
. make/lib_append.sh ~/libs/mpfr
