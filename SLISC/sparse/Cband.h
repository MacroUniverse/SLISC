// band diagonal matrix class
#pragma once
#include "../dense/Cmat.h"
#include "../dense/Dvec.h"
#include "../dense/Dcmat.h"

namespace slisc {

class CbandInt
{
public:
	Long m_N0;
	Long m_Nup;
	Long m_Nlow;
	Long m_idiag; // position of diagonal
	CmatInt m_a;

	CbandInt();
	CbandInt(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

	Int * p();
	const Int * p() const;
	Int operator()(Long_I i, Long_I j) const;
	Int &ref(Long_I i, Long_I j);
	Long n0() const;
	Long n1() const;
	Long size() const;
	Long nup() const;
	Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatInt &cmat();
	const CmatInt &cmat() const;
	DcmatInt band();
	DcmatInt_c band() const;
	DvecInt diag();
	DvecInt_c diag() const;
	void resize(Long_I lda, Long_I N1);
	void resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);
	void reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag = -1);
	void shift(Long_I idiag);
};

inline CbandInt::CbandInt(): m_N0(0), m_Nup(0), m_Nlow(0), m_idiag(0)
{}

inline CbandInt::CbandInt(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
	m_N0(N0), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N1)
{
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < m_Nup || m_a.n0() - m_idiag - 1 < m_Nlow)
	    SLS_ERR("CbandInt: wrong shape: N0="+num2str(N0)+", N1="+num2str(N1)+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
#endif
}

inline Int * CbandInt::p()
{
	return m_a.p();
}

inline const Int * CbandInt::p() const
{
	return m_a.p();
}

inline Int CbandInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    return 0;
	return m_a(m_idiag + i - j, j);
}

inline Int &CbandInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    SLS_ERR("index out of band!");
	return m_a(m_idiag + i - j, j);
}

inline Long CbandInt::n0() const
{
	return m_N0;
}

inline Long CbandInt::n1() const
{
	return m_a.n1();
}

inline Long CbandInt::size() const
{
	return n0() * n1();
}

inline Long CbandInt::nup() const
{
	return m_Nup;
}

inline Long CbandInt::nlow() const
{
	return m_Nlow;
}

inline Long CbandInt::lda() const
{
	return m_a.n0();
}

inline Long CbandInt::idiag() const
{
	return m_idiag;
}

inline CmatInt &CbandInt::cmat()
{
	return m_a;
}

inline const CmatInt &CbandInt::cmat() const
{
	return m_a;
}

