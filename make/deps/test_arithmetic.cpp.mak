test_arithmetic.o: tests/test_arithmetic.cpp \
 tests/../SLISC/arith/arith1.h \
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
 tests/../SLISC/arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/arith/arith2.h tests/../SLISC/arith/arith4.h \
 tests/../SLISC/lin/mul.h tests/../SLISC/lin/../arith/copy.h \
 tests/../SLISC/lin/../arith/../dense/cut.h tests/../SLISC/util/random.h \
 tests/../SLISC/util/../util/STL_util.h tests/../SLISC/algo/sort.h \
 tests/../SLISC/algo/../str/unicode.h \
 tests/../SLISC/algo/../str/utfcpp/utf8.h \
 tests/../SLISC/algo/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/algo/../str/utfcpp/utf8/core.h \
 tests/../SLISC/algo/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/algo/../algo/heap.h \
 tests/../SLISC/algo/../arith/reorder.h
	$(opt_compiler) $(flags) -c tests/test_arithmetic.cpp