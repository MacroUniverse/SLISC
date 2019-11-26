void veccpy(Bool *dst, const Bool *src, Long_I N);
void veccpy(Bool *dst, Bool_I src, Long_I N);

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
	using Base::operator[];

    explicit VecBool(Long_I N);
    VecBool(Long_I N, Bool_I s); // initialize to constant value
    VecBool(Long_I N, const Bool *a); // copy from existing memory
	VecBool(const VecBool &rhs); // copy constructor
    void operator<<(VecBool &rhs); // move data and rhs.resize(0)
};

inline VecBool::VecBool() {}

inline VecBool::VecBool(Long_I N) : Base(N) {}

inline VecBool::VecBool(Long_I N, Bool_I s) : VecBool(N)
{
    veccpy(m_p, s, N);
}

inline VecBool::VecBool(Long_I N, const Bool * a) : VecBool(N)
{
    veccpy(m_p, a, N);
}

VecBool::VecBool(const VecBool &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecBool::operator<<(VecBool &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Char *dst, const Char *src, Long_I N);
void veccpy(Char *dst, Char_I src, Long_I N);

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
	using Base::operator[];

    explicit VecChar(Long_I N);
    VecChar(Long_I N, Char_I s); // initialize to constant value
    VecChar(Long_I N, const Char *a); // copy from existing memory
	VecChar(const VecChar &rhs); // copy constructor
    void operator<<(VecChar &rhs); // move data and rhs.resize(0)
};

inline VecChar::VecChar() {}

inline VecChar::VecChar(Long_I N) : Base(N) {}

inline VecChar::VecChar(Long_I N, Char_I s) : VecChar(N)
{
    veccpy(m_p, s, N);
}

inline VecChar::VecChar(Long_I N, const Char * a) : VecChar(N)
{
    veccpy(m_p, a, N);
}

VecChar::VecChar(const VecChar &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecChar::operator<<(VecChar &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Int *dst, const Int *src, Long_I N);
void veccpy(Int *dst, Int_I src, Long_I N);

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
	using Base::operator[];

    explicit VecInt(Long_I N);
    VecInt(Long_I N, Int_I s); // initialize to constant value
    VecInt(Long_I N, const Int *a); // copy from existing memory
	VecInt(const VecInt &rhs); // copy constructor
    void operator<<(VecInt &rhs); // move data and rhs.resize(0)
};

inline VecInt::VecInt() {}

inline VecInt::VecInt(Long_I N) : Base(N) {}

inline VecInt::VecInt(Long_I N, Int_I s) : VecInt(N)
{
    veccpy(m_p, s, N);
}

inline VecInt::VecInt(Long_I N, const Int * a) : VecInt(N)
{
    veccpy(m_p, a, N);
}

VecInt::VecInt(const VecInt &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecInt::operator<<(VecInt &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Llong *dst, const Llong *src, Long_I N);
void veccpy(Llong *dst, Llong_I src, Long_I N);

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
	using Base::operator[];

    explicit VecLlong(Long_I N);
    VecLlong(Long_I N, Llong_I s); // initialize to constant value
    VecLlong(Long_I N, const Llong *a); // copy from existing memory
	VecLlong(const VecLlong &rhs); // copy constructor
    void operator<<(VecLlong &rhs); // move data and rhs.resize(0)
};

inline VecLlong::VecLlong() {}

inline VecLlong::VecLlong(Long_I N) : Base(N) {}

inline VecLlong::VecLlong(Long_I N, Llong_I s) : VecLlong(N)
{
    veccpy(m_p, s, N);
}

inline VecLlong::VecLlong(Long_I N, const Llong * a) : VecLlong(N)
{
    veccpy(m_p, a, N);
}

VecLlong::VecLlong(const VecLlong &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecLlong::operator<<(VecLlong &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Float *dst, const Float *src, Long_I N);
void veccpy(Float *dst, Float_I src, Long_I N);

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
	using Base::operator[];

    explicit VecFloat(Long_I N);
    VecFloat(Long_I N, Float_I s); // initialize to constant value
    VecFloat(Long_I N, const Float *a); // copy from existing memory
	VecFloat(const VecFloat &rhs); // copy constructor
    void operator<<(VecFloat &rhs); // move data and rhs.resize(0)
};

inline VecFloat::VecFloat() {}

inline VecFloat::VecFloat(Long_I N) : Base(N) {}

inline VecFloat::VecFloat(Long_I N, Float_I s) : VecFloat(N)
{
    veccpy(m_p, s, N);
}

inline VecFloat::VecFloat(Long_I N, const Float * a) : VecFloat(N)
{
    veccpy(m_p, a, N);
}

VecFloat::VecFloat(const VecFloat &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecFloat::operator<<(VecFloat &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Doub *dst, const Doub *src, Long_I N);
void veccpy(Doub *dst, Doub_I src, Long_I N);

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
	using Base::operator[];

    explicit VecDoub(Long_I N);
    VecDoub(Long_I N, Doub_I s); // initialize to constant value
    VecDoub(Long_I N, const Doub *a); // copy from existing memory
	VecDoub(const VecDoub &rhs); // copy constructor
    void operator<<(VecDoub &rhs); // move data and rhs.resize(0)
};

inline VecDoub::VecDoub() {}

inline VecDoub::VecDoub(Long_I N) : Base(N) {}

inline VecDoub::VecDoub(Long_I N, Doub_I s) : VecDoub(N)
{
    veccpy(m_p, s, N);
}

