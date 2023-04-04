test_Vbase.o: tests/test_Vbase.cpp tests/../SLISC/dense/Vbase.h \
 tests/../SLISC/dense/../global.h tests/../SLISC/dense/../config.h \
 tests/../SLISC/dense/../prec/quad_math_declare.h \
 tests/../SLISC/dense/../prec/quad_math.h \
 tests/../SLISC/dense/../arith/Imag.h tests/../SLISC/dense/../str/str.h \
 tests/../SLISC/dense/../str/../str/unicode.h \
 tests/../SLISC/dense/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/dense/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/dense/../str/../str/utfcpp/utf8/unchecked.h
	$(opt_compiler) $(flags) -c tests/test_Vbase.cpp
