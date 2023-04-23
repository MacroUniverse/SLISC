test_fft.o: tests/test_fft.cpp tests/../SLISC/sci/fft.h \
 tests/../SLISC/sci/../dense/cut.h \
 tests/../SLISC/sci/../dense/../dense/Vec.h \
 tests/../SLISC/sci/../dense/../dense/../dense/Vbase.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../global.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../config.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../prec/quad_math.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../arith/Imag.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/str.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/sci/../dense/../dense/../dense/../str/../util/bit.h \
 tests/../SLISC/sci/../dense/../dense/Mat.h \
 tests/../SLISC/sci/../dense/../dense/Cmat.h \
 tests/../SLISC/sci/../dense/../dense/Cmat3.h \
 tests/../SLISC/sci/../dense/../dense/Cmat4.h \
 tests/../SLISC/sci/../dense/../dense/Svec.h \
 tests/../SLISC/sci/../dense/../dense/Dvec.h \
 tests/../SLISC/sci/../dense/../dense/Scmat.h \
 tests/../SLISC/sci/../dense/../dense/Scmat3.h \
 tests/../SLISC/sci/../dense/../dense/Dcmat.h \
 tests/../SLISC/sci/../dense/../dense/Jcmat3.h \
 tests/../SLISC/sci/../arith/copy.h \
 tests/../SLISC/sci/../arith/../arith/compare.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Cband.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/arith/arith1.h tests/../SLISC/arith/arith2.h \
 tests/../SLISC/arith/arith4.h
	$(opt_compiler) $(flags) -c tests/test_fft.cpp
