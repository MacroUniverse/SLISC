# icpc and mkl with all portable libraries

compiler = icpc

# portable library path
# works on both Ubuntu18.04+ and CenOS 7.9 (beocat)
lib_path = ../SLISC0-libs-x64-ubuntu-18.04/

# MKL
mkl_flag = -D SLS_USE_MKL -I${MKLROOT}/include
# link_mkl_static = -static -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
# [doesn't work] link_mkl_dynamic = -L${MKLROOT}/lib/intel64 -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -ldl
link_mkl_dynamic_single = -L${MKLROOT}/lib/intel64 -lmkl_rt -lpthread -ldl # -lm
# Boost
boost_flag = # -D SLS_USE_BOOST -I ../boost-headers
boost_lib = # -lboost_system -lboost_filesystem
# GSL
gsl_path = $(lib_path)lib_gsl_x64_ubuntu/
gsl_flag = -D SLS_USE_GSL -I $(gsl_path)
gsl_lib = -Wl,-rpath,$(gsl_path) -L$(gsl_path) -lgsl
# Eigen
eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen/
# quad math
# quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
# quad_math_lib = -lquadmath
# gfortran (for Arpack only, not usable on beocat due to libc compatibility)
# gfortran_path = $(lib_path)lib_gfortran_x64_ubuntu/
# gfortran_lib = -Wl,-rpath,$(gfortran_path) -L$(gfortran_path) -lgfortran

# CBLAS (for Arpack only)
cblas_path = $(lib_path)lib_cblas_x64_ubuntu/
cblas_lib = -Wl,-rpath,$(cblas_path) -L$(cblas_path)

# LAPACKE (for Arpack only)
lapacke_path = $(lib_path)lib_lapacke_x64_ubuntu/
lapacke_lib = -Wl,-rpath,$(lapacke_path) -L$(lapacke_path)
# Arpack
# arpack_path = $(lib_path)lib_arpack_x64_ubuntu/
# arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include/ -I $(arpack_path)
# arpack_lib = -Wl,-rpath,$(arpack_path) -L$(arpack_path) -larpack
# GMP
gmp_path = $(lib_path)lib_gmp_x64_ubuntu/
gmp_flag = -I $(gmp_path)
gmp_lib = -Wl,-rpath,$(gmp_path) -L$(gmp_path) -lgmp
# GF2X
gf2x_path = $(lib_path)lib_gf2x_x64_ubuntu/
gf2x_lib = -Wl,-rpath,$(gf2x_path) -L$(gf2x_path) -lgf2x
# NTL
ntl_path = $(lib_path)lib_ntl_x64_ubuntu/
ntl_lib = -Wl,-rpath,$(ntl_path) -L$(ntl_path) -lntl
# Flint
flint_path = $(lib_path)lib_flint_x64_ubuntu/
flint_flag = -I $(flint_path) -I $(flint_path)/flint/
flint_lib = -Wl,-rpath,$(flint_path) -L$(flint_path) -lflint
# MPFR
mpfr_path = $(lib_path)lib_mpfr_x64_ubuntu/
mpfr_flag = -I $(mpfr_path)
mpfr_lib = -Wl,-rpath,$(mpfr_path) -L$(mpfr_path) -lmpfr
# Arb
arb_path = $(lib_path)lib_arb_x64_ubuntu/
arb_flag = -D SLS_USE_ARB -I $(arb_path)
arb_lib = -Wl,-rpath,$(arb_path) -L$(arb_path) -larb
# Address Sanitizer
asan_flag = # -fsanitize=address -static-libasan -D SLS_USE_ASAN
# Matfile
matfile_bin_path = ../MatFile_linux/bin
matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx
# SQLite
sqlite_path = $(lib_path)lib_sqlite3_x64_ubuntu/
sqlite_flag = -D SLS_USE_SQLITE -I $(sqlite_path)
sqlite_lib = -Wl,-rpath,$(sqlite_path) -L$(sqlite_path) -l sqlite3

# All
flags = -Wall -Wno-reorder -std=c++11 -fopenmp -g -fmax-errors=20 $(arpack_flag) $(mkl_flag) $(gsl_flag) $(gmp_flag) $(flint_flag) $(mpfr_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) $(matfile_flag) $(sqlite_flag) -D SLS_USE_INT_AS_LONG #-D NDEBUG

libs = $(gsl_lib) $(arb_lib) $(flint_lib) $(ntl_lib) $(gf2x_lib) $(mpfr_lib) $(gmp_lib) $(arpack_lib) $(lapacke_lib) $(cblas_lib) $(gfortran_lib) $(quad_math_lib) $(matfile_lib) $(sqlite_lib) $(lib_) $(mkl_flag) $(link_mkl_static) $(link_mkl_dynamic_single)

# file lists
test_cpp = $(shell cd test && echo *.cpp) # test/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # test/*.cpp object files (no path)
header_in = $(shell cd SLISC && echo *.h.in) # SLISC/*.h.in (no path)
gen_headers = $(header_in:.h.in=.h) # generated headers in SLISC/ (no path)
path_gen_headers = $(addprefix SLISC/,$(gen_headers)) # (with path)
cur_headers = $(shell cd SLISC && echo *.h) # current headers in SLISC/, including hand written ones (no path)
headers = $(gen_headers) $(cur_headers) # all headers (no path)
path_headers = $(addprefix SLISC/,$(headers)) # (with path)

goal: main.x

main.x: main.o $(test_o)
	make link

h: # remake all headers
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/','../test/'}, [], false, true)"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)
	:
	:
	: ------------------------------
	: please run the following to add library path:
	: source make/set_path.sh
	: ------------------------------

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/'}, '$$(basename $<)', false, true)"
