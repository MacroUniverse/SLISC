test_bisection.o: test/test_bisection.cpp test/../SLISC/algo/bisection.h \
 test/../SLISC/algo/../global.h test/../SLISC/algo/../config.h \
 test/../SLISC/algo/../prec/quad_math_declare.h \
 test/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
