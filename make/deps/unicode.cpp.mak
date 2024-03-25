# this file is auto generated with Makefile and g++
tests/unicode.o: tests/unicode.cpp tests/../SLISC/str/unicode.h \
 tests/../SLISC/str/../arith/scalar_arith.h \
 tests/../SLISC/str/../arith/../arith/fp_arith.h \
 tests/../SLISC/str/../arith/../arith/../util/bit.h \
 tests/../SLISC/str/../arith/../arith/../util/../global.h \
 tests/../SLISC/str/../arith/../arith/../util/../config.h \
 tests/../SLISC/str/../arith/../arith/../util/../prec/quad_math_declare.h \
 tests/../SLISC/str/../arith/../arith/../util/../prec/quad_math.h \
 tests/../SLISC/str/../arith/../arith/complex_arith.h \
 tests/../SLISC/str/../arith/../arith/Imag.h \
 tests/../SLISC/str/utfcpp/utf8.h \
 tests/../SLISC/str/utfcpp/utf8/checked.h \
 tests/../SLISC/str/utfcpp/utf8/core.h \
 tests/../SLISC/str/utfcpp/utf8/cpp11.h \
 tests/../SLISC/str/utfcpp/utf8/checked.h \
 tests/../SLISC/str/utfcpp/utf8/unchecked.h
	$(opt_compiler) $(all_flags) -c tests/unicode.cpp -o tests/unicode.o
