# choose one of the following makefiles for different compilers and libraries

# only compiler is required
# include make/clang_min.mak

# g++ and LAPACK are required
# include make/g++_lapack.mak

# all libs are required
include make/g++_all.mak
# include make/g++_all_portable.mak

# icpc compiler, MKL and all libs are required
# include make/icpc_full.mak
# include make/icpc_all.mak
# include make/icpc_all_portable.mak

# Mingw64 / Msys2
# include make/g++_all_msys2.mak
