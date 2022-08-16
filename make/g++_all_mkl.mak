# use g++ with MKL

# reference: MKL link advisor https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor

compiler = g++

# MKL
mkl_stat_link = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl

# mkl_dyn_link = -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl

mkl_compile =  -m64 -I${MKLROOT}/include

# GSL
gsl_flag = -D SLS_USE_GSL
gsl_lib = -lgsl
# Arb
arb_flag = -D SLS_USE_ARB -I /usr/include/flint
arb_lib = -lflint -lflint-arb
# Arpack
arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include
arpack_lib = -larpack -lgfortran
# Boost
boost_flag = -D SLS_USE_BOOST -I ../boost-headers
boost_lib = 

libs = $(gsl_lib) $(arb_lib) $(arpack_lib) $(mkl_stat_link) # -lquadmath
# -lboost_system -lboost_filesystem

flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -O3 -fmax-errors=1 -fext-numeric-literals  -D SLS_USE_MKL $(mkl_compile) $(gsl_flag) $(arb_flag) $(arpack_flag) -D SLS_USE_INT_AS_LONG -D NDEBUG  # -D SLS_USE_QUAD_MATH

# file lists
test_cpp = $(shell cd test && echo *.cpp) # test/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # test/*.cpp object files (no path)

header_in = $(shell cd SLISC && echo *.h.in) # SLISC/*.h.in (no path)
gen_headers = $(header_in:.h.in=.h) # generated headers in SLISC/ (no path)
path_gen_headers = $(addprefix SLISC/,$(gen_headers)) # (with path)
cur_headers = $(shell cd SLISC && echo *.h) # current headers in SLISC/, including hand written ones (no path)
headers = $(gen_headers) $(cur_headers) # all headers (no path)
path_headers = $(addprefix SLISC/,$(headers)) # (with path)

# link
goal: main.x

main.x: main.o $(test_o)
	make link

h: # remake all headers
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC' '../test'})"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

goal:main.o
	g++ $(flags) -o main.x main.o test_*.o $(libs)

main.o: $(path_headers) main.cpp
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen ../SLISC $$(basename $<)"
