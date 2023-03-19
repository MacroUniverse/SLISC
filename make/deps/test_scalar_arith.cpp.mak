test_scalar_arith.o: tests/test_scalar_arith.cpp \
 tests/../SLISC/arith/scalar_arith.h \
 tests/../SLISC/arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../arith/../global.h \
 tests/../SLISC/arith/../arith/../config.h \
 tests/../SLISC/arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../arith/../prec/quad_math.h \
 tests/../SLISC/arith/../arith/Imag.h tests/../SLISC/util/STL_util.h
	$(opt_compiler) $(flags) -c tests/test_scalar_arith.cpp
