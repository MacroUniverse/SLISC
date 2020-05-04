// convert .matt files into .matb files
#define SLS_MATB_REPLACE
#include "SLISC/matt.h"
#include "SLISC/matb.h"

int main(int argc, char *argv[])
{
    using namespace slisc;
	for (Long i = 1; i < argc; ++i) {
		cout << argv[i] << endl;
		matt2matb(argv[i]);
	}
}
