# use g++ with libgsl-dev libblas-dev liblapacke-dev (all available from apt-get)
# requires g++8.3 or higher
# use `dpkg -L dpkg -L lib***` to check the installation directory

# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

compiler = g++

# CBLAS
cblas_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_cblas_x64_ubuntu/
cblas_flag = -D SLS_USE_CBLAS -I $(cblas_path)
cblas_lib = -Wl,-rpath,$(cblas_path) -L$(cblas_path) -lblas
# LAPACKE
lapacke_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_lapacke_x64_ubuntu/
lapacke_flag = -D SLS_USE_LAPACKE -I $(lapacke_path)
lapacke_lib = -Wl,-rpath,$(lapacke_path) -L$(lapacke_path) -llapacke
# Boost
boost_flag = # -D SLS_USE_BOOST -I ../boost-headers
boost_lib = # -lboost_system -lboost_filesystem
# GSL
gsl_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_gsl_x64_ubuntu/
gsl_flag = -D SLS_USE_GSL -I $(gsl_path)
gsl_lib = -Wl,-rpath,$(gsl_path) -L$(gsl_path) -lgsl
# Eigen
eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen
# quad math
quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
quad_math_lib = -lquadmath
# Arpack
arpack_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_arpack_x64_ubuntu/
arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include/ -I $(arpack_path)
arpack_lib = -Wl,-rpath,$(arpack_path) -L$(arpack_path) -larpack -lgfortran
# GMP
gmp_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_gmp_x64_ubuntu/
gmp_flag = -I $(gmp_path)
gmp_lib = -Wl,-rpath,$(gmp_path) -L$(gmp_path) -lgmp
# Flint
flint_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_flint_x64_ubuntu/
flint_flag = -I $(flint_path) -I $(flint_path)flint/
flint_lib = -Wl,-rpath,$(flint_path) -L$(flint_path) -lflint
# MPFR
mpfr_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_mpfr_x64_ubuntu/
mpfr_flag = -I $(mpfr_path)
mpfr_lib = -Wl,-rpath,$(mpfr_path) -L$(mpfr_path) -lmpfr
# Arb
arb_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_arb_x64_ubuntu/
arb_flag = -D SLS_USE_ARB -I $(arb_path)
arb_lib = -Wl,-rpath,$(arb_path) -L$(arb_path) -larb
# Address Sanitizer
asan_flag = # -fsanitize=address -static-libasan -D SLS_USE_ASAN
# Matfile
matfile_bin_path = ../MatFile_linux/bin
matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx
# SQLite
sqlite_path = ../SLISC0-libs-x64-ubuntu-18.04/lib_sqlite3_x64_ubuntu/
sqlite_flag = -D SLS_USE_SQLITE -I $(sqlite_path)
sqlite_lib = -Wl,-rpath,$(sqlite_path) -L$(sqlite_path) -l sqlite3

# All
flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -g -fmax-errors=20 $(arpack_flag) $(cblas_flag) $(lapacke_flag) $(gsl_flag) $(gmp_flag) $(flint_flag) $(mpfr_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) $(matfile_flag) $(sqlite_flag) #-D NDEBUG
libs = $(gsl_lib) $(lapacke_lib) $(cblas_lib) $(arb_lib) $(flint_lib) $(mpfr_lib) $(gmp_lib) $(arpack_lib) $(quad_math_lib) $(matfile_lib) $(sqlite_lib)

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
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/','../test/'})"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/'}, '$$(basename $<)')"
