test_time.o: tests/test_time.cpp tests/../SLISC/util/time.h \
 tests/../SLISC/util/../str/str.h \
 tests/../SLISC/util/../str/../str/unicode.h \
 tests/../SLISC/util/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/../global.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/../config.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/util/../str/../str/../arith/../arith/Imag.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/util/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/util/../str/../util/bit.h
	$(opt_compiler) $(flags) -c tests/test_time.cpp
