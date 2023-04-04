test_ylm.o: tests/test_ylm.cpp tests/../SLISC/spec/ylm.h \
 tests/../SLISC/spec/../str/unicode.h \
 tests/../SLISC/spec/../str/../arith/scalar_arith.h \
 tests/../SLISC/spec/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/spec/../str/../arith/../arith/../global.h \
 tests/../SLISC/spec/../str/../arith/../arith/../config.h \
 tests/../SLISC/spec/../str/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/spec/../str/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/spec/../str/../arith/../arith/Imag.h \
 tests/../SLISC/spec/../str/utfcpp/utf8.h \
 tests/../SLISC/spec/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/spec/../str/utfcpp/utf8/core.h \
 tests/../SLISC/spec/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/spec/../spec/legendreP.h \
 tests/../SLISC/spec/../spec/anglib.h
	$(opt_compiler) $(flags) -c tests/test_ylm.cpp
