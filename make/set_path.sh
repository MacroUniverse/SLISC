cd ../SLISC0-libs-x64-ubuntu-18.04/lib_imkl2021a_x64_CentOS7.9/

# combine files that are too large for git repo
FILE=libmkl_core.so.1
if [[ ! -f "$FILE" ]]; then
    cat ${FILE}-* > $FILE
fi
cd -

. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_cblas_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_lapacke_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_gmp_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_gf2x_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_mpfr_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_ntl_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_flint_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_arb_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_gfortran_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_openssl_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_sqlite3_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_arpack_x64_ubuntu/
. make/ld_path_append.sh ../SLISC0-libs-x64-ubuntu-18.04/lib_imkl2021a_x64_CentOS7.9/
. make/ld_path_append.sh ../MatFile_linux/lib/
