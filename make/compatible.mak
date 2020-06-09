# No external dependency at all

flags = -Wall -Wno-reorder -fopenmp -g -fmax-errors=1

compiler = g++

# link
# choose `$(mkl_dyn_link)` or `$(mkl_stat_link)`
goal:main.o
	$(compiler) $(flags) -o main.x main.o test_*.o

# compile
main.o:main.cpp
	$(compiler) $(flags) -std=c++11 -c main.cpp test/*.cpp

h:
	octave --no-window-system auto_gen.m

clean:
	rm -f *.o *.x
