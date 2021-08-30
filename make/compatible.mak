# No external dependency at all
# requires g++8.3 or higher

compiler = g++

flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp -g -fmax-errors=1

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
	$(compiler) $(flags) -o main.x main.o test_*.o

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: $(path_headers) main.cpp
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "auto_gen $<"