inline VecDoub::VecDoub(Long_I N, const Doub * a) : VecDoub(N)
{
    veccpy(m_p, a, N);
}

VecDoub::VecDoub(const VecDoub &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecDoub::operator<<(VecDoub &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Ldoub *dst, const Ldoub *src, Long_I N);
void veccpy(Ldoub *dst, Ldoub_I src, Long_I N);

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
	using Base::operator[];

    explicit VecLdoub(Long_I N);
    VecLdoub(Long_I N, Ldoub_I s); // initialize to constant value
    VecLdoub(Long_I N, const Ldoub *a); // copy from existing memory
	VecLdoub(const VecLdoub &rhs); // copy constructor
    void operator<<(VecLdoub &rhs); // move data and rhs.resize(0)
};

inline VecLdoub::VecLdoub() {}

inline VecLdoub::VecLdoub(Long_I N) : Base(N) {}

inline VecLdoub::VecLdoub(Long_I N, Ldoub_I s) : VecLdoub(N)
{
    veccpy(m_p, s, N);
}

inline VecLdoub::VecLdoub(Long_I N, const Ldoub * a) : VecLdoub(N)
{
    veccpy(m_p, a, N);
}

VecLdoub::VecLdoub(const VecLdoub &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecLdoub::operator<<(VecLdoub &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Fcomp *dst, const Fcomp *src, Long_I N);
void veccpy(Fcomp *dst, Fcomp_I src, Long_I N);

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
	using Base::operator[];

    explicit VecFcomp(Long_I N);
    VecFcomp(Long_I N, Fcomp_I s); // initialize to constant value
    VecFcomp(Long_I N, const Fcomp *a); // copy from existing memory
	VecFcomp(const VecFcomp &rhs); // copy constructor
    void operator<<(VecFcomp &rhs); // move data and rhs.resize(0)
};

inline VecFcomp::VecFcomp() {}

inline VecFcomp::VecFcomp(Long_I N) : Base(N) {}

inline VecFcomp::VecFcomp(Long_I N, Fcomp_I s) : VecFcomp(N)
{
    veccpy(m_p, s, N);
}

inline VecFcomp::VecFcomp(Long_I N, const Fcomp * a) : VecFcomp(N)
{
    veccpy(m_p, a, N);
}

VecFcomp::VecFcomp(const VecFcomp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecFcomp::operator<<(VecFcomp &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Comp *dst, const Comp *src, Long_I N);
void veccpy(Comp *dst, Comp_I src, Long_I N);

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
	using Base::operator[];

    explicit VecComp(Long_I N);
    VecComp(Long_I N, Comp_I s); // initialize to constant value
    VecComp(Long_I N, const Comp *a); // copy from existing memory
	VecComp(const VecComp &rhs); // copy constructor
    void operator<<(VecComp &rhs); // move data and rhs.resize(0)
};

inline VecComp::VecComp() {}

inline VecComp::VecComp(Long_I N) : Base(N) {}

inline VecComp::VecComp(Long_I N, Comp_I s) : VecComp(N)
{
    veccpy(m_p, s, N);
}

inline VecComp::VecComp(Long_I N, const Comp * a) : VecComp(N)
{
    veccpy(m_p, a, N);
}

VecComp::VecComp(const VecComp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecComp::operator<<(VecComp &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Lcomp *dst, const Lcomp *src, Long_I N);
void veccpy(Lcomp *dst, Lcomp_I src, Long_I N);

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
	using Base::operator[];

    explicit VecLcomp(Long_I N);
    VecLcomp(Long_I N, Lcomp_I s); // initialize to constant value
    VecLcomp(Long_I N, const Lcomp *a); // copy from existing memory
	VecLcomp(const VecLcomp &rhs); // copy constructor
    void operator<<(VecLcomp &rhs); // move data and rhs.resize(0)
};

inline VecLcomp::VecLcomp() {}

inline VecLcomp::VecLcomp(Long_I N) : Base(N) {}

inline VecLcomp::VecLcomp(Long_I N, Lcomp_I s) : VecLcomp(N)
{
    veccpy(m_p, s, N);
}

inline VecLcomp::VecLcomp(Long_I N, const Lcomp * a) : VecLcomp(N)
{
    veccpy(m_p, a, N);
}

VecLcomp::VecLcomp(const VecLcomp &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecLcomp::operator<<(VecLcomp &rhs)
{
    Base::operator<<(rhs);
}

void veccpy(Imag *dst, const Imag *src, Long_I N);
void veccpy(Imag *dst, Imag_I src, Long_I N);

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
	using Base::operator[];

    explicit VecImag(Long_I N);
    VecImag(Long_I N, Imag_I s); // initialize to constant value
    VecImag(Long_I N, const Imag *a); // copy from existing memory
	VecImag(const VecImag &rhs); // copy constructor
    void operator<<(VecImag &rhs); // move data and rhs.resize(0)
};

inline VecImag::VecImag() {}

inline VecImag::VecImag(Long_I N) : Base(N) {}

inline VecImag::VecImag(Long_I N, Imag_I s) : VecImag(N)
{
    veccpy(m_p, s, N);
}

inline VecImag::VecImag(Long_I N, const Imag * a) : VecImag(N)
{
    veccpy(m_p, a, N);
}

VecImag::VecImag(const VecImag &rhs)
{
	SLS_ERR("copy constructor forbidden!");
}

inline void VecImag::operator<<(VecImag &rhs)
{
    Base::operator<<(rhs);
}

