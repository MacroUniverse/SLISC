test_ylm.o: test/test_ylm.cpp test/../SLISC/spec/ylm.h \
 test/../SLISC/spec/../str/unicode.h \
 test/../SLISC/spec/../str/../arith/scalar_arith.h \
 test/../SLISC/spec/../str/../arith/../arith/complex_arith.h \
 test/../SLISC/spec/../str/../arith/../arith/../global.h \
 test/../SLISC/spec/../str/../arith/../arith/../config.h \
 test/../SLISC/spec/../str/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/spec/../str/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/spec/../str/../arith/../arith/Imag.h \
 test/../SLISC/spec/../str/../str/str.h \
 test/../SLISC/spec/../str/utfcpp/utf8.h \
 test/../SLISC/spec/../str/utfcpp/utf8/checked.h \
 test/../SLISC/spec/../str/utfcpp/utf8/core.h \
 test/../SLISC/spec/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/spec/../spec/legendreP.h \
 test/../SLISC/spec/../spec/anglib.h
	$(opt_compiler) $(flags) -c $<
