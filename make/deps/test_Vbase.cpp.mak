test_Vbase.o: tests/test_Vbase.cpp tests/../SLISC/dense/Vbase.h \
 tests/../SLISC/dense/../global.h tests/../SLISC/dense/../config.h \
 tests/../SLISC/dense/../prec/quad_math_declare.h \
 tests/../SLISC/dense/../prec/quad_math.h \
 tests/../SLISC/dense/../arith/Imag.h tests/../SLISC/dense/../str/str.h
	$(opt_compiler) $(flags) -c tests/test_Vbase.cpp
