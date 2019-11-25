inline void linspace(VecInt_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecLlong_O v, Llong_I first, Llong_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(SvecDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(Cmat3Doub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(Cmat4Int_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatInt_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(MatInt_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(CmatComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(Cmat3Int_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(MatComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecComp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(VecChar_O v, Char_I first, Char_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(MatDoub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(ScmatInt_O v, Int_I first, Int_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(Mat3Comp_O v, Comp_I first, Comp_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(MatChar_O v, Char_I first, Char_I last)
{
    if (v.size() != abs(last - first) + 1) {
		SLS_ERR("linspace for integral types does not support rounding!");
	}
    linspace_vss(v.ptr(), first, last, v.size());
}

inline void linspace(Mat3Doub_O v, Doub_I first, Doub_I last)
{
    linspace_vss(v.ptr(), first, last, v.size());
}

