test_sing_list.o: test/test_sing_list.cpp test/../SLISC/algo/sing_list.h \
 test/../SLISC/algo/../util/random.h \
 test/../SLISC/algo/../util/../arith/arith2.h \
 test/../SLISC/algo/../util/../arith/../arith/scalar_arith.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/../global.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/../config.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/algo/../util/../arith/../arith/../arith/Imag.h \
 test/../SLISC/algo/../util/../arith/../arith/compare.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Vec.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Mat.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/algo/../util/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/algo/../util/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/algo/../util/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/algo/../util/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/algo/../util/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Svec.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/algo/../util/../arith/../arith/../dense/Jcmat3.h
	$(opt_compiler) $(flags) -c $<
