test_boost.o: tests/test_boost.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_boost.cpp
