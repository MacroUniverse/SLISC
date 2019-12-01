inline void linspace(VecInt_O v, Int_I first, Int_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatLlong_O v, Llong_I first, Llong_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

