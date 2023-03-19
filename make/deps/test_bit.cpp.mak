test_bit.o: tests/test_bit.cpp tests/../SLISC/util/bit.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_bit.cpp
