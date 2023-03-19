test_SafeInt.o: test/test_SafeInt.cpp make/deps/test_SafeInt.cpp.mak \
 test/../SLISC/arith/SafeInt.h
	$(opt_compiler) $(flags) -c test/test_SafeInt.cpp
