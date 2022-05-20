# use g++ with MKL

# reference: MKL link advisor https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor

compiler = g++

mkl_stat_link = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl

mkl_dyn_link = -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread -lm -ldl

mkl_compile =  -m64 -I${MKLROOT}/include

# use `sudo apt install libgsl-dev` to install GNU scientific library
# use `dpkg -L dpkg -L libgsl-dev` to check the installation directory
libs = -lgsl -llapacke -lblas -lflint -larb -lboost_system -lboost_filesystem -larpack -lgfortran -lquadmath

flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -O3 -fmax-errors=1 -fext-numeric-literals -I ../boost-headers -I ../Arpack_test/include -D SLS_USE_MKL -D SLS_USE_GSL -D SLS_USE_ARB -D SLS_USE_BOOST -D SLS_USE_ARPACK -D SLS_USE_QUAD_MATH -D NDEBUG

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
# choose `$(mkl_dyn_link)` or `$(mkl_stat_link)`
goal: main.x

main.x: main.o $(test_o)
	make link

h: $(path_gen_headers) # update headers only

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

goal:main.o
	g++ $(flags) -o main.x main.o test_*.o $(libs) $(mkl_stat_link)

main.o: $(path_headers) main.cpp
	$(compiler) $(flags) $(mkl_compile) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "auto_gen SLISC $$(basename $<)"
