// iterator for Dcmat
// still slower than fully optimized double loop
#include "Dcmat.h"

namespace slisc {
struct DcitDoub {
		Doub *m_p; // current pos
		Doub *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		// DcitDoub();
		// DcitDoub(Doub *p, Doub *end0, Doub *end, Doub *gap1): m_p(p), m_beg0(beg0), m_end(end), m_gap1(gap1) {}
		void operator++() {
			if (++m_p == m_end0)
				m_beg0 += m_step1, m_end0 += m_step1, m_p = m_beg0;
		}
		void operator--() {
			if (--m_p < m_beg0)
				m_beg0 -= m_step1, m_end0 -= m_step1, m_p = m_end0-1;
		}
		// Doub *p() { return m_p; }
		Doub &operator*() { return *m_p; }
		Bool operator==(Doub *p) { return m_p == p; }
		Bool operator!=(Doub *p) { return m_p != p; }
		Bool operator>(Doub *p) { return m_p > p; }
		Bool operator>=(Doub *p) { return m_p >= p; }
		Bool operator<(Doub *p) { return m_p < p; }
		Bool operator<=(Doub *p) { return m_p <= p; }
};

typedef DcitDoub &DcitDoub_O, &DcitDoub_IO;

inline void begin(DcitDoub_O it, DcmatDoub_IO a) {
	it.m_p = a.p();
	it.m_beg0 = it.m_p;
	it.m_end0 = it.m_p + a.n0();
	it.m_step1 = a.lda();
}

inline void end(DcitDoub_O it, DcmatDoub_IO a) {
	it.m_beg0 = a.p() + a.lda()*(a.n1()-1);
	it.m_end0 = it.m_beg0 + a.n0();
	it.m_p = it.m_beg0 + (a.n0()-1);
	it.m_step1 = a.lda();
}

inline Doub *begin(DcmatDoub_IO a) {
	return a.p();
}

inline Doub *end(DcmatDoub_IO a) {
	return a.p() + a.lda()*a.n1();
}
} // namespace slisc
