test_input.o: test/test_input.cpp test/../SLISC/util/input.h \
 test/../SLISC/util/../global.h test/../SLISC/util/../config.h \
 test/../SLISC/util/../prec/quad_math_declare.h \
 test/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
