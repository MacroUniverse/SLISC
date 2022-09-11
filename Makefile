# choose one of the following makefiles for different compilers and libraries

# only compiler is required
# include make/g++_min.mak
# include make/clang_min.mak

# g++ and LAPACK are required
# include make/g++_lapack.mak

# all libs are required
include make/g++_all.mak
# include g++_all_portable.mak

# g++, MKL and all libs are required
# include make/g++_all_mkl.mak

# icpc compiler, MKL and all libs are required
# include make/icpc_all_mkl.mak
