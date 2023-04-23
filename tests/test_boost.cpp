#include <iostream>
#ifdef SLS_USE_BOOST
#include "../SLISC/file/file.h"
#include <boost/filesystem.hpp>
#include <boost/json/src.hpp>
#include <boost/multiprecision/cpp_int.hpp>
// #include <boost/multiprecision/cpp_bin_float.hpp>
// #include <boost/math/special_functions/gamma.hpp>
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
		SLS_ERR("failed! boost version not tested");
    if (!file_exist(u8"tests/test_file/测试.txt")) {
        cout << "pwd() = " << pwd() << endl;
        SLS_ERR("failed!");
    }
	if (file_size(u8"tests/test_file/测试.txt") != 12) {
        SLS_ERR("failed!" + to_string(file_size(u8"tests/test_file/测试.txt")));
    }
	file_copy(u8"tests/test_file/测试1.txt", u8"tests/test_file/测试.txt", true);
	error_code ec;

	// If old_p and new_p resolve to the same existing file, no action is taken.
	// otherwise, if new_p resolves to an existing non-directory file, it is removed.
	// if new_p resolves to an existing directory, it is removed if empty on ISO/IEC 9945 but is an error on Windows.
	// A symbolic link is itself renamed, rather than the file it resolves to being renamed.
	file_remove(u8"测试1.txt");
	rename(u8"tests/test_file/测试1.txt", u8"测试1.txt");
	if (!file_exist(u8"测试1.txt"))
		SLS_FAIL;
	
	// last_write_time
	Long t = last_write_time(u8"测试1.txt"); // return an integer of POSIX time
	Long t1 = time(NULL);
	if (abs(t - t1) > 1)
		SLS_FAIL;

	file_remove(u8"测试1.txt");

	// current path (pwd)
	Str path = current_path().string();
	if (path.substr(path.size()-6) != "/SLISC")
		SLS_WARN("current path is: " + path);

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
		cpp_int u = 2, v = 3, w;
		w = (u + v)*v + u;
		// cout << w << endl;
		for(unsigned i = 3; i <= 100; ++i)
			u *= i;
		// prints 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000 (i.e. 100!)
		// std::cout << u << std::endl;
		// std::cout << w << std::endl;

		// Operations at fixed precision and full numeric_limits support:
		// typedef number<cpp_bin_float<256> > cpp_bin_float_256;
		// cpp_bin_float_256 b = 2;
		// std::cout << std::numeric_limits<cpp_bin_float_256>::digits << std::endl;
		// std::cout << std::numeric_limits<cpp_bin_float_256>::digits10 << std::endl;
		// We can use any C++ std lib function, lets print all the digits as well:
		// std::cout << std::setprecision(std::numeric_limits<cpp_bin_float_256>::max_digits10)
		//	<< log(b) << std::endl; // print log(2)
		// We can also use any function from Boost.Math:
		// std::cout << boost::math::tgamma(b) << std::endl;
		// These even work when the argument is an expression template:
		// std::cout << boost::math::tgamma(b * b) << std::endl;
		// And since we have an extended exponent range we can generate some really large 
		// numbers here (4.0238726007709377354370243e+2564):
		// std::cout << boost::math::tgamma(cpp_bin_float_256(1000)) << std::endl;
	}
#else
	std::cout << "---------- disabled! ----------" << std::endl;
#endif
}

#ifndef SLS_TEST_ALL
int main() { test_boost(); }
#endif
