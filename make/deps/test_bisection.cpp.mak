test_bisection.o: tests/test_bisection.cpp \
 tests/../SLISC/algo/bisection.h tests/../SLISC/algo/../global.h \
 tests/../SLISC/algo/../config.h \
 tests/../SLISC/algo/../prec/quad_math_declare.h \
 tests/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_bisection.cpp
