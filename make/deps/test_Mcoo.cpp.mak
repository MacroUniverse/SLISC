test_Mcoo.o: test/test_Mcoo.cpp test/../SLISC/sparse/sparse_arith.h \
 test/../SLISC/sparse/../arith/arith1.h \
 test/../SLISC/sparse/../arith/../arith/scalar_arith.h \
 test/../SLISC/sparse/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/sparse/../arith/../arith/../arith/../global.h \
 test/../SLISC/sparse/../arith/../arith/../arith/../config.h \
 test/../SLISC/sparse/../arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/sparse/../arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/sparse/../arith/../arith/../arith/Imag.h \
 test/../SLISC/sparse/../arith/../arith/compare.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Vec.h \
 test/../SLISC/sparse/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/sparse/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Mat.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/sparse/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/sparse/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/sparse/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/sparse/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/sparse/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Svec.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/sparse/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/sparse/../arith/arith4.h \
 test/../SLISC/sparse/../arith/copy.h \
 test/../SLISC/sparse/../arith/../dense/cut.h \
 test/../SLISC/sparse/../algo/sort.h \
 test/../SLISC/sparse/../algo/../str/unicode.h \
 test/../SLISC/sparse/../algo/../str/utfcpp/utf8.h \
 test/../SLISC/sparse/../algo/../str/utfcpp/utf8/checked.h \
 test/../SLISC/sparse/../algo/../str/utfcpp/utf8/core.h \
 test/../SLISC/sparse/../algo/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/sparse/../algo/../algo/heap.h \
 test/../SLISC/sparse/../algo/../algo/../util/random.h \
 test/../SLISC/sparse/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/sparse/../algo/../arith/reorder.h \
 test/../SLISC/sparse/../sparse/Diag.h
	$(opt_compiler) $(flags) -c $<
