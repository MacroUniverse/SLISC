# this file is auto generated with Makefile and g++
test_lanczos.o: tests/test_lanczos.cpp tests/../SLISC/tdse/lanczos.h \
 tests/../SLISC/tdse/../global.h tests/../SLISC/tdse/../config.h \
 tests/../SLISC/tdse/../prec/quad_math_declare.h \
 tests/../SLISC/tdse/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_lanczos.cpp
