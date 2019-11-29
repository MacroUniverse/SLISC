VecLlong::VecLlong(Long_I N) : Base(N) {}

VecLlong::VecLlong(const VecLlong &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecLlong::operator<<(VecLlong &rhs)
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

VecComp::VecComp(Long_I N) : Base(N) {}

VecComp::VecComp(const VecComp &rhs) : Base(0)
{
    SLS_ERR("copy constructor forbidden!");
}

void VecComp::operator<<(VecComp &rhs)
{
    Base::operator<<(rhs);
}

