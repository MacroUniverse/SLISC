test_bisection.o: test/test_bisection.cpp \
 make/deps/test_bisection.cpp.mak test/../SLISC/algo/bisection.h \
 test/../SLISC/algo/../global.h test/../SLISC/algo/../config.h \
 test/../SLISC/algo/../prec/quad_math_declare.h \
 test/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_bisection.cpp
