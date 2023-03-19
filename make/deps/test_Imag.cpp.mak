test_Imag.o: tests/test_Imag.cpp tests/../SLISC/arith/Imag.h \
 tests/../SLISC/arith/../global.h tests/../SLISC/arith/../config.h \
 tests/../SLISC/arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_Imag.cpp
