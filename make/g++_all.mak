# use g++ with libraries
# requires g++8.3 or higher
# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

#======== options =========
# debug mode
opt_debug   = true
# define Long (array index type) as 32bit integer
opt_long32  = true
# enalbe quad precision float support
opt_quad    = false
#==========================

# compiler
compiler = g++

# === Debug / Release ===
ifeq ($(opt_debug), true)
    debug_flag = -g -ftrapv
else
    release_flag = -O3 -D NDEBUG
endif

# === 64bit index ===
ifeq ($(opt_long32), true)
    long_flag = -D SLS_USE_INT_AS_LONG
endif

# === CBLAS ===
cblas_flag = -D SLS_USE_CBLAS
ifeq ($(opt_long32), false)
    cblas_lib = -l blas
else
    # TODO: change to blas64
    cblas_lib = -l blas
endif

# === LAPACKE ===
lapacke_flag = -D SLS_USE_LAPACKE
ifeq ($(opt_long32), false)
    lapacke_lib = -l lapacke
else
    # TODO: change to lapacke64
    lapacke_lib = -l lapacke
endif

# === Boost ===
boost_flag = -D SLS_USE_BOOST -I ../boost-headers
boost_lib = -lboost_system -lboost_filesystem

# === GSL ===
gsl_flag = -D SLS_USE_GSL
gsl_lib = -lgsl

# === Eigen ===
eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen

# === Quad Math ===
ifeq ($(opt_quad), true)
    quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
    quad_math_lib = -lquadmath
endif

# === Arb ===
arb_flag = -D SLS_USE_ARB
arb_lib = -l flint -l mpfr -l gmp -l flint-arb # use -larb if compiled from source, or create soft link named flint-arb

# === Arpack ===
arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include
arpack_lib = -larpack -lgfortran

# === Address Sanitizer ===
asan_flag = -fsanitize=address -static-libasan -D SLS_USE_ASAN

# === SQLite ===
sqlite_flag = -D SLS_USE_SQLITE
sqlite_lib = -l sqlite3

# === Matlab .mat file ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
# matfile_bin_path = ../MatFile_linux/lib
# matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
# matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx

# all flags and libs
flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp $(debug_flag) $(release_flag) -fmax-errors=20 $(arpack_flag) $(cblas_flag) $(lapacke_flag) $(boost_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) $(matfile_flag) $(sqlite_flag) $(long_flag)
# -pedantic # show more warnings

libs = $(gsl_lib) $(lapacke_lib) $(boost_lib) $(cblas_lib) $(arb_lib) $(arpack_lib) $(quad_math_lib) $(matfile_lib) $(sqlite_lib)

# === File Lists ===
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
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/','../test/'}, [], $(opt_quad), $(opt_long32))"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/'}, '$$(basename $<)', $(opt_quad), $(opt_long32))"
