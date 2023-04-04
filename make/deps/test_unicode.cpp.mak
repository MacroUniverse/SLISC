test_unicode.o: tests/test_unicode.cpp tests/../SLISC/str/unicode.h \
 tests/../SLISC/str/../arith/scalar_arith.h \
 tests/../SLISC/str/../arith/../arith/complex_arith.h \
 tests/../SLISC/str/../arith/../arith/../global.h \
 tests/../SLISC/str/../arith/../arith/../config.h \
 tests/../SLISC/str/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/str/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/str/../arith/../arith/Imag.h \
 tests/../SLISC/str/utfcpp/utf8.h \
 tests/../SLISC/str/utfcpp/utf8/checked.h \
 tests/../SLISC/str/utfcpp/utf8/core.h \
 tests/../SLISC/str/utfcpp/utf8/unchecked.h
	$(opt_compiler) $(flags) -c tests/test_unicode.cpp
