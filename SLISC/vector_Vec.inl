class VecBool : public Vbase<Bool>
{
protected:
    typedef Vbase<Bool> Base;
    using Base::m_p;
    using Base::m_N;
    VecBool();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecBool(Long_I N);
    VecBool(Long_I N, Bool_I s); // initialize to constant value
    VecBool(Long_I N, const Bool *a); // copy from existing memory
	VecBool(const VecBool &rhs); // copy constructor

    VecBool &operator=(const VecBool &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecBool &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecBool &operator=(const Tv &rhs);
    void operator<<(VecBool &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecBool & operator=(const Gvector<Bool> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecBool::VecBool() {}

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(Long_I N, Bool_I s) : VecBool(N)
{
    *this = s;
}

inline VecBool::VecBool(Long_I N, const Bool * a) : VecBool(N)
{
    veccpy(m_p, a, N);
}

VecBool::VecBool(const VecBool &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecBool &VecBool::operator=(VecBool_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecBool &VecBool::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecBool &VecBool::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecBool::operator<<(VecBool &rhs)
{
    Base::operator<<(rhs);
}

class VecChar : public Vbase<Char>
{
protected:
    typedef Vbase<Char> Base;
    using Base::m_p;
    using Base::m_N;
    VecChar();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecChar(Long_I N);
    VecChar(Long_I N, Char_I s); // initialize to constant value
    VecChar(Long_I N, const Char *a); // copy from existing memory
	VecChar(const VecChar &rhs); // copy constructor

    VecChar &operator=(const VecChar &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecChar &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecChar &operator=(const Tv &rhs);
    void operator<<(VecChar &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecChar & operator=(const Gvector<Char> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecChar::VecChar() {}

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(Long_I N, Char_I s) : VecChar(N)
{
    *this = s;
}

inline VecChar::VecChar(Long_I N, const Char * a) : VecChar(N)
{
    veccpy(m_p, a, N);
}

VecChar::VecChar(const VecChar &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecChar &VecChar::operator=(VecChar_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecChar &VecChar::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecChar &VecChar::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecChar::operator<<(VecChar &rhs)
{
    Base::operator<<(rhs);
}

class VecInt : public Vbase<Int>
{
protected:
    typedef Vbase<Int> Base;
    using Base::m_p;
    using Base::m_N;
    VecInt();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecInt(Long_I N);
    VecInt(Long_I N, Int_I s); // initialize to constant value
    VecInt(Long_I N, const Int *a); // copy from existing memory
	VecInt(const VecInt &rhs); // copy constructor

    VecInt &operator=(const VecInt &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecInt &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecInt &operator=(const Tv &rhs);
    void operator<<(VecInt &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecInt & operator=(const Gvector<Int> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecInt::VecInt() {}

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(Long_I N, Int_I s) : VecInt(N)
{
    *this = s;
}

inline VecInt::VecInt(Long_I N, const Int * a) : VecInt(N)
{
    veccpy(m_p, a, N);
}

VecInt::VecInt(const VecInt &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecInt &VecInt::operator=(VecInt_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecInt &VecInt::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecInt &VecInt::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecInt::operator<<(VecInt &rhs)
{
    Base::operator<<(rhs);
}

class VecLlong : public Vbase<Llong>
{
protected:
    typedef Vbase<Llong> Base;
    using Base::m_p;
    using Base::m_N;
    VecLlong();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecLlong(Long_I N);
    VecLlong(Long_I N, Llong_I s); // initialize to constant value
    VecLlong(Long_I N, const Llong *a); // copy from existing memory
	VecLlong(const VecLlong &rhs); // copy constructor

    VecLlong &operator=(const VecLlong &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecLlong &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecLlong &operator=(const Tv &rhs);
    void operator<<(VecLlong &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecLlong & operator=(const Gvector<Llong> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecLlong::VecLlong() {}

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(Long_I N, Llong_I s) : VecLlong(N)
{
    *this = s;
}

inline VecLlong::VecLlong(Long_I N, const Llong * a) : VecLlong(N)
{
    veccpy(m_p, a, N);
}

VecLlong::VecLlong(const VecLlong &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecLlong &VecLlong::operator=(VecLlong_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecLlong &VecLlong::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecLlong &VecLlong::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecLlong::operator<<(VecLlong &rhs)
{
    Base::operator<<(rhs);
}

class VecFloat : public Vbase<Float>
{
protected:
    typedef Vbase<Float> Base;
    using Base::m_p;
    using Base::m_N;
    VecFloat();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecFloat(Long_I N);
    VecFloat(Long_I N, Float_I s); // initialize to constant value
    VecFloat(Long_I N, const Float *a); // copy from existing memory
	VecFloat(const VecFloat &rhs); // copy constructor

    VecFloat &operator=(const VecFloat &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecFloat &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecFloat &operator=(const Tv &rhs);
    void operator<<(VecFloat &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecFloat & operator=(const Gvector<Float> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecFloat::VecFloat() {}

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(Long_I N, Float_I s) : VecFloat(N)
{
    *this = s;
}

inline VecFloat::VecFloat(Long_I N, const Float * a) : VecFloat(N)
{
    veccpy(m_p, a, N);
}

VecFloat::VecFloat(const VecFloat &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecFloat &VecFloat::operator=(VecFloat_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecFloat &VecFloat::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecFloat &VecFloat::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecFloat::operator<<(VecFloat &rhs)
{
    Base::operator<<(rhs);
}

class VecDoub : public Vbase<Doub>
{
protected:
    typedef Vbase<Doub> Base;
    using Base::m_p;
    using Base::m_N;
    VecDoub();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecDoub(Long_I N);
    VecDoub(Long_I N, Doub_I s); // initialize to constant value
    VecDoub(Long_I N, const Doub *a); // copy from existing memory
	VecDoub(const VecDoub &rhs); // copy constructor

    VecDoub &operator=(const VecDoub &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecDoub &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecDoub &operator=(const Tv &rhs);
    void operator<<(VecDoub &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecDoub & operator=(const Gvector<Doub> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecDoub::VecDoub() {}

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(Long_I N, Doub_I s) : VecDoub(N)
{
    *this = s;
}

inline VecDoub::VecDoub(Long_I N, const Doub * a) : VecDoub(N)
{
    veccpy(m_p, a, N);
}

VecDoub::VecDoub(const VecDoub &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecDoub &VecDoub::operator=(VecDoub_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecDoub &VecDoub::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecDoub &VecDoub::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecDoub::operator<<(VecDoub &rhs)
{
    Base::operator<<(rhs);
}

class VecLdoub : public Vbase<Ldoub>
{
protected:
    typedef Vbase<Ldoub> Base;
    using Base::m_p;
    using Base::m_N;
    VecLdoub();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecLdoub(Long_I N);
    VecLdoub(Long_I N, Ldoub_I s); // initialize to constant value
    VecLdoub(Long_I N, const Ldoub *a); // copy from existing memory
	VecLdoub(const VecLdoub &rhs); // copy constructor

    VecLdoub &operator=(const VecLdoub &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecLdoub &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecLdoub &operator=(const Tv &rhs);
    void operator<<(VecLdoub &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecLdoub & operator=(const Gvector<Ldoub> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecLdoub::VecLdoub() {}

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(Long_I N, Ldoub_I s) : VecLdoub(N)
{
    *this = s;
}

inline VecLdoub::VecLdoub(Long_I N, const Ldoub * a) : VecLdoub(N)
{
    veccpy(m_p, a, N);
}

VecLdoub::VecLdoub(const VecLdoub &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecLdoub &VecLdoub::operator=(VecLdoub_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecLdoub &VecLdoub::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecLdoub &VecLdoub::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecLdoub::operator<<(VecLdoub &rhs)
{
    Base::operator<<(rhs);
}

class VecFcomp : public Vbase<Fcomp>
{
protected:
    typedef Vbase<Fcomp> Base;
    using Base::m_p;
    using Base::m_N;
    VecFcomp();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecFcomp(Long_I N);
    VecFcomp(Long_I N, Fcomp_I s); // initialize to constant value
    VecFcomp(Long_I N, const Fcomp *a); // copy from existing memory
	VecFcomp(const VecFcomp &rhs); // copy constructor

    VecFcomp &operator=(const VecFcomp &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecFcomp &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecFcomp &operator=(const Tv &rhs);
    void operator<<(VecFcomp &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecFcomp & operator=(const Gvector<Fcomp> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecFcomp::VecFcomp() {}

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(Long_I N, Fcomp_I s) : VecFcomp(N)
{
    *this = s;
}

inline VecFcomp::VecFcomp(Long_I N, const Fcomp * a) : VecFcomp(N)
{
    veccpy(m_p, a, N);
}

VecFcomp::VecFcomp(const VecFcomp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecFcomp &VecFcomp::operator=(VecFcomp_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecFcomp &VecFcomp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecFcomp &VecFcomp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecFcomp::operator<<(VecFcomp &rhs)
{
    Base::operator<<(rhs);
}

class VecComp : public Vbase<Comp>
{
protected:
    typedef Vbase<Comp> Base;
    using Base::m_p;
    using Base::m_N;
    VecComp();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecComp(Long_I N);
    VecComp(Long_I N, Comp_I s); // initialize to constant value
    VecComp(Long_I N, const Comp *a); // copy from existing memory
	VecComp(const VecComp &rhs); // copy constructor

    VecComp &operator=(const VecComp &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecComp &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecComp &operator=(const Tv &rhs);
    void operator<<(VecComp &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecComp & operator=(const Gvector<Comp> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecComp::VecComp() {}

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(Long_I N, Comp_I s) : VecComp(N)
{
    *this = s;
}

inline VecComp::VecComp(Long_I N, const Comp * a) : VecComp(N)
{
    veccpy(m_p, a, N);
}

VecComp::VecComp(const VecComp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecComp &VecComp::operator=(VecComp_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecComp &VecComp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecComp &VecComp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecComp::operator<<(VecComp &rhs)
{
    Base::operator<<(rhs);
}

class VecLcomp : public Vbase<Lcomp>
{
protected:
    typedef Vbase<Lcomp> Base;
    using Base::m_p;
    using Base::m_N;
    VecLcomp();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecLcomp(Long_I N);
    VecLcomp(Long_I N, Lcomp_I s); // initialize to constant value
    VecLcomp(Long_I N, const Lcomp *a); // copy from existing memory
	VecLcomp(const VecLcomp &rhs); // copy constructor

    VecLcomp &operator=(const VecLcomp &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecLcomp &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecLcomp &operator=(const Tv &rhs);
    void operator<<(VecLcomp &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecLcomp & operator=(const Gvector<Lcomp> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecLcomp::VecLcomp() {}

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(Long_I N, Lcomp_I s) : VecLcomp(N)
{
    *this = s;
}

inline VecLcomp::VecLcomp(Long_I N, const Lcomp * a) : VecLcomp(N)
{
    veccpy(m_p, a, N);
}

VecLcomp::VecLcomp(const VecLcomp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecLcomp &VecLcomp::operator=(VecLcomp_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecLcomp &VecLcomp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecLcomp &VecLcomp::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecLcomp::operator<<(VecLcomp &rhs)
{
    Base::operator<<(rhs);
}

class VecImag : public Vbase<Imag>
{
protected:
    typedef Vbase<Imag> Base;
    using Base::m_p;
    using Base::m_N;
    VecImag();
public:
    using Base::resize;
    using Base::resize_cpy;
    using Base::operator=;

    explicit VecImag(Long_I N);
    VecImag(Long_I N, Imag_I s); // initialize to constant value
    VecImag(Long_I N, const Imag *a); // copy from existing memory
	VecImag(const VecImag &rhs); // copy constructor

    VecImag &operator=(const VecImag &rhs);
    template <class Tv, SLS_IF(is_dense_vec<Tv>())>
    VecImag &operator=(const Tv &rhs);
    template <class Tv, SLS_IF(is_Dvector<Tv>())>
    VecImag &operator=(const Tv &rhs);
    void operator<<(VecImag &rhs); // move data and rhs.resize(0)
#ifdef SLS_CUSLISC
    VecImag & operator=(const Gvector<Imag> &rhs) // copy from GPU vector
    { rhs.get(*this); return *this; }
#endif
};

inline VecImag::VecImag() {}

inline VecImag::VecImag(Long_I N) : Base(N) {}

inline VecImag::VecImag(Long_I N, Imag_I s) : VecImag(N)
{
    *this = s;
}

inline VecImag::VecImag(Long_I N, const Imag * a) : VecImag(N)
{
    veccpy(m_p, a, N);
}

VecImag::VecImag(const VecImag &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

VecImag &VecImag::operator=(VecImag_I rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_dense_vec<Tv>())>
VecImag &VecImag::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

template <class Tv, SLS_IF0(is_Dvector<Tv>())>
VecImag &VecImag::operator=(const Tv &rhs)
{
    copy(*this, rhs);
    return *this;
}

inline void VecImag::operator<<(VecImag &rhs)
{
    Base::operator<<(rhs);
}

