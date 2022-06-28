#include "../SLISC/arithmetic.h"
#include "../SLISC/cut.h"
#include "../SLISC/Dcit.h"
#include "../SLISC/disp.h"

using namespace slisc;

void test_Dcmat() {
	CmatDoub a(6, 7); linspace(a, 0, 41);
	DcmatDoub b = cut(a, 0, 4, 0, 3);
	DcitDoub it; 
	Doub *p = end(b);
	Long k = 0;
	for (begin(it, b); it != p; ++it)
		if (*it != b[k++]) SLS_ERR("failed!");
	k = 11;
	p = begin(b);
	for (end(it, b); it >= p; --it)
		if (*it != b[k--]) SLS_ERR("failed!");
}
