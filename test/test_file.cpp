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
	write_bin(data, "test_bin");
	if (file_size("test_bin") != size(data))
		SLS_ERR("failed!");
	Str data1;

	// read_bin()
	read_bin(data1, "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	
	// multiple write_bin()
	ofstream fout; open_bin(fout, "test_bin");
	write_bin(fout, data.substr(0, 5));
	write_bin(fout, data.substr(5, 5));
	write_bin(fout, data.substr(10, 16));
	fout.close();
	read_bin(data1, "test_bin");
	if (data1 != data)
		SLS_ERR("failed!");
	
	// multiple read_bin()
	ifstream fin; open_bin(fin, "test_bin");
	Str tmp;
	read_bin(data1, fin, 10);
	read_bin(tmp, fin, 10); data1 += tmp;
	read_bin(tmp, fin, 10); data1 += tmp;
	if (data1 != data)
		SLS_ERR("failed!");

	remove("test_bin");
}
