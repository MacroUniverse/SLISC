test_boost.o: test/test_boost.cpp make/deps/test_boost.cpp.mak
	$(opt_compiler) $(flags) -c test/test_boost.cpp
