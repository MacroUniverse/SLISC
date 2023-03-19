test_unicode.o: test/test_unicode.cpp make/deps/test_unicode.cpp.mak \
 test/../SLISC/str/unicode.h test/../SLISC/str/../arith/scalar_arith.h \
 test/../SLISC/str/../arith/../arith/complex_arith.h \
 test/../SLISC/str/../arith/../arith/../global.h \
 test/../SLISC/str/../arith/../arith/../config.h \
 test/../SLISC/str/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/str/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/str/../arith/../arith/Imag.h \
 test/../SLISC/str/../str/str.h test/../SLISC/str/utfcpp/utf8.h \
 test/../SLISC/str/utfcpp/utf8/checked.h \
 test/../SLISC/str/utfcpp/utf8/core.h \
 test/../SLISC/str/utfcpp/utf8/unchecked.h
	$(opt_compiler) $(flags) -c test/test_unicode.cpp
