test_arb.o: test/test_arb.cpp make/deps/test_arb.cpp.mak
	$(opt_compiler) $(flags) -c test/test_arb.cpp
