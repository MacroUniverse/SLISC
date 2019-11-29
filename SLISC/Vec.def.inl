VecBool::VecBool(Long_I N) : Base(N) {}

VecBool::VecBool(const VecBool &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecBool::operator<<(VecBool &rhs)
{
    Base::operator<<(rhs);
}

VecChar::VecChar(Long_I N) : Base(N) {}

VecChar::VecChar(const VecChar &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecChar::operator<<(VecChar &rhs)
{
    Base::operator<<(rhs);
}

VecInt::VecInt(Long_I N) : Base(N) {}

VecInt::VecInt(const VecInt &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecInt::operator<<(VecInt &rhs)
{
    Base::operator<<(rhs);
}

VecLlong::VecLlong(Long_I N) : Base(N) {}

VecLlong::VecLlong(const VecLlong &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecLlong::operator<<(VecLlong &rhs)
{
    Base::operator<<(rhs);
}

VecFloat::VecFloat(Long_I N) : Base(N) {}

VecFloat::VecFloat(const VecFloat &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecFloat::operator<<(VecFloat &rhs)
{
    Base::operator<<(rhs);
}

VecDoub::VecDoub(Long_I N) : Base(N) {}

VecDoub::VecDoub(const VecDoub &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecDoub::operator<<(VecDoub &rhs)
{
    Base::operator<<(rhs);
}

VecLdoub::VecLdoub(Long_I N) : Base(N) {}

VecLdoub::VecLdoub(const VecLdoub &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecLdoub::operator<<(VecLdoub &rhs)
{
    Base::operator<<(rhs);
}

VecFcomp::VecFcomp(Long_I N) : Base(N) {}

VecFcomp::VecFcomp(const VecFcomp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecFcomp::operator<<(VecFcomp &rhs)
{
    Base::operator<<(rhs);
}

VecComp::VecComp(Long_I N) : Base(N) {}

VecComp::VecComp(const VecComp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecComp::operator<<(VecComp &rhs)
{
    Base::operator<<(rhs);
}

VecLcomp::VecLcomp(Long_I N) : Base(N) {}

VecLcomp::VecLcomp(const VecLcomp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecLcomp::operator<<(VecLcomp &rhs)
{
    Base::operator<<(rhs);
}

