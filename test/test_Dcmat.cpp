#include "../SLISC/arithmetic.h"
#include "../SLISC/cut.h"
#include "../SLISC/Dcit.h"
#include "../SLISC/disp.h"

using namespace slisc;

void test_Dcmat() {
	CmatDoub a(6, 7); linspace(a, 0, 41);
	const DcmatDoub_c b = cut(a, 0, 4, 0, 3);
	DcitDoub_c it;
	Long k = 0;
	for (it.beg(b); it.ckend(); ++it)
		if (*it != b[k++]) SLS_ERR("failed!");
	if (k != 12)  SLS_ERR("failed!");
	k = 11;
	for (it.end(b); it.ckbeg(); --it)
		if (*it != b[k--]) SLS_ERR("failed!");
	if (k != -1)  SLS_ERR("failed!");
}
