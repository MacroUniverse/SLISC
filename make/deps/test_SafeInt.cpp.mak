test_SafeInt.o: tests/test_SafeInt.cpp tests/../SLISC/arith/SafeInt.h
	$(opt_compiler) $(flags) -c tests/test_SafeInt.cpp
