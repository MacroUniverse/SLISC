test_Cmat3.o: tests/test_Cmat3.cpp tests/../SLISC/dense/Cmat3.h \
 tests/../SLISC/dense/../dense/Vbase.h \
 tests/../SLISC/dense/../dense/../global.h \
 tests/../SLISC/dense/../dense/../config.h \
 tests/../SLISC/dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/dense/../dense/../prec/quad_math.h \
 tests/../SLISC/dense/../dense/../arith/Imag.h \
 tests/../SLISC/dense/../dense/../str/str.h
	$(opt_compiler) $(flags) -c tests/test_Cmat3.cpp
