#include "../SLISC-64q/file/matt.h"

using namespace slisc;

int main(int argc, char **argv)
{
	Str fname = argv[1];
	Matt matt(fname, "r");
	for (Long i = 0; i < matt.size(); ++i) {
		cout << i << ". " << matt.m_name[i] << "  size: ";
		if (size(matt.m_size[i]) > 0) {
			cout << matt.m_size[i][0];
			for (Long j = 1; j < size(matt.m_size[i]); ++j) {
				cout << "x" << matt.m_size[i][j];
			}
		}
		else
			cout << '1';
		
		cout << "  type: " << matt.m_type[i] << endl;
//% types = {};
//%----------------------------------
// TODO
//%----------------------------------
	}
}
