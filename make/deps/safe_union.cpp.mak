# this file is auto generated with Makefile and g++
tests/safe_union.o: tests/safe_union.cpp tests/../SLISC/util/safe_union.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/safe_union.cpp -o tests/safe_union.o
