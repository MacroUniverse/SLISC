# use g++ with libgsl-dev libblas-dev liblapacke-dev (all available from apt-get)
# use `dpkg -L dpkg -L lib***` to check the installation directory

libs = -lgsl -llapacke -lblas

flags = -Wall -Wno-reorder -fopenmp -g -fmax-errors=1 -D SLS_USE_CBLAS -D SLS_USE_LAPACKE -D SLS_USE_GSL

compiler = g++

# link
# choose `$(mkl_dyn_link)` or `$(mkl_stat_link)`
# strange, order of *.o files doesn't matter?
goal:main.o
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

# compile
main.o:main.cpp
	$(compiler) $(flags) -std=c++11 -c main.cpp test/*.cpp

inl:
	octave auto_gen.m

clean:
	rm -f *.o *.x
