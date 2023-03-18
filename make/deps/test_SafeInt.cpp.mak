test_SafeInt.o: test/test_SafeInt.cpp test/../SLISC/arith/SafeInt.h
	$(opt_compiler) $(flags) -c $<
