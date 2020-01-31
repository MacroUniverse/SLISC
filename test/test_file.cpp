#include "../SLISC/file.h"

void test_file()
{
	using namespace slisc;
	// file_list
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
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
}
