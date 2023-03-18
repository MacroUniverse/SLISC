test_disp.o: test/test_disp.cpp test/../SLISC/str/disp.h \
 test/../SLISC/str/../arith/arith1.h \
 test/../SLISC/str/../arith/../arith/scalar_arith.h \
 test/../SLISC/str/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/str/../arith/../arith/../arith/../global.h \
 test/../SLISC/str/../arith/../arith/../arith/../config.h \
 test/../SLISC/str/../arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/str/../arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/str/../arith/../arith/../arith/Imag.h \
 test/../SLISC/str/../arith/../arith/compare.h \
 test/../SLISC/str/../arith/../arith/../dense/Vec.h \
 test/../SLISC/str/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/str/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/str/../arith/../arith/../dense/Mat.h \
 test/../SLISC/str/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/str/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/str/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/str/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/str/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/str/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/str/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/str/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/str/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/str/../arith/../arith/../dense/Svec.h \
 test/../SLISC/str/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/str/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/str/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/str/../str/unicode.h \
 test/../SLISC/str/../str/utfcpp/utf8.h \
 test/../SLISC/str/../str/utfcpp/utf8/checked.h \
 test/../SLISC/str/../str/utfcpp/utf8/core.h \
 test/../SLISC/str/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/arith/arith2.h
	$(opt_compiler) $(flags) -c $<
