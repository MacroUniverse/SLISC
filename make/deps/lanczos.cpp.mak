# this file is auto generated with Makefile and g++
tests/lanczos.o: tests/lanczos.cpp tests/../SLISC/tdse/lanczos.h \
 tests/../SLISC/tdse/../global.h tests/../SLISC/tdse/../config.h \
 tests/../SLISC/tdse/../prec/quad_math_declare.h \
 tests/../SLISC/tdse/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/lanczos.cpp -o tests/lanczos.o
