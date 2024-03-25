# this file is auto generated with Makefile and g++
tests/input.o: tests/input.cpp tests/../SLISC/util/input.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/input.cpp -o tests/input.o
