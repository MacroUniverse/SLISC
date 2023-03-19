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
 tests/../SLISC/sci/../arith/../arith/../sparse/../arith/scalar_arith.h \
 tests/../SLISC/sci/../arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Svec.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Scmat.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/sci/../arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/sci/../arith/../dense/cut.h tests/../SLISC/file/file.h \
 tests/../SLISC/file/../util/time.h tests/../SLISC/file/../util/linux.h \
 tests/../SLISC/file/../util/bit.h tests/../SLISC/file/../arith/arith1.h \
 tests/../SLISC/file/../str/unicode.h \
 tests/../SLISC/file/../str/utfcpp/utf8.h \
 tests/../SLISC/file/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/file/../str/utfcpp/utf8/core.h \
 tests/../SLISC/file/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/file/../algo/sort.h \
 tests/../SLISC/file/../algo/../algo/heap.h \
 tests/../SLISC/file/../algo/../algo/../util/random.h \
 tests/../SLISC/file/../algo/../algo/../util/../arith/arith2.h \
 tests/../SLISC/file/../algo/../arith/reorder.h
	$(opt_compiler) $(flags) -c tests/test_odeint.cpp
