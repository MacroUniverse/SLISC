#ifdef SLS_USE_BOOST
#include <iostream>
#include <boost/filesystem.hpp>
#include "../SLISC/file.h"

void test_boost()
{
	using namespace slisc;
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
		SLS_ERR("failed!");
	file_copy("test/test_file/测试1.txt", "test/test_file/测试.txt", true);
	error_code ec;

	// If old_p and new_p resolve to the same existing file, no action is taken.
	// otherwise, if new_p resolves to an existing non-directory file, it is removed.
	// if new_p resolves to an existing directory, it is removed if empty on ISO/IEC 9945 but is an error on Windows.
	// A symbolic link is itself renamed, rather than the file it resolves to being renamed.
	file_remove("测试1.txt");
	rename("test/test_file/测试1.txt", "测试1.txt");
	if (!file_exist("测试1.txt"))
		SLS_ERR("failed!");
	
	// last_write_time
	Long t = last_write_time("测试1.txt"); // return an integer of POSIX time
	Long t1 = time(NULL);
	if (abs(t - t1) > 1)
		SLS_ERR("failed!");

	file_remove("测试1.txt");

	// current path (pwd)
	Str path = current_path().string();
	if (path.substr(path.size()-7) != "/SLISC0")
		SLS_ERR("failed!");

	// manipulate path
	boost::filesystem::path p = "abc/def/ghi.txt";
	if (p.string() != "abc/def/ghi.txt")
		SLS_ERR("failed!");
	if (p.extension() != ".txt") // file extension
		SLS_ERR("failed!");
	if (p.stem() != "ghi")
		SLS_ERR("failed!");
	if (p.filename() != "ghi.txt") // string convert to boost::filesystem::path
		SLS_ERR("failed!");
	if (p.parent_path() != "abc/def") // no slash at the end!
		SLS_ERR("failed!");
}
#endif
