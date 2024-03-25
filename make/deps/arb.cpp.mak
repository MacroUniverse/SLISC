# this file is auto generated with Makefile and g++
tests/arb.o: tests/arb.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/arb.cpp -o tests/arb.o
