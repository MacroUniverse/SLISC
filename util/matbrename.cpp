#include "../SLISC-64q/file/matb.h"

using namespace slisc;

// usage: matbrename <filename.matb> <varname> <newname>
// cuttently only support rename to same size!
int main(int argc, char **argv)
{
	Str fname = argv[1], varname = argv[2], newname = argv[3];
	cout << fname << ": " << varname << " -> " << newname << endl;
	if (varname.size() != newname.size())
		SLS_ERR("cuttently only support rename to same size!");
	Matb matb(fname, "r");
	Long ind = matb.search(varname);
	if (ind < 0)
		SLS_ERR("variable not found!");
	Long name_pos = matb.m_ind[ind] + 8;

	Str data; read(data, fname);
	if (data.substr(name_pos, varname.size()) != varname)
		SLS_ERR("unknow!");
	data.replace(name_pos, varname.size(), newname);

	ofstream fout; open_bin(fout, "renamed-" + fname);
	write(fout, data);
	fout.close();
}
