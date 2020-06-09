# Makefile

exe = main.x

compiler = icpc

gsl_dir = /thummscratch/Hongyu/gsl/
link_gsl = -L $(gsl_dir)lib/ -lgsl

compile_flags = -std=c++11 -Wall -I${MKLROOT}/include -I $(gsl_dir)include/  -fp-model precise -fp-model except -qopenmp -O3 -D NDEBUG -D SLS_USE_GSL -D SLS_USE_MKL
# -g # debug
# -qopenmp # run OpenMP in parallel mode
# -qopenmp-stubs # run OpenMP in serial mode
# -fp-model # floating point model

link_mkl_static = -static -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl

link_mkl_dynamic = -lpthread -lm -ldl

# goal
goal: clean main.o
	$(compiler) $(compile_flags) -o $(exe) main.o test_*.o $(link_gsl) $(link_mkl_static)

main.o: main.cpp
	$(compiler) $(compile_flags) -c main.cpp test/*.cpp

h:
	cd ../ && octave --no-window-system auto_gen.m && cd -

clean:
	rm -f *.o *.x *.gch
