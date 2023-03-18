test_complex_arith.o: test/test_complex_arith.cpp \
 test/../SLISC/arith/complex_arith.h test/../SLISC/arith/../global.h \
 test/../SLISC/arith/../config.h \
 test/../SLISC/arith/../prec/quad_math_declare.h \
 test/../SLISC/arith/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
