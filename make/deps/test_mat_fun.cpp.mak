test_mat_fun.o: tests/test_mat_fun.cpp tests/../SLISC/lin/mat_fun.h \
 tests/../SLISC/lin/../sparse/sparse_arith.h \
 tests/../SLISC/lin/../sparse/../arith/arith1.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/scalar_arith.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/complex_arith.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/../global.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/../config.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../arith/Imag.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/compare.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Vec.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Mat.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../sparse/Cband.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Svec.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Scmat.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/lin/../sparse/../arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/lin/../sparse/../arith/arith4.h \
 tests/../SLISC/lin/../sparse/../arith/copy.h \
 tests/../SLISC/lin/../sparse/../arith/../dense/cut.h \
 tests/../SLISC/lin/../sparse/../algo/sort.h \
 tests/../SLISC/lin/../sparse/../algo/../str/unicode.h \
 tests/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8.h \
 tests/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/core.h \
 tests/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/lin/../sparse/../algo/../algo/heap.h \
 tests/../SLISC/lin/../sparse/../algo/../algo/../util/random.h \
 tests/../SLISC/lin/../sparse/../algo/../algo/../util/../arith/arith2.h \
 tests/../SLISC/lin/../sparse/../algo/../algo/../util/../util/STL_util.h \
 tests/../SLISC/lin/../sparse/../algo/../arith/reorder.h \
 tests/../SLISC/lin/../sparse/../sparse/Diag.h \
 tests/../SLISC/lin/../lin/eig.h tests/../SLISC/lin/../lin/mul.h
	$(opt_compiler) $(flags) -c tests/test_mat_fun.cpp