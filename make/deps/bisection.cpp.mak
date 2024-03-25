# this file is auto generated with Makefile and g++
tests/bisection.o: tests/bisection.cpp tests/../SLISC/algo/bisection.h \
 tests/../SLISC/algo/../global.h tests/../SLISC/algo/../config.h \
 tests/../SLISC/algo/../prec/quad_math_declare.h \
 tests/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/bisection.cpp -o tests/bisection.o
