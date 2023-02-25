#pragma once
#include "string.h"
#ifdef SLS_USE_ARB
#include "arb_hypgeom.h" // real functions
#include "acb_hypgeom.h" // complex functions
#endif

namespace slisc {

#ifdef SLS_USE_ARB
// 1F1 with real arguments
inline Doub arb_hypergeom1F1(Doub_I a, Doub_I b, Doub_I z)
{
	Int digits;
	slong prec = 64; // set precision bit (log10/log2 = 3.322)
	Doub res;
	arb_t a1, b1, z1, res1;
	arb_init(a1); arb_init(b1); arb_init(z1); arb_init(res1);
	arb_set_d(a1, a); arb_set_d(b1, b);	arb_set_d(z1, z);
	// arb_printn(res1, 100, 0); printf("\n");  // print result
	for (Long i = 0; i < 6; ++i) {
		arb_hypgeom_1f1(res1, a1, b1, z1, 0, prec);
		digits = arb_rel_accuracy_bits(res1)/3.321928;
		if (digits >= 16)
	        break;
	    prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_hypergeom1F1 error too large : " + num2str(digits) + " digits");
	res = arf_get_d(arb_midref(res1), ARF_RND_NEAR);
	arb_clear(a1); arb_clear(b1); arb_clear(z1); arb_clear(res1);
	return res;
}

inline Doub arb_WhittakerM(Doub_I ka, Doub_I mu, Doub_I x)
{
	return exp(-0.5*x)*pow(x, mu+0.5)*arb_hypergeom1F1(mu - ka + 0.5, 1 + 2*mu, x);
}

// 1F1 with complex arguments
inline Comp arb_hypergeom1F1(Comp_I a, Comp_I b, Comp_I z)
{
	Int digits;
	slong prec = 64; // set precision bit (log10/log2 = 3.322)
	Comp res;
	arb_t temp1;
	arb_init(temp1);
	acb_t a1, b1, z1, res1;
	acb_init(a1); acb_init(b1); acb_init(z1); acb_init(res1);
	acb_set_d_d(a1, real(a), imag(a));
	acb_set_d_d(b1, real(b), imag(b));
	acb_set_d_d(z1, real(z), imag(z));
	for (Long i = 0; i < 6; ++i) {
		acb_hypgeom_1f1(res1, a1, b1, z1, 0, prec);
		digits = acb_rel_accuracy_bits(res1)/3.321928;
		if (digits >= 16)
	        break;
	    prec *= 2;
	}
	if (digits < 16)
		SLS_ERR("arb_hypergeom1F1 error too large : " + num2str(digits) + " digits");
	acb_get_real(temp1, res1);
	res.real(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_get_imag(temp1, res1);
	res.imag(arf_get_d(arb_midref(temp1), ARF_RND_NEAR));
	acb_clear(a1); acb_clear(b1); acb_clear(z1); acb_clear(res1); arb_clear(temp1);
	return res;
}

inline Comp arb_hypergeom(SvecComp_I a, SvecComp_I b, SvecComp_I z)
{
	slong p = a.size(), q = b.size();
	Int regularized = false;
	slong prec = 64; // set precision bit (log10/log2 = 3.322)
	acb_t a1;
	acb_init(a1);
	arb_clear(a1);

	acb_hypgeom_pfq(acb_poly_t res, acb_srcptr a, p, acb_srcptr b, q, const acb_t z, int regularized, slong prec)
}
#endif

} // namespace slisc
