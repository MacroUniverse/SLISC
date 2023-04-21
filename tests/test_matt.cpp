#include "../SLISC/arith/arith4.h"
#include "../SLISC/file/matt.h"
#include "../SLISC/util/random.h"

void test_matt()
{
#if !(defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__) || defined(__MSYS__))
	using namespace slisc;

	// write to file
	Matt matt;
	if (file_exist("test.matt"))
		remove("test.matt");
	matt.open("test.matt", "w");
	Doub s(3.14159265358979323);
	Comp sc(s, -s);
	save(sc, "sc", matt);
	matt.close();

	// read test

	// scalars
	matt.open("test.matt", "r");
	Comp r_sc;
	load(r_sc, "sc", matt);
	if (abs(r_sc-sc) > 1e-14)
    {
        cout << "sc = " << sc << endl;
        cout << "r_sc = " << r_sc << endl;
        SLS_FAIL;
    }
	matt.close();
#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
