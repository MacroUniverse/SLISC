test_gsl.o: tests/test_gsl.cpp tests/../SLISC/arith/arith2.h \
 tests/../SLISC/arith/../arith/scalar_arith.h \
 tests/../SLISC/arith/../arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../arith/../arith/../global.h \
 tests/../SLISC/arith/../arith/../arith/../config.h \
 tests/../SLISC/arith/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/arith/../arith/../arith/Imag.h \
 tests/../SLISC/arith/../arith/compare.h \
 tests/../SLISC/arith/../arith/../dense/Vec.h \
 tests/../SLISC/arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../util/bit.h \
 tests/../SLISC/arith/../arith/../dense/Mat.h \
 tests/../SLISC/arith/../arith/../dense/Mat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat.h \
 tests/../SLISC/arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/arith/../arith/../sparse/Cband.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/arith/../arith/../dense/Svec.h \
 tests/../SLISC/arith/../arith/../dense/Scmat.h \
 tests/../SLISC/arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/arith/../arith/../dense/Jcmat3.h
	$(opt_compiler) $(flags) -c tests/test_gsl.cpp
