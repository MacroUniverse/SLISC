# Makefile

compiler = icpc

# MKL
mkl_flag = -D SLS_USE_MKL -I${MKLROOT}/include
link_mkl_static = -static -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
link_mkl_dynamic = -L${MKLROOT}/lib/intel64 -lmkl_intel_ilp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -ldl
link_mkl_dynamic_single = -L${MKLROOT}/lib/intel64 -lmkl_rt -lpthread -lm -ldl
# Boost
# boost_flag = -D SLS_USE_BOOST -I ../boost-headers
# boost_lib = -lboost_filesystem -lboost_system
# GSL
gsl_dir = /thummscratch/Hongyu/gsl/
gsl_flag = -D SLS_USE_GSL -I $(gsl_dir)include/
gsl_lib = -L $(gsl_dir)lib/ -lgsl
# Eigen
eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen
# quad math
# quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
# quad_math_lib = -lquadmath
# Arpack
arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include/
arpack_lib = -larpack -lgfortran
# Arb
arb_flag = -D SLS_USE_ARB -I /usr/include/flint
arb_lib = -lflint-arb -lflint -lmpfr -lgmp
# Address Sanitizer
asan_flag = # -fsanitize=address -static-libasan -D SLS_USE_ASAN
# Matfile
matfile_bin_path = ../MatFile_linux/bin
matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx
# SQLite
sqlite_flag = -D SLS_USE_SQLITE
sqlite_lib = -l sqlite3

# All

compiler_flag = -std=c++11 -Wall -fp-model precise -fp-model except -qopenmp -Qoption,cpp,--extended_float_type -g

flags = $(sqlite_flag) $(matfile_flag) $(arpack_flag) $(mkl_flag) $(gsl_flag) $(compiler_flag) $(boost_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) -D SLS_USE_INT_AS_LONG
# -qopenmp # run OpenMP in parallel mode
# -qopenmp-stubs # run OpenMP in serial mode

# WARNING: link order does matter for icpc compiler, each linked library should depend only on the ones after it, add new libs to the front
libs = $(sqlite_lib) $(matfile_lib) $(arpack_lib) $(link_mkl_dynamic_single) $(gsl_lib) $(arb_lib) $(quad_math_lib) $(boost_lib)

# file lists
test_cpp = $(shell cd test && echo *.cpp) # test/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # test/*.cpp object files (no path)

header_in = $(shell cd SLISC && echo *.h.in) # SLISC/*.h.in (no path)
gen_headers = $(header_in:.h.in=.h) # generated headers in SLISC/ (no path)
path_gen_headers = $(addprefix SLISC/,$(gen_headers)) # (with path)
cur_headers = $(shell cd SLISC && echo *.h) # current headers in SLISC/, including hand written ones (no path)
headers = $(gen_headers) $(cur_headers) # all headers (no path)
path_headers = $(addprefix SLISC/,$(headers)) # (with path)

# goal
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
