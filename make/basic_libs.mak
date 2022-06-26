# use g++ with libgsl-dev libblas-dev liblapacke-dev (all available from apt-get)
# requires g++8.3 or higher
# use `dpkg -L dpkg -L lib***` to check the installation directory

# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

compiler = g++

# CBLAS
cblas_flag = -D SLS_USE_CBLAS
cblas_lib = -lblas
# LAPACKE
lapacke_flag = -D SLS_USE_LAPACKE
lapacke_lib = -llapacke
# Arpack
arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include
arpack_lib = -larpack -lgfortran
# GSL
gsl_flag = -D SLS_USE_GSL
gsl_lib = -lgsl
# Arb
arb_flag = -D SLS_USE_ARB -I /usr/include/flint
arb_lib = -lflint -lmpfr -lgmp -larb
# quad math
quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
quad_math_lib = -lquadmath
# Boost
boost_flag = -D SLS_USE_BOOST -I ../boost-headers
boost_lib = -lboost_system -lboost_filesystem
# Eigen
eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen
# Address Sanitizer
asan_flag = -fsanitize=address -static-libasan -D SLS_USE_ASAN
# SQLite
sqlite_flag = -D SLS_USE_SQLITE
sqlite_lib = -l sqlite3
# All
flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -g -fmax-errors=20 $(arpack_flag) $(cblas_flag) $(lapacke_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) $(sqlite_flag) #-D NDEBUG
libs = $(gsl_lib) $(lapacke_lib) $(cblas_lib) $(arb_lib) $(arpack_lib) $(quad_math_lib) $(sqlite_lib)

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
	octave --no-window-system --eval "cd preprocessor; auto_gen '../SLISC' '../test'"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen ../SLISC $$(basename $<)"
