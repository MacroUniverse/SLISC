#include "../SLISC/file.h"
#include "../SLISC/disp.h"

void test_file()
{
	using namespace slisc;
	// file_list
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
		SLS_FAIL;

	// file_list_r
	file_list_r(names, "test/test_file/");
	if (names[0] != "test/test_file/123.txt" || names[1] != "test/test_file/234.txt" || names[2] != "test/test_file/sub/345.txt")
		SLS_FAIL;

	// write()
	Str data = "abcdefghijklmnopqrstuvwxyz";
	write(data.data(), data.size(), "test_bin");
	if (file_size("test_bin") != size(data))
		SLS_FAIL;
	Str data1;

	// read()
	data1.resize(data.size());
	read(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_FAIL;

	// write_vec_str() and read_vec_str()
	vecStr32 str32 = {U"你好你好", U"谢谢", U"您吃了吗？"}, str32_;
	write_vec_str(str32, U"您吃了吗.txt");
	read_vec_str(str32_, U"您吃了吗.txt");
	if (str32 != str32_)
		SLS_FAIL;
	file_remove(utf32to8(U"您吃了吗.txt"));
	
	// multiple binary write()
	ofstream fout; open_bin(fout, "test_bin");
	fout.write(&data[0], 5);
	fout.write(&data[5], 5);
	fout.write(&data[10], 16);
	fout.close();
	read(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_FAIL;
	
	// multiple binary read()
	ifstream fin; open_bin(fin, "test_bin");
	Str tmp;
	fin.read(&data1[0], 10);
	fin.read(&data1[10], 10);
	fin.read(&data1[20], 10);
	fin.close();
	if (data1 != data)
		SLS_FAIL;

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
		SLS_FAIL;
	read(fin, d);
	if (d != 3.1415)
		SLS_FAIL;
	read(fin, c);
	if (c != 1.1 + 2.2*I)
		SLS_FAIL;
	
	// write() and read() string to/from file
	Str str(data), str1;
	write(str, "test_bin");
	read(str1, "test_bin");
	if (str != str1)
		SLS_FAIL;

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
		SLS_FAIL;

	remove("test_bin");

	{ // read matrix/vector from file
		CmatDoub mat, mat1(3, 3);
		read(mat, "test/test_file_matrix.txt", 2);
		mat1(0, 0) = 1.315; mat1(0, 1) = -2.531; mat1(0, 2) = -6.65;
		mat1(1, 0) = 2.351; mat1(1, 1) = 2.265; mat1(1, 2) = -2.376;
		mat1(2, 0) = -2.53; mat1(2, 1) = 6.65; mat1(2, 2) =  0.28;
		if (mat != mat1)
			SLS_FAIL;
		
		VecDoub v; MatDoub mat2(3, 3); copy(mat2, mat1);
		read(v, "test/test_file_matrix.txt", 2);
		for (i = 0; i < mat2.size(); ++i) {
			if (v[i] != mat2[i])
				SLS_FAIL;
		}
	}

	// last modified time (local time)
	{
#ifndef _MSC_VER
		Str yyyymmddhhmmss;
		last_modified(yyyymmddhhmmss, "main.cpp");
		if (yyyymmddhhmmss.size() != 14)
			SLS_FAIL;
#endif
	}

	// check if directory exist
	// `path` must end with '/'
	{
		if (!dir_exist("SLISC/"))
			SLS_FAIL;
		if (!dir_exist("SLISC"))
			SLS_FAIL;
		if (dir_exist("abc/"))
			SLS_FAIL;
		if (dir_exist("abc"))
			SLS_FAIL;
	}

	// test ensure_dir()
	{
		ensure_dir("test_dir");
		if (!dir_exist("test_dir"))
			SLS_FAIL;
		rmdir("test_dir");
		if (dir_exist("test_dir"))
			SLS_FAIL;
	}

	// file_copy()
	{
		Str file1 = "sls_test_file_copy.txt", str1 = "abcdefg";
		Str file2 = "sls_test_file_copy2.txt", str2;
		file_remove(file1); file_remove(file2);
		write(str1, file1);
		file_copy(file2, file1);
		read(str2, file2);
		if (str2 != str1)
			SLS_FAIL;
		file_remove(file1); file_remove(file2);
	}

	// file_copy() with buffer, and file_move()
	{
		Str file1 = "sls_test_file_copy.txt", str1 = "abcdefg";
		Str file2 = "sls_test_file_copy2.txt", str2;
		file_remove(file1); file_remove(file2);
		Str buff; buff.resize(5);
		write(str1, file1);
		file_copy(file2, file1, buff);
		read(str2, file2);
		SLS_ASSERT(str2 == str1);
		file_remove(file2);
		file_move(file2, file1);
		str2.clear(); read(str2, file2);
		SLS_ASSERT(str1 == str2);
		file_remove(file2);
	}
}
