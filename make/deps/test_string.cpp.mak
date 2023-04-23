test_string.o: tests/test_string.cpp tests/../SLISC/str/str.h \
 tests/../SLISC/str/../str/unicode.h \
 tests/../SLISC/str/../str/../arith/scalar_arith.h \
 tests/../SLISC/str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/str/../str/../arith/../arith/../global.h \
 tests/../SLISC/str/../str/../arith/../arith/../config.h \
 tests/../SLISC/str/../str/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/str/../str/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/str/../str/../arith/../arith/Imag.h \
 tests/../SLISC/str/../str/utfcpp/utf8.h \
 tests/../SLISC/str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/str/../util/bit.h
	$(opt_compiler) $(flags) -c tests/test_string.cpp
