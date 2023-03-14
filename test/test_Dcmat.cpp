#include "../SLISC/arith/arithmetic.h"
#include "../SLISC/dense/cut.h"
#include "../SLISC/dense/Dcit.h"
#include "../SLISC/str/disp.h"

using namespace slisc;

void test_Dcmat() {
	CmatDoub a(6, 7); linspace(a, 0, 41);
	const DcmatDoub_c b = cut(a, 0, 4, 0, 3);
	DcitDoub_c it;
	Long k = 0;
	for (it.beg(b); it.ckend(); ++it)
		if (*it != b[k++]) SLS_FAIL;
	if (k != 12)  SLS_FAIL;
	k = 11;
	for (it.end(b); it.ckbeg(); --it)
		if (*it != b[k--]) SLS_FAIL;
	if (k != -1)  SLS_FAIL;
}
