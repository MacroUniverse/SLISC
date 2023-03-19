test_expokit.o: test/test_expokit.cpp make/deps/test_expokit.cpp.mak \
 test/../SLISC/lin/expokit.h test/../SLISC/lin/../global.h \
 test/../SLISC/lin/../config.h \
 test/../SLISC/lin/../prec/quad_math_declare.h \
 test/../SLISC/lin/../prec/quad_math.h test/../SLISC/lin/mat_fun.h \
 test/../SLISC/lin/../sparse/sparse_arith.h \
 test/../SLISC/lin/../sparse/../arith/arith1.h \
 test/../SLISC/lin/../sparse/../arith/../arith/scalar_arith.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../arith/Imag.h \
 test/../SLISC/lin/../sparse/../arith/../arith/compare.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Vec.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Mat.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Svec.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/lin/../sparse/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/lin/../sparse/../arith/arith4.h \
 test/../SLISC/lin/../sparse/../arith/copy.h \
 test/../SLISC/lin/../sparse/../arith/../dense/cut.h \
 test/../SLISC/lin/../sparse/../algo/sort.h \
 test/../SLISC/lin/../sparse/../algo/../str/unicode.h \
 test/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8.h \
 test/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/checked.h \
 test/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/core.h \
 test/../SLISC/lin/../sparse/../algo/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/lin/../sparse/../algo/../algo/heap.h \
 test/../SLISC/lin/../sparse/../algo/../algo/../util/random.h \
 test/../SLISC/lin/../sparse/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/lin/../sparse/../algo/../arith/reorder.h \
 test/../SLISC/lin/../sparse/../sparse/Diag.h \
 test/../SLISC/lin/../lin/eig.h test/../SLISC/lin/../lin/mul.h
	$(opt_compiler) $(flags) -c test/test_expokit.cpp
