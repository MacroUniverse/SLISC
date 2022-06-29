// iterator for Dcmat
// support forward and backward
// very high performance for element traversal
#include "Dcmat.h"

namespace slisc {

struct DcitInt {
		Int *m_p; // current pos
		Int *m_beg, *m_end; // tot range
		Int *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatInt_IO a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatInt_IO a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		Int &operator*() { return *m_p; }
		Bool operator==(const Int *p) { return m_p == p; }
		Bool operator!=(const Int *p) { return m_p != p; }
		Bool operator>(const Int *p) { return m_p > p; }
		Bool operator>=(const Int *p) { return m_p >= p; }
		Bool operator<(const Int *p) { return m_p < p; }
		Bool operator<=(const Int *p) { return m_p <= p; }
};
typedef DcitInt &DcitInt_O, &DcitInt_IO;

struct DcitInt_c {
		const Int *m_p; // current pos
		const Int *m_beg, *m_end; // tot range
		const Int *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatInt_I a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatInt_I a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		const Int &operator*() { return *m_p; }
		Bool operator==(const Int *p) { return m_p == p; }
		Bool operator!=(const Int *p) { return m_p != p; }
		Bool operator>(const Int *p) { return m_p > p; }
		Bool operator>=(const Int *p) { return m_p >= p; }
		Bool operator<(const Int *p) { return m_p < p; }
		Bool operator<=(const Int *p) { return m_p <= p; }
};
typedef const DcitInt_c &DcitInt_I;

struct DcitLlong {
		Llong *m_p; // current pos
		Llong *m_beg, *m_end; // tot range
		Llong *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatLlong_IO a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatLlong_IO a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		Llong &operator*() { return *m_p; }
		Bool operator==(const Llong *p) { return m_p == p; }
		Bool operator!=(const Llong *p) { return m_p != p; }
		Bool operator>(const Llong *p) { return m_p > p; }
		Bool operator>=(const Llong *p) { return m_p >= p; }
		Bool operator<(const Llong *p) { return m_p < p; }
		Bool operator<=(const Llong *p) { return m_p <= p; }
};
typedef DcitLlong &DcitLlong_O, &DcitLlong_IO;

struct DcitLlong_c {
		const Llong *m_p; // current pos
		const Llong *m_beg, *m_end; // tot range
		const Llong *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatLlong_I a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatLlong_I a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		const Llong &operator*() { return *m_p; }
		Bool operator==(const Llong *p) { return m_p == p; }
		Bool operator!=(const Llong *p) { return m_p != p; }
		Bool operator>(const Llong *p) { return m_p > p; }
		Bool operator>=(const Llong *p) { return m_p >= p; }
		Bool operator<(const Llong *p) { return m_p < p; }
		Bool operator<=(const Llong *p) { return m_p <= p; }
};
typedef const DcitLlong_c &DcitLlong_I;

struct DcitDoub {
		Doub *m_p; // current pos
		Doub *m_beg, *m_end; // tot range
		Doub *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatDoub_IO a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatDoub_IO a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		Doub &operator*() { return *m_p; }
		Bool operator==(const Doub *p) { return m_p == p; }
		Bool operator!=(const Doub *p) { return m_p != p; }
		Bool operator>(const Doub *p) { return m_p > p; }
		Bool operator>=(const Doub *p) { return m_p >= p; }
		Bool operator<(const Doub *p) { return m_p < p; }
		Bool operator<=(const Doub *p) { return m_p <= p; }
};
typedef DcitDoub &DcitDoub_O, &DcitDoub_IO;

struct DcitDoub_c {
		const Doub *m_p; // current pos
		const Doub *m_beg, *m_end; // tot range
		const Doub *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatDoub_I a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatDoub_I a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		const Doub &operator*() { return *m_p; }
		Bool operator==(const Doub *p) { return m_p == p; }
		Bool operator!=(const Doub *p) { return m_p != p; }
		Bool operator>(const Doub *p) { return m_p > p; }
		Bool operator>=(const Doub *p) { return m_p >= p; }
		Bool operator<(const Doub *p) { return m_p < p; }
		Bool operator<=(const Doub *p) { return m_p <= p; }
};
typedef const DcitDoub_c &DcitDoub_I;

struct DcitComp {
		Comp *m_p; // current pos
		Comp *m_beg, *m_end; // tot range
		Comp *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatComp_IO a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatComp_IO a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		Comp &operator*() { return *m_p; }
		Bool operator==(const Comp *p) { return m_p == p; }
		Bool operator!=(const Comp *p) { return m_p != p; }
		Bool operator>(const Comp *p) { return m_p > p; }
		Bool operator>=(const Comp *p) { return m_p >= p; }
		Bool operator<(const Comp *p) { return m_p < p; }
		Bool operator<=(const Comp *p) { return m_p <= p; }
};
typedef DcitComp &DcitComp_O, &DcitComp_IO;

struct DcitComp_c {
		const Comp *m_p; // current pos
		const Comp *m_beg, *m_end; // tot range
		const Comp *m_beg0, *m_end0; // current column range
		Long m_step1; // leading dimension
		void operator++() { ++m_p; }
		void operator--() { --m_p; }
		void beg(DcmatComp_I a) {
			m_beg = m_p = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = m_p;
			m_end0 = m_p + a.n0();
		}
		void end(DcmatComp_I a) {
			m_beg = a.p();
			m_step1 = a.lda();
			m_end = m_beg + a.n1()*m_step1;
			m_beg0 = a.p() + a.lda()*(a.n1()-1);
			m_end0 = m_beg0 + a.n0();
			m_p = m_end0-1;
		}
		Bool ckend() {
			if (m_p == m_end0) {
				m_beg0 += m_step1;
				if (m_beg0 >= m_end)
					return false;
				m_p = m_beg0; m_end0 += m_step1;
			}
			return true;
		}
		Bool ckbeg() {
			if (m_p < m_beg0) {
				m_end0 -= m_step1;
				if (m_end0 < m_beg)
					return false;
				m_p = m_end0-1; m_beg0 -= m_step1;
			}
			return true;
		}
		const Comp &operator*() { return *m_p; }
		Bool operator==(const Comp *p) { return m_p == p; }
		Bool operator!=(const Comp *p) { return m_p != p; }
		Bool operator>(const Comp *p) { return m_p > p; }
		Bool operator>=(const Comp *p) { return m_p >= p; }
		Bool operator<(const Comp *p) { return m_p < p; }
		Bool operator<=(const Comp *p) { return m_p <= p; }
};
typedef const DcitComp_c &DcitComp_I;


} // namespace slisc
