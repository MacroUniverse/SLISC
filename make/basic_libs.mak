# use g++ with libgsl-dev libblas-dev liblapacke-dev (all available from apt-get)
# use `dpkg -L dpkg -L lib***` to check the installation directory

# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

compiler = g++

libs = -lgsl -llapacke -lblas

flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -g -fmax-errors=1 -D SLS_USE_CBLAS -D SLS_USE_LAPACKE -D SLS_USE_GSL

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

h: $(path_gen_headers) # update headers only

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: $(path_headers) main.cpp
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --eval "auto_gen $<"
