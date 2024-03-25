# this file is auto generated with Makefile and g++
tests/SafeInt.o: tests/SafeInt.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h tests/../SLISC/arith/SafeInt.h
	$(opt_compiler) $(all_flags) -c tests/SafeInt.cpp -o tests/SafeInt.o
