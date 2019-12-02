class VbaseInt
{
protected:
    Int *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Int value_type;
    // constructors
    explicit VbaseInt(Long_I N);
    VbaseInt(const VbaseInt &rhs); // copy constructor

    // get properties
    Int* ptr(); // get pointer
    const Int* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Int & operator[](Long_I i);
    const Int & operator[](Long_I i) const;
    Int & operator()(Long_I i);
    const Int & operator()(Long_I i) const;
    Int& end();
    const Int& end() const;
    Int& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Int& end(Long_I i) const;
    void operator<<(VbaseInt &rhs); // move data
    ~VbaseInt();
};

inline VbaseInt::VbaseInt(Long_I N) : m_p(new Int[N]), m_N(N) {}

inline VbaseInt::VbaseInt(const VbaseInt &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Int[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Int * VbaseInt::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Int * VbaseInt::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseInt::size() const
{
    return m_N;
}

inline void VbaseInt::resize(Long_I N)
{
    if (N != m_N) {
        if (m_N == 0) {
            m_N = N; m_p = new Int[N];
        }
        else { // m_N != 0
            delete[] m_p;
            if (N == 0)
                m_N = 0;
            else {
                m_N = N;
                m_p = new Int[N];
            }
        }
    }
}

inline void VbaseInt::operator<<(VbaseInt &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Int & VbaseInt::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseInt subscript out of bounds");
#endif
    return m_p[i];
}

inline const Int & VbaseInt::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseInt subscript out of bounds");
#endif
    return m_p[i];
}

inline Int & VbaseInt::operator()(Long_I i)
{ return (*this)[i]; }

inline const Int & VbaseInt::operator()(Long_I i) const
{ return (*this)[i]; }

inline Int & VbaseInt::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Int & VbaseInt::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Int & VbaseInt::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Int & VbaseInt::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseInt::~VbaseInt()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseLlong
{
protected:
    Llong *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Llong value_type;
    // constructors
    explicit VbaseLlong(Long_I N);
    VbaseLlong(const VbaseLlong &rhs); // copy constructor

    // get properties
    Llong* ptr(); // get pointer
    const Llong* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Llong & operator[](Long_I i);
    const Llong & operator[](Long_I i) const;
    Llong & operator()(Long_I i);
    const Llong & operator()(Long_I i) const;
    Llong& end();
    const Llong& end() const;
    Llong& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Llong& end(Long_I i) const;
    void operator<<(VbaseLlong &rhs); // move data
    ~VbaseLlong();
};

inline VbaseLlong::VbaseLlong(Long_I N) : m_p(new Llong[N]), m_N(N) {}

inline VbaseLlong::VbaseLlong(const VbaseLlong &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Llong[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Llong * VbaseLlong::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Llong * VbaseLlong::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseLlong::size() const
{
    return m_N;
}

inline void VbaseLlong::resize(Long_I N)
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

inline void VbaseLlong::operator<<(VbaseLlong &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Llong & VbaseLlong::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

inline const Llong & VbaseLlong::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseLlong subscript out of bounds");
#endif
    return m_p[i];
}

inline Llong & VbaseLlong::operator()(Long_I i)
{ return (*this)[i]; }

inline const Llong & VbaseLlong::operator()(Long_I i) const
{ return (*this)[i]; }

inline Llong & VbaseLlong::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Llong & VbaseLlong::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Llong & VbaseLlong::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Llong & VbaseLlong::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseLlong::~VbaseLlong()
{
    if (m_N != 0)
        delete[] m_p;
}

#ifdef SLS_USE_INT_AS_LONG
typedef VbaseInt VbaseLong;
#else
typedef VbaseLlong VbaseLong;
#endif

class VbaseDoub
{
protected:
    Doub *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Doub value_type;
    // constructors
    explicit VbaseDoub(Long_I N);
    VbaseDoub(const VbaseDoub &rhs); // copy constructor

    // get properties
    Doub* ptr(); // get pointer
    const Doub* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Doub & operator[](Long_I i);
    const Doub & operator[](Long_I i) const;
    Doub & operator()(Long_I i);
    const Doub & operator()(Long_I i) const;
    Doub& end();
    const Doub& end() const;
    Doub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Doub& end(Long_I i) const;
    void operator<<(VbaseDoub &rhs); // move data
    ~VbaseDoub();
};

inline VbaseDoub::VbaseDoub(Long_I N) : m_p(new Doub[N]), m_N(N) {}

inline VbaseDoub::VbaseDoub(const VbaseDoub &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Doub[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Doub * VbaseDoub::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Doub * VbaseDoub::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseDoub::size() const
{
    return m_N;
}

inline void VbaseDoub::resize(Long_I N)
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

inline void VbaseDoub::operator<<(VbaseDoub &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Doub & VbaseDoub::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

inline const Doub & VbaseDoub::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseDoub subscript out of bounds");
#endif
    return m_p[i];
}

inline Doub & VbaseDoub::operator()(Long_I i)
{ return (*this)[i]; }

inline const Doub & VbaseDoub::operator()(Long_I i) const
{ return (*this)[i]; }

inline Doub & VbaseDoub::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Doub & VbaseDoub::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Doub & VbaseDoub::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Doub & VbaseDoub::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseDoub::~VbaseDoub()
{
    if (m_N != 0)
        delete[] m_p;
}

class VbaseComp
{
protected:
    Comp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Comp value_type;
    // constructors
    explicit VbaseComp(Long_I N);
    VbaseComp(const VbaseComp &rhs); // copy constructor

    // get properties
    Comp* ptr(); // get pointer
    const Comp* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Comp & operator[](Long_I i);
    const Comp & operator[](Long_I i) const;
    Comp & operator()(Long_I i);
    const Comp & operator()(Long_I i) const;
    Comp& end();
    const Comp& end() const;
    Comp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Comp& end(Long_I i) const;
    void operator<<(VbaseComp &rhs); // move data
    ~VbaseComp();
};

inline VbaseComp::VbaseComp(Long_I N) : m_p(new Comp[N]), m_N(N) {}

inline VbaseComp::VbaseComp(const VbaseComp &rhs)
{
#ifndef SLS_ALLOW_COPY_CONSTRUCTOR
    SLS_ERR("Copy constructor or move constructor is forbidden!");
#endif
    // m_N = rhs.m_N;
    // m_p = new Comp[rhs.m_N];
    // veccpy(m_p, rhs.ptr(), m_N);
}

inline Comp * VbaseComp::ptr()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline const Comp * VbaseComp::ptr() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("using ptr() for empty container!");
#endif
    return m_p;
}

inline Long VbaseComp::size() const
{
    return m_N;
}

inline void VbaseComp::resize(Long_I N)
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

inline void VbaseComp::operator<<(VbaseComp &rhs)
{
    if (this == &rhs)
        SLS_ERR("self move is forbidden!");
    if (m_N != 0)
        delete[] m_p;
    m_N = rhs.m_N; rhs.m_N = 0;
    m_p = rhs.m_p;
}

inline Comp & VbaseComp::operator[](Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
if (i<0 || i>=m_N)
    SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

inline const Comp & VbaseComp::operator[](Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i<0 || i>=m_N)
        SLS_ERR("VbaseComp subscript out of bounds");
#endif
    return m_p[i];
}

inline Comp & VbaseComp::operator()(Long_I i)
{ return (*this)[i]; }

inline const Comp & VbaseComp::operator()(Long_I i) const
{ return (*this)[i]; }

inline Comp & VbaseComp::end()
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline const Comp & VbaseComp::end() const
{
#ifdef SLS_CHECK_BOUNDS
    if (m_N == 0)
        SLS_ERR("tring to use end() on empty vector!");
#endif
    return m_p[m_N - 1];
}

inline Comp & VbaseComp::end(Long_I i)
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline const Comp & VbaseComp::end(Long_I i) const
{
#ifdef SLS_CHECK_BOUNDS
    if (i <= 0 || i > m_N)
        SLS_ERR("index out of bound");
#endif
    return m_p[m_N - i];
}

inline VbaseComp::~VbaseComp()
{
    if (m_N != 0)
        delete[] m_p;
}

