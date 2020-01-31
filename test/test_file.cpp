#include "../SLISC/file.h"

void test_file()
{
	using namespace slisc;
	// file_list
	vecStr names;
	file_list(names, "./");
	if (names.size() < 3)
		SLS_ERR("failed!");

	// write_bin()
	Str data = "abcdefghijklmnopqrstuvwxyz";
	write_bin(data.data(), data.size(), "test_bin");
	if (file_size("test_bin") != size(data))
		SLS_ERR("failed!");
	Str data1;

	// read_bin()
	data1.resize(data.size());
	read_bin(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	
	// multiple write_bin()
	ofstream fout; open_bin(fout, "test_bin");
	fout.write(&data[0], 5);
	fout.write(&data[5], 5);
	fout.write(&data[10], 16);
	fout.close();
	read_bin(&data1[0], data1.size(), "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	
	// multiple read_bin()
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
	remove("test_bin");
}
