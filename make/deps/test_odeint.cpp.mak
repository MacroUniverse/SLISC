# this file is auto generated with Makefile and g++
test_odeint.o: tests/test_odeint.cpp tests/../SLISC/sci/odeint.h \
 tests/../SLISC/sci/../arith/copy.h \
 tests/../SLISC/sci/../arith/../arith/compare.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Vec.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../global.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../config.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../prec/quad_math.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../arith/Imag.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/sci/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Mat.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Cmat.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Cband.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Svec.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Scmat.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/sci/../arith/../dense/cut.h \
 tests/../SLISC/arith/reorder.h tests/../SLISC/arith/../arith/arith2.h
	$(opt_compiler) $(flags) -c tests/test_odeint.cpp
