#include "../SLISC/matb.h"

using namespace slisc;

int main(int argc, char **argv)
{
	Str fname = argv[1];
	Matb matb(fname, 'r');
	for (Long i = 0; i < matb.size(); ++i) {
		cout << i << ". " << matb.m_name[i] << "  size: ";
		if (size(matb.m_size[i]) > 0) {
			cout << matb.m_size[i][0];
			for (Long j = 1; j < size(matb.m_size[i]); ++j) {
				cout << "x" << matb.m_size[i][j];
			}
		}
		else
			cout << '1';
		
		cout << "  type: " << matb.m_type[i] << endl;
//% types = {};
//%----------------------------------
// TODO
//%----------------------------------
	}
}
