test_random.o: tests/test_random.cpp tests/../SLISC/util/random.h \
 tests/../SLISC/util/../arith/arith2.h \
 tests/../SLISC/util/../arith/../arith/scalar_arith.h \
 tests/../SLISC/util/../arith/../arith/../arith/complex_arith.h \
 tests/../SLISC/util/../arith/../arith/../arith/../global.h \
 tests/../SLISC/util/../arith/../arith/../arith/../config.h \
 tests/../SLISC/util/../arith/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/util/../arith/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/util/../arith/../arith/../arith/Imag.h \
 tests/../SLISC/util/../arith/../arith/compare.h \
 tests/../SLISC/util/../arith/../arith/../dense/Vec.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/util/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/util/../arith/../arith/../dense/Mat.h \
 tests/../SLISC/util/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/util/../arith/../arith/../dense/Cmat.h \
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
 tests/../SLISC/util/../util/STL_util.h tests/../SLISC/algo/search.h \
 tests/../SLISC/algo/../arith/arith1.h tests/../SLISC/algo/../dense/cut.h
	$(opt_compiler) $(flags) -c tests/test_random.cpp
