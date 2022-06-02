# Makefile

compiler = icpc

gsl_dir = /thummscratch/Hongyu/gsl/

flags = -std=c++11 -Wall -I${MKLROOT}/include -I $(gsl_dir)include/  -fp-model precise -fp-model except -qopenmp -Qoption,cpp,--extended_float_type -I ../boost-headers -O3 -D NDEBUG -D SLS_USE_GSL -D SLS_USE_MKL -D SLS_USE_ARB -D SLS_USE_QUAD_MATH
# -g # debug
# -qopenmp # run OpenMP in parallel mode
# -qopenmp-stubs # run OpenMP in serial mode
# -fp-model # floating point model
# -D SLS_USE_BOOST

link_mkl_static = -static -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl

link_mkl_dynamic = -lpthread -lm -ldl  

other_libs = -L $(gsl_dir)lib/ -lgsl -larb -lflint -lmpfr -lgmp -lquadmath
# -lboost_system -lboost_filesystem

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
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC' '../test'})"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(link_mkl_static) $(other_libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp
	$(compiler) $(flags) -c main.cpp test/*.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen ../SLISC $$(basename $<)"
