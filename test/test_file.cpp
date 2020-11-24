#include "../SLISC/file.h"
#include "../SLISC/disp.h"

void test_file()
{
	using namespace slisc;
	// file_list
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
		SLS_ERR("failed!");

	// file_list_r
	file_list_r(names, "test/test_file");
	if (names[0] != "test/test_file/123.txt" || names[1] != "test/test_file/234.txt" || names[2] != "test/test_file/sub/345.txt")
		SLS_ERR("failed!");

	// write()
	Str data = "abcdefghijklmnopqrstuvwxyz";
	write(data.data(), data.size(), "test_bin");
	if (file_size("test_bin") != size(data))
		SLS_ERR("failed!");
	Str data1;

	// read()
	data1.resize(data.size());
	read(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");

	// write_vec_str() and read_vec_str()
	vecStr32 str32 = {U"你好你好", U"谢谢", U"您吃了吗？"}, str32_;
	write_vec_str(str32, U"您吃了吗.txt");
	read_vec_str(str32_, U"您吃了吗.txt");
	if (str32 != str32_)
		SLS_ERR("failed!");
	file_remove(utf32to8(U"您吃了吗.txt"));
	
	// multiple binary write()
	ofstream fout; open_bin(fout, "test_bin");
	fout.write(&data[0], 5);
	fout.write(&data[5], 5);
	fout.write(&data[10], 16);
	fout.close();
	read(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	
	// multiple binary read()
	ifstream fin; open_bin(fin, "test_bin");
	Str tmp;
	fin.read(&data1[0], 10);
	fin.read(&data1[10], 10);
	fin.read(&data1[20], 10);
	fin.close();
	if (data1 != data)
		SLS_ERR("failed!");

	// write() and read() scalar
	open_bin(fout, "test_bin");
	write(fout, 12345);
	write(fout, 3.1415);
	write(fout, 1.1 + 2.2*I);
	fout.close();
	open_bin(fin, "test_bin");
	Int i; Doub d; Comp c;
	read(fin, i);
	if (i != 12345)
		SLS_ERR("failed!");
	read(fin, d);
	if (d != 3.1415)
		SLS_ERR("failed!");
	read(fin, c);
	if (c != 1.1 + 2.2*I)
		SLS_ERR("failed!");
	
	// write() and read() string to/from file
	Str str(data), str1;
	write(str, "test_bin");
	read(str1, "test_bin");
	if (str != str1)
		SLS_ERR("failed!");

	// write() and read() string to/from fstream
	open_bin(fout, "test_bin");
	write(fout, str.substr(0, 5));
	write(fout, str.substr(5, 5));
	write(fout, str.substr(10, 16));
	fout.close();
	
	open_bin(fin, "test_bin");
	tmp.resize(10);
	str1.clear();
	read(fin, tmp);
	str1 += tmp;
	read(fin, tmp);
	str1 += tmp;
	read(fin, tmp);
	str1 += tmp;
	fin.close();
	if (str1 != str)
		SLS_ERR("failed!");

	remove("test_bin");

	{ // read matrix from file
		CmatDoub mat, mat1(3, 3);
		read(mat, "test/test_file_matrix.txt", 2);
		mat1(0, 0) = 1.315; mat1(0, 1) = -2.531; mat1(0, 2) = -6.65;
		mat1(1, 0) = 2.351; mat1(1, 1) = 2.265; mat1(1, 2) = -2.376;
		mat1(2, 0) = -2.53; mat1(2, 1) = 6.65; mat1(2, 2) =  0.28;
		mat -= mat1;
		if (max_abs(mat) > 1e-14)
			SLS_ERR("failed!");
	}

	// last modified time (local time)
	{
		Str yyyymmddhhmmss;
		last_modified(yyyymmddhhmmss, "main.cpp");
		if (yyyymmddhhmmss.size() != 14)
			SLS_ERR("failed!");
	}

	// check if directory exist
	// `path` must end with '/'
	{
		if (!dir_exist("SLISC/"))
			SLS_ERR("failed!");
		if (!dir_exist("SLISC"))
			SLS_ERR("failed!");
		if (dir_exist("abc/"))
			SLS_ERR("failed!");
		if (dir_exist("abc"))
			SLS_ERR("failed!");
	}

	// test ensure_dir()
	{
		ensure_dir("test_dir");
		if (!dir_exist("test_dir"))
			SLS_ERR("failed!");
		rmdir("test_dir");
		if (dir_exist("test_dir"))
			SLS_ERR("failed!");
	}

	// file_copy()
	{
		Str file1 = "sls_test_file_copy.txt", str1 = "abcdefg";
		Str file2 = "sls_test_file_copy2.txt", str2;
		write(str1, file1);
		file_copy(file2, file1);
		read(str2, file2);
		if (str2 != str1)
			SLS_ERR("failed!");
		file_remove(file1); file_remove(file2);
	}

	// file_copy() with buffer
	{
		Str file1 = "sls_test_file_copy.txt", str1 = "abcdefg";
		Str file2 = "sls_test_file_copy2.txt", str2;
		Str buff; buff.resize(5);
		write(str1, file1);
		file_copy(file2, file1, buff);
		read(str2, file2);
		if (str2 != str1)
			SLS_ERR("failed!");
		file_remove(file1); file_remove(file2);
	}
}
