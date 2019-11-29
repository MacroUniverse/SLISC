//% type = {'Bool'; 'Char'; 'Int'; 'Llong'; 'Float'; 'Doub';...
//%     'Ldoub'; 'Fcomp'; 'Comp'; 'Lcomp';};
//%----------------------------------------------
class VbaseBool
{
protected:
    Bool *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Bool value_type;
    // constructors
    explicit VbaseBool(Long_I N);
    VbaseBool(const VbaseBool &rhs); // copy constructor

    // get properties
    Bool* ptr(); // get pointer
    const Bool* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Bool & operator[](Long_I i);
    const Bool & operator[](Long_I i) const;
    Bool & operator()(Long_I i);
    const Bool & operator()(Long_I i) const;
    Bool& end();
    const Bool& end() const;
    Bool& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Bool& end(Long_I i) const;
    void operator<<(VbaseBool &rhs); // move data
    ~VbaseBool();
};

class VbaseChar
{
protected:
    Char *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Char value_type;
    // constructors
    explicit VbaseChar(Long_I N);
    VbaseChar(const VbaseChar &rhs); // copy constructor

    // get properties
    Char* ptr(); // get pointer
    const Char* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Char & operator[](Long_I i);
    const Char & operator[](Long_I i) const;
    Char & operator()(Long_I i);
    const Char & operator()(Long_I i) const;
    Char& end();
    const Char& end() const;
    Char& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Char& end(Long_I i) const;
    void operator<<(VbaseChar &rhs); // move data
    ~VbaseChar();
};

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

class VbaseFloat
{
protected:
    Float *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Float value_type;
    // constructors
    explicit VbaseFloat(Long_I N);
    VbaseFloat(const VbaseFloat &rhs); // copy constructor

    // get properties
    Float* ptr(); // get pointer
    const Float* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Float & operator[](Long_I i);
    const Float & operator[](Long_I i) const;
    Float & operator()(Long_I i);
    const Float & operator()(Long_I i) const;
    Float& end();
    const Float& end() const;
    Float& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Float& end(Long_I i) const;
    void operator<<(VbaseFloat &rhs); // move data
    ~VbaseFloat();
};

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

class VbaseLdoub
{
protected:
    Ldoub *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Ldoub value_type;
    // constructors
    explicit VbaseLdoub(Long_I N);
    VbaseLdoub(const VbaseLdoub &rhs); // copy constructor

    // get properties
    Ldoub* ptr(); // get pointer
    const Ldoub* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Ldoub & operator[](Long_I i);
    const Ldoub & operator[](Long_I i) const;
    Ldoub & operator()(Long_I i);
    const Ldoub & operator()(Long_I i) const;
    Ldoub& end();
    const Ldoub& end() const;
    Ldoub& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Ldoub& end(Long_I i) const;
    void operator<<(VbaseLdoub &rhs); // move data
    ~VbaseLdoub();
};

class VbaseFcomp
{
protected:
    Fcomp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Fcomp value_type;
    // constructors
    explicit VbaseFcomp(Long_I N);
    VbaseFcomp(const VbaseFcomp &rhs); // copy constructor

    // get properties
    Fcomp* ptr(); // get pointer
    const Fcomp* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Fcomp & operator[](Long_I i);
    const Fcomp & operator[](Long_I i) const;
    Fcomp & operator()(Long_I i);
    const Fcomp & operator()(Long_I i) const;
    Fcomp& end();
    const Fcomp& end() const;
    Fcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Fcomp& end(Long_I i) const;
    void operator<<(VbaseFcomp &rhs); // move data
    ~VbaseFcomp();
};

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

class VbaseLcomp
{
protected:
    Lcomp *m_p; // pointer to the first element
    Long m_N; // number of elements
public:
    typedef Lcomp value_type;
    // constructors
    explicit VbaseLcomp(Long_I N);
    VbaseLcomp(const VbaseLcomp &rhs); // copy constructor

    // get properties
    Lcomp* ptr(); // get pointer
    const Lcomp* ptr() const;
    Long size() const;
    void resize(Long_I N);
    Lcomp & operator[](Long_I i);
    const Lcomp & operator[](Long_I i) const;
    Lcomp & operator()(Long_I i);
    const Lcomp & operator()(Long_I i) const;
    Lcomp& end();
    const Lcomp& end() const;
    Lcomp& end(Long_I i); // i = 1 for the last, i = 2 for the second last...
    const Lcomp& end(Long_I i) const;
    void operator<<(VbaseLcomp &rhs); // move data
    ~VbaseLcomp();
};