inline DcmatInt CbandInt::band()
{
	return DcmatInt(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DcmatInt_c CbandInt::band() const
{
	return DcmatInt_c(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DvecInt CbandInt::diag()
{
	return DvecInt(&m_a[m_idiag], n1(), lda());
}

inline DvecInt_c CbandInt::diag() const
{
	return DvecInt_c(&m_a[m_idiag], n1(), lda());
}

inline void CbandInt::resize(Long_I lda, Long_I N1)
{
	m_a.resize(lda, N1);
}

inline void CbandInt::reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag)
{
	if (idiag >= 0)
	    m_idiag = idiag;
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow) {
	    SLS_ERR("CbandInt: wrong shape: N0="+num2str(N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
	}
#endif
	m_N0 = N0; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandInt::resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag)
{
	resize(lda < 0? Nup+Nlow+1 : lda, N1);
	reshape(N0, Nup, Nlow, idiag < 0? Nup : idiag);
}

inline void CbandInt::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPES
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
	    SLS_ERR("CbandInt: wrong shape: N0="+num2str(m_N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(m_Nup)+", Nlow="+num2str(m_Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(idiag));
#endif
	m_idiag = idiag;
}

typedef const CbandInt &CbandInt_I;
typedef CbandInt &CbandInt_O, &CbandInt_IO;

class CbandDoub
{
public:
	Long m_N0;
	Long m_Nup;
	Long m_Nlow;
	Long m_idiag; // position of diagonal
	CmatDoub m_a;

	CbandDoub();
	CbandDoub(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

	Doub * p();
	const Doub * p() const;
	Doub operator()(Long_I i, Long_I j) const;
	Doub &ref(Long_I i, Long_I j);
	Long n0() const;
	Long n1() const;
	Long size() const;
	Long nup() const;
	Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatDoub &cmat();
	const CmatDoub &cmat() const;
	DcmatDoub band();
	DcmatDoub_c band() const;
	DvecDoub diag();
	DvecDoub_c diag() const;
	void resize(Long_I lda, Long_I N1);
	void resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);
	void reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag = -1);
	void shift(Long_I idiag);
};

inline CbandDoub::CbandDoub(): m_N0(0), m_Nup(0), m_Nlow(0), m_idiag(0)
{}

inline CbandDoub::CbandDoub(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
	m_N0(N0), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N1)
{
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < m_Nup || m_a.n0() - m_idiag - 1 < m_Nlow)
	    SLS_ERR("CbandDoub: wrong shape: N0="+num2str(N0)+", N1="+num2str(N1)+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
#endif
}

inline Doub * CbandDoub::p()
{
	return m_a.p();
}

inline const Doub * CbandDoub::p() const
{
	return m_a.p();
}

inline Doub CbandDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    return 0;
	return m_a(m_idiag + i - j, j);
}

inline Doub &CbandDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    SLS_ERR("index out of band!");
	return m_a(m_idiag + i - j, j);
}

inline Long CbandDoub::n0() const
{
	return m_N0;
}

inline Long CbandDoub::n1() const
{
	return m_a.n1();
}

inline Long CbandDoub::size() const
{
	return n0() * n1();
}

inline Long CbandDoub::nup() const
{
	return m_Nup;
}

inline Long CbandDoub::nlow() const
{
	return m_Nlow;
}

inline Long CbandDoub::lda() const
{
	return m_a.n0();
}

inline Long CbandDoub::idiag() const
{
	return m_idiag;
}

inline CmatDoub &CbandDoub::cmat()
{
	return m_a;
}

inline const CmatDoub &CbandDoub::cmat() const
{
	return m_a;
}

inline DcmatDoub CbandDoub::band()
{
	return DcmatDoub(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DcmatDoub_c CbandDoub::band() const
{
	return DcmatDoub_c(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DvecDoub CbandDoub::diag()
{
	return DvecDoub(&m_a[m_idiag], n1(), lda());
}

inline DvecDoub_c CbandDoub::diag() const
{
	return DvecDoub_c(&m_a[m_idiag], n1(), lda());
}

inline void CbandDoub::resize(Long_I lda, Long_I N1)
{
	m_a.resize(lda, N1);
}

inline void CbandDoub::reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag)
{
	if (idiag >= 0)
	    m_idiag = idiag;
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow) {
	    SLS_ERR("CbandDoub: wrong shape: N0="+num2str(N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
	}
#endif
	m_N0 = N0; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandDoub::resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag)
{
	resize(lda < 0? Nup+Nlow+1 : lda, N1);
	reshape(N0, Nup, Nlow, idiag < 0? Nup : idiag);
}

inline void CbandDoub::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPES
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
	    SLS_ERR("CbandDoub: wrong shape: N0="+num2str(m_N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(m_Nup)+", Nlow="+num2str(m_Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(idiag));
#endif
	m_idiag = idiag;
}

typedef const CbandDoub &CbandDoub_I;
typedef CbandDoub &CbandDoub_O, &CbandDoub_IO;

class CbandComp
{
public:
	Long m_N0;
	Long m_Nup;
	Long m_Nlow;
	Long m_idiag; // position of diagonal
	CmatComp m_a;

	CbandComp();
	CbandComp(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

	Comp * p();
	const Comp * p() const;
	Comp operator()(Long_I i, Long_I j) const;
	Comp &ref(Long_I i, Long_I j);
	Long n0() const;
	Long n1() const;
	Long size() const;
	Long nup() const;
	Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatComp &cmat();
	const CmatComp &cmat() const;
	DcmatComp band();
	DcmatComp_c band() const;
	DvecComp diag();
	DvecComp_c diag() const;
	void resize(Long_I lda, Long_I N1);
	void resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);
	void reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag = -1);
	void shift(Long_I idiag);
};

inline CbandComp::CbandComp(): m_N0(0), m_Nup(0), m_Nlow(0), m_idiag(0)
{}

inline CbandComp::CbandComp(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
	m_N0(N0), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N1)
{
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < m_Nup || m_a.n0() - m_idiag - 1 < m_Nlow)
	    SLS_ERR("CbandComp: wrong shape: N0="+num2str(N0)+", N1="+num2str(N1)+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
#endif
}

inline Comp * CbandComp::p()
{
	return m_a.p();
}

inline const Comp * CbandComp::p() const
{
	return m_a.p();
}

inline Comp CbandComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    return 0;
	return m_a(m_idiag + i - j, j);
}

inline Comp &CbandComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N0 || j < 0 || j >= n1())
	    SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
	    SLS_ERR("index out of band!");
	return m_a(m_idiag + i - j, j);
}

inline Long CbandComp::n0() const
{
	return m_N0;
}

inline Long CbandComp::n1() const
{
	return m_a.n1();
}

inline Long CbandComp::size() const
{
	return n0() * n1();
}

inline Long CbandComp::nup() const
{
	return m_Nup;
}

inline Long CbandComp::nlow() const
{
	return m_Nlow;
}

inline Long CbandComp::lda() const
{
	return m_a.n0();
}

inline Long CbandComp::idiag() const
{
	return m_idiag;
}

inline CmatComp &CbandComp::cmat()
{
	return m_a;
}

inline const CmatComp &CbandComp::cmat() const
{
	return m_a;
}

inline DcmatComp CbandComp::band()
{
	return DcmatComp(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DcmatComp_c CbandComp::band() const
{
	return DcmatComp_c(&m_a[m_idiag - m_Nup], m_Nup + m_Nlow + 1, n1(), lda());
}

inline DvecComp CbandComp::diag()
{
	return DvecComp(&m_a[m_idiag], n1(), lda());
}

inline DvecComp_c CbandComp::diag() const
{
	return DvecComp_c(&m_a[m_idiag], n1(), lda());
}

inline void CbandComp::resize(Long_I lda, Long_I N1)
{
	m_a.resize(lda, N1);
}

inline void CbandComp::reshape(Long_I N0, Long_I Nup, Long_I Nlow, Long_I idiag)
{
	if (idiag >= 0)
	    m_idiag = idiag;
#ifdef SLS_CHECK_SHAPES
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow) {
	    SLS_ERR("CbandComp: wrong shape: N0="+num2str(N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(Nup)+", Nlow="+num2str(Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(m_idiag));
	}
#endif
	m_N0 = N0; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandComp::resize(Long_I N0, Long_I N1, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag)
{
	resize(lda < 0? Nup+Nlow+1 : lda, N1);
	reshape(N0, Nup, Nlow, idiag < 0? Nup : idiag);
}

inline void CbandComp::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPES
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
	    SLS_ERR("CbandComp: wrong shape: N0="+num2str(m_N0)+", N1="+num2str(m_a.n1())+
	        ", Nup="+num2str(m_Nup)+", Nlow="+num2str(m_Nlow)+
	        ", lda="+num2str(m_a.n0())+", idiag="+num2str(idiag));
#endif
	m_idiag = idiag;
}

typedef const CbandComp &CbandComp_I;
typedef CbandComp &CbandComp_O, &CbandComp_IO;



} // namespace slisc
