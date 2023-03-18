test_global.o: test/test_global.cpp test/../SLISC/global.h \
 test/../SLISC/config.h test/../SLISC/prec/quad_math_declare.h \
 test/../SLISC/prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
