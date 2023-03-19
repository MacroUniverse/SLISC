test_cpp11.o: test/test_cpp11.cpp make/deps/test_cpp11.cpp.mak
	$(opt_compiler) $(flags) -c test/test_cpp11.cpp
