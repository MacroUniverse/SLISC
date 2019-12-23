// band diagonal matrix class
#pragma once
#include "Cmat.h"

namespace slisc {

class CbandInt
{
public:
    Long m_N1;
    Long m_Nup;
    Long m_Nlow;
	Long m_idiag; // position of diagonal
    CmatInt m_a;

    CbandInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

    Int * ptr();
    const Int * ptr() const;
	Int operator()(Long_I i, Long_I j) const;
	Int &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
	Long size() const;
    Long nup() const;
    Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatInt &cmat();
	const CmatInt &cmat() const;
	void resize(Long_I lda, Long_I N2);
	void reshape(Long_I N1, Long_I Nup, Long_I Nlow);
	void shift(Long_I idiag);
};

inline CbandInt::CbandInt(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
    m_N1(N1), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N2)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < m_Nup || m_a.n1() - m_idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
}

inline Int * CbandInt::ptr()
{
    return m_a.ptr();
}

inline const Int * CbandInt::ptr() const
{
    return m_a.ptr();
}

inline Int CbandInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_idiag + i - j, j);
}

inline Int &CbandInt::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_idiag + i - j, j);
}

inline Long CbandInt::n1() const
{
    return m_N1;
}

inline Long CbandInt::n2() const
{
    return m_a.n2();
}

inline Long CbandInt::size() const
{
	return n1() * n2();
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
    return m_a.n1();
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

inline void CbandInt::resize(Long_I lda, Long_I N2)
{
	m_a.resize(lda, N2);
}

inline void CbandInt::reshape(Long_I N1, Long_I Nup, Long_I Nlow)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_N1 = N1; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandInt::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPE
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_idiag = idiag;
}

typedef const CbandInt & CbandInt_I;
typedef CbandInt & CbandInt_O, & CbandInt_IO;

class CbandDoub
{
public:
    Long m_N1;
    Long m_Nup;
    Long m_Nlow;
	Long m_idiag; // position of diagonal
    CmatDoub m_a;

    CbandDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

    Doub * ptr();
    const Doub * ptr() const;
	Doub operator()(Long_I i, Long_I j) const;
	Doub &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
	Long size() const;
    Long nup() const;
    Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatDoub &cmat();
	const CmatDoub &cmat() const;
	void resize(Long_I lda, Long_I N2);
	void reshape(Long_I N1, Long_I Nup, Long_I Nlow);
	void shift(Long_I idiag);
};

inline CbandDoub::CbandDoub(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
    m_N1(N1), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N2)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < m_Nup || m_a.n1() - m_idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
}

inline Doub * CbandDoub::ptr()
{
    return m_a.ptr();
}

inline const Doub * CbandDoub::ptr() const
{
    return m_a.ptr();
}

inline Doub CbandDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_idiag + i - j, j);
}

inline Doub &CbandDoub::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_idiag + i - j, j);
}

inline Long CbandDoub::n1() const
{
    return m_N1;
}

inline Long CbandDoub::n2() const
{
    return m_a.n2();
}

inline Long CbandDoub::size() const
{
	return n1() * n2();
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
    return m_a.n1();
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

inline void CbandDoub::resize(Long_I lda, Long_I N2)
{
	m_a.resize(lda, N2);
}

inline void CbandDoub::reshape(Long_I N1, Long_I Nup, Long_I Nlow)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_N1 = N1; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandDoub::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPE
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_idiag = idiag;
}

typedef const CbandDoub & CbandDoub_I;
typedef CbandDoub & CbandDoub_O, & CbandDoub_IO;

class CbandComp
{
public:
    Long m_N1;
    Long m_Nup;
    Long m_Nlow;
	Long m_idiag; // position of diagonal
    CmatComp m_a;

    CbandComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda = -1, Long_I idiag = -1);

    Comp * ptr();
    const Comp * ptr() const;
	Comp operator()(Long_I i, Long_I j) const;
	Comp &ref(Long_I i, Long_I j);
    Long n1() const;
    Long n2() const;
	Long size() const;
    Long nup() const;
    Long nlow() const;
	Long lda() const;
	Long idiag() const;
	CmatComp &cmat();
	const CmatComp &cmat() const;
	void resize(Long_I lda, Long_I N2);
	void reshape(Long_I N1, Long_I Nup, Long_I Nlow);
	void shift(Long_I idiag);
};

inline CbandComp::CbandComp(Long_I N1, Long_I N2, Long_I Nup, Long_I Nlow, Long_I lda, Long_I idiag):
    m_N1(N1), m_Nup(Nup), m_Nlow(Nlow), m_idiag(idiag < 0 ? Nup : idiag), m_a(lda < 0? Nup + Nlow + 1 : lda, N2)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < m_Nup || m_a.n1() - m_idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
}

inline Comp * CbandComp::ptr()
{
    return m_a.ptr();
}

inline const Comp * CbandComp::ptr() const
{
    return m_a.ptr();
}

inline Comp CbandComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		return 0;
    return m_a(m_idiag + i - j, j);
}

inline Comp &CbandComp::ref(Long_I i, Long_I j)
{
#ifdef SLS_CHECK_BOUNDS
	if (i < 0 || i >= m_N1 || j < 0 || j >= n2())
		SLS_ERR("index out of bound!");
#endif
	if (i - j > m_Nlow || j - i > m_Nup)
		SLS_ERR("index out of band!");
    return m_a(m_idiag + i - j, j);
}

inline Long CbandComp::n1() const
{
    return m_N1;
}

inline Long CbandComp::n2() const
{
    return m_a.n2();
}

inline Long CbandComp::size() const
{
	return n1() * n2();
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
    return m_a.n1();
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

inline void CbandComp::resize(Long_I lda, Long_I N2)
{
	m_a.resize(lda, N2);
}

inline void CbandComp::reshape(Long_I N1, Long_I Nup, Long_I Nlow)
{
#ifdef SLS_CHECK_SHAPE
	if (m_idiag < Nup || lda() - m_idiag - 1 < Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_N1 = N1; m_Nup = Nup; m_Nlow = Nlow;
}

inline void CbandComp::shift(Long_I idiag)
{
#ifdef SLS_CHECK_SHAPE
	if (idiag < m_Nup || lda() - idiag - 1 < m_Nlow)
		SLS_ERR("wrong shape!");
#endif
	m_idiag = idiag;
}

typedef const CbandComp & CbandComp_I;
typedef CbandComp & CbandComp_O, & CbandComp_IO;

} // namespace slisc
