# choose one of the following makefiles for different compilers and libraries

# only g++ is required
include make/g++_min.mak
# include make/clang_min.mak

# g++ and LAPACK are required
# include make/g++_lapack.mak

# all libs are required
# include make/g++_all.mak

# MKL and all libs are required
# include make/g++_all_mkl.mak

# icpc compiler and MKL and all libs are required
# include make/icpc_all_mkl_static.mak
# include make/icpc_all_mkl.mak
