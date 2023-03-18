test_json.o: test/test_json.cpp test/../SLISC/util/json.h \
 test/../SLISC/file/file.h test/../SLISC/file/../global.h \
 test/../SLISC/file/../config.h \
 test/../SLISC/file/../prec/quad_math_declare.h \
 test/../SLISC/file/../prec/quad_math.h test/../SLISC/file/../util/time.h \
 test/../SLISC/file/../util/../str/str.h \
 test/../SLISC/file/../util/linux.h test/../SLISC/file/../util/bit.h \
 test/../SLISC/file/../arith/arith1.h \
 test/../SLISC/file/../arith/../arith/scalar_arith.h \
 test/../SLISC/file/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/file/../arith/../arith/../arith/Imag.h \
 test/../SLISC/file/../arith/../arith/compare.h \
 test/../SLISC/file/../arith/../arith/../dense/Vec.h \
 test/../SLISC/file/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/file/../arith/../arith/../dense/Mat.h \
 test/../SLISC/file/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/file/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/file/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/file/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/file/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/file/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/file/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/file/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/file/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/file/../arith/../arith/../dense/Svec.h \
 test/../SLISC/file/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/file/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/file/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/file/../str/unicode.h \
 test/../SLISC/file/../str/utfcpp/utf8.h \
 test/../SLISC/file/../str/utfcpp/utf8/checked.h \
 test/../SLISC/file/../str/utfcpp/utf8/core.h \
 test/../SLISC/file/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/file/../algo/sort.h \
 test/../SLISC/file/../algo/../algo/heap.h \
 test/../SLISC/file/../algo/../algo/../util/random.h \
 test/../SLISC/file/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/file/../algo/../arith/reorder.h \
 test/../SLISC/file/../algo/../arith/../arith/copy.h \
 test/../SLISC/file/../algo/../arith/../arith/../dense/cut.h
	$(opt_compiler) $(flags) -c $<
