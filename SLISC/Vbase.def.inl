VbaseLlong::VbaseLlong(Long_I N) : m_p(new Llong[N]), m_N(N) {}

VbaseLlong::VbaseLlong(const VbaseLlong &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Llong[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

Llong * VbaseLlong::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

const Llong * VbaseLlong::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

Long VbaseLlong::size() const
{
    return m_N;
}

void VbaseLlong::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Llong[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Llong[N];
            }
        }
    }
}

void VbaseLlong::operator<<(VbaseLlong &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

Llong & VbaseLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

const Llong & VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

Llong & VbaseLlong::operator()(Long_I i)
{ return (*this)[i]; }

const Llong & VbaseLlong::operator()(Long_I i) const
{ return (*this)[i]; }

Llong & VbaseLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

const Llong & VbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

Llong & VbaseLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

const Llong & VbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

VbaseLlong::~VbaseLlong()
{
    if (m_N != 0)
        delete[] m_p;
}

VbaseDoub::VbaseDoub(Long_I N) : m_p(new Doub[N]), m_N(N) {}

VbaseDoub::VbaseDoub(const VbaseDoub &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Doub[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

Doub * VbaseDoub::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

const Doub * VbaseDoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

Long VbaseDoub::size() const
{
    return m_N;
}

void VbaseDoub::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Doub[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Doub[N];
            }
        }
    }
}

void VbaseDoub::operator<<(VbaseDoub &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

Doub & VbaseDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

const Doub & VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

Doub & VbaseDoub::operator()(Long_I i)
{ return (*this)[i]; }

const Doub & VbaseDoub::operator()(Long_I i) const
{ return (*this)[i]; }

Doub & VbaseDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

const Doub & VbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

Doub & VbaseDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

const Doub & VbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

VbaseDoub::~VbaseDoub()
{
    if (m_N != 0)
        delete[] m_p;
}

VbaseComp::VbaseComp(Long_I N) : m_p(new Comp[N]), m_N(N) {}

VbaseComp::VbaseComp(const VbaseComp &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Comp[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

Comp * VbaseComp::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

const Comp * VbaseComp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

Long VbaseComp::size() const
{
    return m_N;
}

void VbaseComp::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Comp[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Comp[N];
            }
        }
    }
}

void VbaseComp::operator<<(VbaseComp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

Comp & VbaseComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

const Comp & VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

Comp & VbaseComp::operator()(Long_I i)
{ return (*this)[i]; }

const Comp & VbaseComp::operator()(Long_I i) const
{ return (*this)[i]; }

Comp & VbaseComp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

const Comp & VbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

Comp & VbaseComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

const Comp & VbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

VbaseComp::~VbaseComp()
{
    if (m_N != 0)
        delete[] m_p;
}

