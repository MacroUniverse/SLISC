# this file is auto generated with Makefile and g++
tests/bit.o: tests/bit.cpp tests/../SLISC/util/bit.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/bit.cpp -o tests/bit.o
