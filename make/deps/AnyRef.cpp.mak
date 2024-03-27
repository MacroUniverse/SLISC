# this file is auto generated with Makefile and g++
tests/AnyRef.o: tests/AnyRef.cpp tests/../SLISC/util/AnyRef.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/AnyRef.cpp -o tests/AnyRef.o
