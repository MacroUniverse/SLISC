#include "../SLISC/matb.h"

using namespace slisc;

// usage: matbrename <filename.matb> <varname> <newname>
int main(int argc, char **argv)
{
	Str file = argv[1], varname = argv[2], newname = argv[3];
	cout << file << ": " << varname << " -> " << newname << endl;
	cout << "file size = " << file_size(file) << endl;
	Matb matb(file, 'r');
	Long ind = matb.search(varname);
	cout << "variable # " << ind << endl;
	if (ind < 0)
		SLS_ERR("var not found!");
	Str data; read(data, file);
	
	matb.m_in.seekg(0, std::ios::beg);
	cout << "begin of file tellg() = " << matb.m_in.tellg() << endl;

	Long name_ind0 = data.find(varname);
	cout << "name_ind0 = " << name_ind0 << endl;

	Long name_ind = matb.m_ind[ind] + 8;
	cout << "name_ind = " << name_ind << endl;
	cout << "is this varname? " << data.substr(name_ind, varname.size()) << endl;

	Long data_ind = matb.data_pos(ind);
	cout << "data_ind = " << data_ind << endl;
}
