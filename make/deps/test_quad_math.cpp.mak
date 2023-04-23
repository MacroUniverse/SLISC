test_quad_math.o: tests/test_quad_math.cpp tests/../SLISC/dense/Cmat.h \
 tests/../SLISC/dense/../dense/Vbase.h \
 tests/../SLISC/dense/../dense/../global.h \
 tests/../SLISC/dense/../dense/../config.h \
 tests/../SLISC/dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/dense/../dense/../prec/quad_math.h \
 tests/../SLISC/dense/../dense/../arith/Imag.h \
 tests/../SLISC/dense/../dense/../str/str.h \
 tests/../SLISC/dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/dense/../dense/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/dense/../dense/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/dense/../dense/../str/../util/bit.h \
 tests/../SLISC/util/random.h tests/../SLISC/util/../arith/arith2.h \
 tests/../SLISC/util/../arith/../arith/compare.h \
 tests/../SLISC/util/../arith/../arith/../dense/Vec.h \
 tests/../SLISC/util/../arith/../arith/../dense/Mat.h \
 tests/../SLISC/util/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/util/../arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/util/../arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/util/../arith/../arith/../sparse/Cband.h \
 tests/../SLISC/util/../arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/util/../arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/util/../arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/util/../arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/util/../arith/../arith/../dense/Svec.h \
 tests/../SLISC/util/../arith/../arith/../dense/Scmat.h \
 tests/../SLISC/util/../arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/util/../arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/util/../util/STL_util.h
	$(opt_compiler) $(flags) -c tests/test_quad_math.cpp
