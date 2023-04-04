test_hypergeom.o: tests/test_hypergeom.cpp \
 tests/../SLISC/spec/hypergeom.h tests/../SLISC/spec/../str/str.h \
 tests/../SLISC/spec/../str/../str/unicode.h \
 tests/../SLISC/spec/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/../global.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/../config.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/spec/../str/../str/../arith/../arith/Imag.h \
 tests/../SLISC/spec/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/spec/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/spec/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/spec/../str/../str/utfcpp/utf8/unchecked.h
	$(opt_compiler) $(flags) -c tests/test_hypergeom.cpp
