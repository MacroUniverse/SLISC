#include <iostream>
#ifdef SLS_USE_BOOST
#include <boost/filesystem.hpp>
#include <boost/json/src.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include "../SLISC/file.h"
#endif

void test_boost()
{
#ifdef SLS_USE_BOOST
	using namespace slisc;
	// ================ file system =====================
	using boost::filesystem::file_size; using boost::filesystem::rename;
	using boost::system::error_code; using boost::filesystem::last_write_time;
	using boost::filesystem::current_path;

	Int major_ver = BOOST_VERSION / 100000,
        minor_ver = (BOOST_VERSION / 100) % 1000,
		sub_minor_ver = BOOST_VERSION % 100;
	cout << "boost version: " << major_ver << "." << minor_ver << "."
        << sub_minor_ver << endl;
	if (BOOST_VERSION < 106500)
		SLS_ERR("faild! boost version not tested");
	if (file_size("test/test_file/测试.txt") != 12)
		SLS_FAIL;
	file_copy("test/test_file/测试1.txt", "test/test_file/测试.txt", true);
	error_code ec;

	// If old_p and new_p resolve to the same existing file, no action is taken.
	// otherwise, if new_p resolves to an existing non-directory file, it is removed.
	// if new_p resolves to an existing directory, it is removed if empty on ISO/IEC 9945 but is an error on Windows.
	// A symbolic link is itself renamed, rather than the file it resolves to being renamed.
	file_remove("测试1.txt");
	rename("test/test_file/测试1.txt", "测试1.txt");
	if (!file_exist("测试1.txt"))
		SLS_FAIL;
	
	// last_write_time
	Long t = last_write_time("测试1.txt"); // return an integer of POSIX time
	Long t1 = time(NULL);
	if (abs(t - t1) > 1)
		SLS_FAIL;

	file_remove("测试1.txt");

	// current path (pwd)
	Str path = current_path().string();
	if (path.substr(path.size()-7) != "/SLISC0")
		SLS_FAIL;

	// manipulate path
	boost::filesystem::path p = "abc/def/ghi.txt";
	if (p.string() != "abc/def/ghi.txt")
		SLS_FAIL;
	if (p.extension() != ".txt") // file extension
		SLS_FAIL;
	if (p.stem() != "ghi")
		SLS_FAIL;
	if (p.filename() != "ghi.txt") // string convert to boost::filesystem::path
		SLS_FAIL;
	if (p.parent_path() != "abc/def") // no slash at the end!
		SLS_FAIL;
	
	// ============== json ===================
	using boost::json::value; using boost::json::parse;
	// object obj;                                                     // construct an empty object
	// obj[ "pi" ] = 3.141;                                            // insert a double
	// obj[ "happy" ] = true;                                          // insert a bool
	// obj[ "name" ] = "Boost";                                        // insert a string
	// obj[ "nothing" ] = nullptr;                                     // insert a null
	// obj[ "answer" ].emplace_object()["everything"] = 42;            // insert an object with 1 element
	// obj[ "list" ] = { 1, 0, 2 };                                    // insert an array with 3 elements
	// obj[ "object" ] = { {"currency", "USD"}, {"value", 42.99} };    // insert an object with 2 elements
	
	value jv1 = {
    { "pi", 3.141 },
    { "happy", true },
    { "name", "Boost" },
    { "nothing", nullptr },
    { "answer", {
        { "everything", 42 } } },
    {"list", {1, 0, 2}}, // [1, 0, 2]
    {"object", {
        { "currency", "USD" },
        { "value", 42.99 }
            } }
    };

	string s1 = serialize(jv1);
	// cout << jv1 << "\n\n\n" << endl; // uncomment
	value jv2 = parse(s1, ec);
	// cout << jv2 << "\n\n\n" << endl; // uncomment
	if(ec)
    	SLS_ERR("failed: " + ec.message());
	if (jv1 != jv2)
		SLS_FAIL;
	string s2 = serialize(jv2);
	// cout << s1 << endl;
	// cout << s2 << endl;
	if (s1 != s2)
		SLS_FAIL;

	// Boost Multi-precision lib
	{
		using namespace boost::multiprecision;
		cpp_int u = 1, v = 2, w;
		for(unsigned i = 1; i <= 100; ++i)
			u *= i;
		// prints 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000 (i.e. 100!)
		// std::cout << u << std::endl;
		w = u + v;
		// std::cout << w << std::endl;
	}
#else
    std::cout << "---------- disabled! ----------" << std::endl;
#endif
}
