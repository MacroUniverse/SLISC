#pragma once
#include "Svec.h"

namespace slisc {
class ScmatInt_c : public SvecInt_c
{
protected:
	Long m_N1, m_N2;
public:
    ScmatInt_c();
    ScmatInt_c(Long_I N1, Long_I N2);
    ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2);

	ScmatInt_c &operator=(const ScmatInt_c &) = delete;

    // === Cmat functions ===
    const Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Int *ptr, Long_I N1, Long_I N2);
	void set(const ScmatInt_c &sli);
    ~ScmatInt_c();
};

inline ScmatInt_c::ScmatInt_c() {}

inline ScmatInt_c::ScmatInt_c(Long_I N1, Long_I N2)
    : SvecInt_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt_c::ScmatInt_c(const Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt_c(N1, N2)
{
    m_p = ptr;
}


inline const Int & ScmatInt_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt_c::n1() const
{
    return m_N1;
}

inline Long ScmatInt_c::n2() const
{
    return m_N2;
}

inline void ScmatInt_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt_c::set(const Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt_c::set(const ScmatInt_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatInt_c::~ScmatInt_c() {}

typedef const ScmatInt_c & ScmatInt_I;

class ScmatInt : public SvecInt
{
protected:
	Long m_N1, m_N2;
public:
    ScmatInt();
    ScmatInt(Long_I N1, Long_I N2);
    ScmatInt(Int *ptr, Long_I N1, Long_I N2);

	operator ScmatInt_c() const;
	ScmatInt &operator=(const ScmatInt &) = delete;

    // === Cmat functions ===
    Int& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Int *ptr, Long_I N1, Long_I N2);
	void set(const ScmatInt &sli);
    ~ScmatInt();
};

inline ScmatInt::ScmatInt() {}

inline ScmatInt::ScmatInt(Long_I N1, Long_I N2)
    : SvecInt(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatInt::ScmatInt(Int *ptr, Long_I N1, Long_I N2)
    : ScmatInt(N1, N2)
{
    m_p = ptr;
}

inline ScmatInt::operator ScmatInt_c() const
{
	return *((ScmatInt_c *)this);
}

inline Int & ScmatInt::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatInt::n1() const
{
    return m_N1;
}

inline Long ScmatInt::n2() const
{
    return m_N2;
}

inline void ScmatInt::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt::set(Int * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatInt::set(const ScmatInt &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatInt::~ScmatInt() {}

typedef const ScmatInt & ScmatInt_O, & ScmatInt_IO;

class ScmatLlong_c : public SvecLlong_c
{
protected:
	Long m_N1, m_N2;
public:
    ScmatLlong_c();
    ScmatLlong_c(Long_I N1, Long_I N2);
    ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2);

	ScmatLlong_c &operator=(const ScmatLlong_c &) = delete;

    // === Cmat functions ===
    const Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Llong *ptr, Long_I N1, Long_I N2);
	void set(const ScmatLlong_c &sli);
    ~ScmatLlong_c();
};

inline ScmatLlong_c::ScmatLlong_c() {}

inline ScmatLlong_c::ScmatLlong_c(Long_I N1, Long_I N2)
    : SvecLlong_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong_c::ScmatLlong_c(const Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong_c(N1, N2)
{
    m_p = ptr;
}


inline const Llong & ScmatLlong_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong_c::n1() const
{
    return m_N1;
}

inline Long ScmatLlong_c::n2() const
{
    return m_N2;
}

inline void ScmatLlong_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong_c::set(const Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong_c::set(const ScmatLlong_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLlong_c::~ScmatLlong_c() {}

typedef const ScmatLlong_c & ScmatLlong_I;

class ScmatLlong : public SvecLlong
{
protected:
	Long m_N1, m_N2;
public:
    ScmatLlong();
    ScmatLlong(Long_I N1, Long_I N2);
    ScmatLlong(Llong *ptr, Long_I N1, Long_I N2);

	operator ScmatLlong_c() const;
	ScmatLlong &operator=(const ScmatLlong &) = delete;

    // === Cmat functions ===
    Llong& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Llong *ptr, Long_I N1, Long_I N2);
	void set(const ScmatLlong &sli);
    ~ScmatLlong();
};

inline ScmatLlong::ScmatLlong() {}

inline ScmatLlong::ScmatLlong(Long_I N1, Long_I N2)
    : SvecLlong(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatLlong::ScmatLlong(Llong *ptr, Long_I N1, Long_I N2)
    : ScmatLlong(N1, N2)
{
    m_p = ptr;
}

inline ScmatLlong::operator ScmatLlong_c() const
{
	return *((ScmatLlong_c *)this);
}

inline Llong & ScmatLlong::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatLlong::n1() const
{
    return m_N1;
}

inline Long ScmatLlong::n2() const
{
    return m_N2;
}

inline void ScmatLlong::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong::set(Llong * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatLlong::set(const ScmatLlong &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatLlong::~ScmatLlong() {}

typedef const ScmatLlong & ScmatLlong_O, & ScmatLlong_IO;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt_c ScmatLong_c;
#else
typedef ScmatLlong_c ScmatLong_c;
#endif

typedef const ScmatLong_c & ScmatLong_I;

#ifdef SLS_USE_INT_AS_LONG
typedef ScmatInt ScmatLong;
#else
typedef ScmatLlong ScmatLong;
#endif

typedef const ScmatLong & ScmatLong_O, & ScmatLong_IO;

class ScmatDoub_c : public SvecDoub_c
{
protected:
	Long m_N1, m_N2;
public:
    ScmatDoub_c();
    ScmatDoub_c(Long_I N1, Long_I N2);
    ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2);

	ScmatDoub_c &operator=(const ScmatDoub_c &) = delete;

    // === Cmat functions ===
    const Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Doub *ptr, Long_I N1, Long_I N2);
	void set(const ScmatDoub_c &sli);
    ~ScmatDoub_c();
};

inline ScmatDoub_c::ScmatDoub_c() {}

inline ScmatDoub_c::ScmatDoub_c(Long_I N1, Long_I N2)
    : SvecDoub_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub_c::ScmatDoub_c(const Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub_c(N1, N2)
{
    m_p = ptr;
}


inline const Doub & ScmatDoub_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub_c::n1() const
{
    return m_N1;
}

inline Long ScmatDoub_c::n2() const
{
    return m_N2;
}

inline void ScmatDoub_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub_c::set(const Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub_c::set(const ScmatDoub_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatDoub_c::~ScmatDoub_c() {}

typedef const ScmatDoub_c & ScmatDoub_I;

class ScmatDoub : public SvecDoub
{
protected:
	Long m_N1, m_N2;
public:
    ScmatDoub();
    ScmatDoub(Long_I N1, Long_I N2);
    ScmatDoub(Doub *ptr, Long_I N1, Long_I N2);

	operator ScmatDoub_c() const;
	ScmatDoub &operator=(const ScmatDoub &) = delete;

    // === Cmat functions ===
    Doub& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Doub *ptr, Long_I N1, Long_I N2);
	void set(const ScmatDoub &sli);
    ~ScmatDoub();
};

inline ScmatDoub::ScmatDoub() {}

inline ScmatDoub::ScmatDoub(Long_I N1, Long_I N2)
    : SvecDoub(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatDoub::ScmatDoub(Doub *ptr, Long_I N1, Long_I N2)
    : ScmatDoub(N1, N2)
{
    m_p = ptr;
}

inline ScmatDoub::operator ScmatDoub_c() const
{
	return *((ScmatDoub_c *)this);
}

inline Doub & ScmatDoub::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatDoub::n1() const
{
    return m_N1;
}

inline Long ScmatDoub::n2() const
{
    return m_N2;
}

inline void ScmatDoub::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub::set(Doub * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatDoub::set(const ScmatDoub &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatDoub::~ScmatDoub() {}

typedef const ScmatDoub & ScmatDoub_O, & ScmatDoub_IO;

class ScmatComp_c : public SvecComp_c
{
protected:
	Long m_N1, m_N2;
public:
    ScmatComp_c();
    ScmatComp_c(Long_I N1, Long_I N2);
    ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2);

	ScmatComp_c &operator=(const ScmatComp_c &) = delete;

    // === Cmat functions ===
    const Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(const Comp *ptr, Long_I N1, Long_I N2);
	void set(const ScmatComp_c &sli);
    ~ScmatComp_c();
};

inline ScmatComp_c::ScmatComp_c() {}

inline ScmatComp_c::ScmatComp_c(Long_I N1, Long_I N2)
    : SvecComp_c(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp_c::ScmatComp_c(const Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp_c(N1, N2)
{
    m_p = ptr;
}


inline const Comp & ScmatComp_c::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp_c::n1() const
{
    return m_N1;
}

inline Long ScmatComp_c::n2() const
{
    return m_N2;
}

inline void ScmatComp_c::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp_c::set(const Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp_c::set(const ScmatComp_c &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatComp_c::~ScmatComp_c() {}

typedef const ScmatComp_c & ScmatComp_I;

class ScmatComp : public SvecComp
{
protected:
	Long m_N1, m_N2;
public:
    ScmatComp();
    ScmatComp(Long_I N1, Long_I N2);
    ScmatComp(Comp *ptr, Long_I N1, Long_I N2);

	operator ScmatComp_c() const;
	ScmatComp &operator=(const ScmatComp &) = delete;

    // === Cmat functions ===
    Comp& operator()(Long_I i, Long_I j) const; // double indexing
    Long n1() const;
    Long n2() const;

    // resize() is a bad idea, don't try to create it!

    // There is no upper bound checking of N, use with care
    void set_size(Long_I N1, Long_I N2);
    void set(Comp *ptr, Long_I N1, Long_I N2);
	void set(const ScmatComp &sli);
    ~ScmatComp();
};

inline ScmatComp::ScmatComp() {}

inline ScmatComp::ScmatComp(Long_I N1, Long_I N2)
    : SvecComp(N1*N2), m_N1(N1), m_N2(N2) {}

inline ScmatComp::ScmatComp(Comp *ptr, Long_I N1, Long_I N2)
    : ScmatComp(N1, N2)
{
    m_p = ptr;
}

inline ScmatComp::operator ScmatComp_c() const
{
	return *((ScmatComp_c *)this);
}

inline Comp & ScmatComp::operator()(Long_I i, Long_I j) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i < 0 || i >= m_N1 || j < 0 || j >= m_N2)
        SLS_ERR("Matrix subscript out of bounds");
#endif
    return m_p[i + m_N1 * j];
}

inline Long ScmatComp::n1() const
{
    return m_N1;
}

inline Long ScmatComp::n2() const
{
    return m_N2;
}

inline void ScmatComp::set_size(Long_I N1, Long_I N2)
{
#ifdef SLS_CHECK_SHAPE
    if (N1 <= 0 || N2 <= 0) SLS_ERR("illegal N1 or N2!");
#endif
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp::set(Comp * ptr, Long_I N1, Long_I N2)
{
    m_p = ptr;
    m_N1 = N1; m_N2 = N2; m_N = N1 * N2;
}

inline void ScmatComp::set(const ScmatComp &sli)
{
	m_p = sli.m_p; m_N = sli.m_N; m_N1 = sli.m_N1; m_N2 = sli.m_N2;
}

inline ScmatComp::~ScmatComp() {}

typedef const ScmatComp & ScmatComp_O, & ScmatComp_IO;

} // namespace slisc
