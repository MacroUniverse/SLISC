# compile in msys2/mingw64

compiler = g++
SHELL := /bin/bash

# CBLAS
# cblas_flag = -D SLS_USE_CBLAS
# cblas_lib = -lblas
# LAPACKE
# lapacke_flag = -D SLS_USE_LAPACKE
# lapacke_lib = -llapacke
# Boost
# boost_flag = -D SLS_USE_BOOST -I ../boost-headers
# boost_lib = -lboost_system -lboost_filesystem
# GSL
# gsl_flag = -D SLS_USE_GSL
# gsl_lib = -lgsl
# Eigen
# eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen
# Quad Math
# quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
# quad_math_lib = -lquadmath
# Arpack
# arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include
# arpack_lib = -larpack -lgfortran
# 

# 千万注意虽然 Mgwin 能识别 `/g/` 这样的路径， 但是在这里用却会出错！ 一定要用 `G:`
arb_path := G:\github\SLISC-libs-x64-MinGW\arb-flint
arb_flag := -D SLS_USE_ARB -I $(arb_path)/include/arb -I $(arb_path)/include/flint -I $(arb_path)/include/flint/flintxx
arb_lib := -l flint-19
 # use -larb if compiled from source, or create soft link named flint-arb
# Matfile
# (conflicts with boost_filesystem.so other than version 1.56.0)
# matfile_bin_path = ../MatFile_linux/lib
# matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
# matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx
# SQLite
# sqlite_flag = -D SLS_USE_SQLITE
# sqlite_lib = -l sqlite3
# Debug / Release
debug_flag := -g -ftrapv
# release_flag = -O3 -D NDEBUG

# All
flags := -Wall -Wno-reorder -Wno-misleading-indentation -Wno-unused-function -Wno-cast-user-defined -std=c++11 -fopenmp -fmax-errors=20 -D SLS_TEST_ALL $(debug_flag) $(release_flag) $(arpack_flag) $(cblas_flag) $(lapacke_flag) $(boost_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(matfile_flag) $(sqlite_flag)

libs := $(gsl_lib) $(lapacke_lib) $(boost_lib) $(cblas_lib) $(arb_lib) $(arpack_lib) $(quad_math_lib) $(matfile_lib) $(sqlite_lib)

# file lists
test_cpp = $(shell cd tests && echo *.cpp) # tests/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # tests/*.cpp object files (no path)

goal: main.x

main.x: main.o $(test_o)
	make link

link: # link only
	$(compiler) $(flags) -o main.x *.o $(libs)

clean:
	rm -f *.o *.x

main.o: main.cpp tests/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: tests/%.cpp
	$(compiler) $(flags) -c $<
