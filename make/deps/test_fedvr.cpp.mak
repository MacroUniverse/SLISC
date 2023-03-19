test_fedvr.o: test/test_fedvr.cpp make/deps/test_fedvr.cpp.mak \
 test/../SLISC/lin/eig.h test/../SLISC/lin/../arith/copy.h \
 test/../SLISC/lin/../arith/../arith/compare.h \
 test/../SLISC/lin/../arith/../arith/../dense/Vec.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../global.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../config.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../arith/Imag.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/lin/../arith/../arith/../dense/Mat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/lin/../arith/../arith/../dense/Svec.h \
 test/../SLISC/lin/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/lin/../arith/../dense/cut.h test/../SLISC/tdse/fedvr.h \
 test/../SLISC/tdse/../sparse/sparse_arith.h \
 test/../SLISC/tdse/../sparse/../arith/arith1.h \
 test/../SLISC/tdse/../sparse/../arith/arith4.h \
 test/../SLISC/tdse/../sparse/../algo/sort.h \
 test/../SLISC/tdse/../sparse/../algo/../str/unicode.h \
 test/../SLISC/tdse/../sparse/../algo/../str/utfcpp/utf8.h \
 test/../SLISC/tdse/../sparse/../algo/../str/utfcpp/utf8/checked.h \
 test/../SLISC/tdse/../sparse/../algo/../str/utfcpp/utf8/core.h \
 test/../SLISC/tdse/../sparse/../algo/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/tdse/../sparse/../algo/../algo/heap.h \
 test/../SLISC/tdse/../sparse/../algo/../algo/../util/random.h \
 test/../SLISC/tdse/../sparse/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/tdse/../sparse/../algo/../arith/reorder.h \
 test/../SLISC/tdse/../sparse/../sparse/Diag.h \
 test/../SLISC/tdse/../sci/interp1.h test/../SLISC/tdse/../algo/search.h \
 test/../SLISC/tdse/../spec/legendreP.h
	$(opt_compiler) $(flags) -c test/test_fedvr.cpp
