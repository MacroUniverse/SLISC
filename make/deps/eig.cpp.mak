# this file is auto generated with Makefile and g++
tests/eig.o: tests/eig.cpp tests/../SLISC/lin/eig.h \
 tests/../SLISC/lin/../arith/copy.h \
 tests/../SLISC/lin/../arith/../arith/compare.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Vec.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/Imag.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/../global.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/../config.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/../prec/quad_math.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/../arith/scalar_arith.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/../arith/../arith/fp_arith.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/../arith/../arith/../util/bit.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/../arith/../arith/complex_arith.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/cpp11.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/Svec.h \
 tests/../SLISC/lin/../arith/../arith/../dense/../dense/../dense/Svbase.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Mat.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Mat3.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Cmat.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Scmat.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Scmat4.h \
 tests/../SLISC/lin/../arith/../arith/../sparse/Cband.h \
 tests/../SLISC/lin/../arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/lin/../arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/lin/../arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/lin/../arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/lin/../arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/lin/../arith/../dense/cut.h \
 tests/../SLISC/sparse/sparse_arith.h \
 tests/../SLISC/sparse/../arith/arith1.h \
 tests/../SLISC/sparse/../arith/arith4.h \
 tests/../SLISC/sparse/../algo/sort.h \
 tests/../SLISC/sparse/../algo/../algo/heap.h \
 tests/../SLISC/sparse/../algo/../algo/../util/random.h \
 tests/../SLISC/sparse/../algo/../algo/../util/../arith/arith2.h \
 tests/../SLISC/sparse/../algo/../algo/../util/../util/STL_util.h \
 tests/../SLISC/sparse/../algo/../arith/reorder.h \
 tests/../SLISC/sparse/../sparse/Diag.h tests/../SLISC/lin/mul.h
	$(opt_compiler) $(all_flags) -c tests/eig.cpp -o tests/eig.o
