#pragma once
#include "arithmetic.h"
#include "unicode.h"

namespace slisc {
const Int def_disp_prec = 8;
inline void disp(vecInt_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(vecLlong_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(vecDoub_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(vecComp_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(VecInt_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(VecLlong_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(VecDoub_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}


inline void disp(VecComp_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}


inline void disp(MatLlong_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(MatDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(MatComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmatInt_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmatLlong_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmatDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmatLdoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}


inline void disp(CmatComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmatLcomp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}


inline void disp(Cmat3Int_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}

inline void disp(Cmat3Llong_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}

inline void disp(Cmat3Doub_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}

inline void disp(Cmat3Ldoub_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}


inline void disp(Cmat3Comp_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}

inline void disp(Cmat3Lcomp_I a, Int_I precision = def_disp_prec) {
	Long i, j, k, m{ a.n0() }, n{ a.n1() }, q{ a.n2() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (k = 0; k < q; ++k) {
	        cout << "(:, :, " << k << ")" << endl;
	        for (i = 0; i < m; ++i) {
	            for (j = 0; j < n; ++j) {
	                cout << to_num(a(i, j, k)) << "   ";
	            }
	            cout << endl;
	        }
	        cout << endl;
	    }
	cout.precision(oldPrecision);
}


inline void disp(SvecLlong_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(SvecDoub_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(SvecComp_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(DvecLlong_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(DvecDoub_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(DvecComp_I v, Int_I precision = def_disp_prec)
{
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	Long N = v.size();
	if (N == 0)
	    cout << "empty";
	else
	    for (Long i = 0; i < N; ++i) {
	        cout << to_num(v[i]) << "   ";
	    }
	cout << endl << endl;
	cout.precision(oldPrecision);
}

inline void disp(DcmatInt_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(DcmatLlong_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(DcmatDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(DcmatLdoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}


inline void disp(DcmatComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(DcmatLcomp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}


inline void disp(CmobdInt_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmobdDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CmobdComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CbandDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(CbandComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(McooInt_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(McooDoub_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}

inline void disp(McooComp_I a, Int_I precision = def_disp_prec)
{
	Long i, j, m{ a.n0() }, n{ a.n1() };
	auto oldPrecision = cout.precision();
	cout.precision(precision);
	if (a.size() == 0) cout << "empty";
	else
	    for (i = 0; i < m; ++i) {
	        for (j = 0; j < n; ++j) {
	            cout << to_num(a(i, j)) << "   ";
	        }
	        cout << endl;
	    }
	cout << endl;
	cout.precision(oldPrecision);
}


// for vector of string
inline void disp(vecStr_I v)
{
	Long N = v.size();
	for (Long i = 0; i < N; ++i)
	    cout << v[i] << endl;
}

inline void disp(vecStr32_I v)
{
	Long N = v.size();
	for (Long i = 0; i < N; ++i)
	    cout << utf32to8(v[i]) << endl;
}

// set stdout text style
// example: cout << text_deco('r', 'b') + "Red bold text" + text_deco() << endl;
// ref: https://www.tutorialspoint.com/how-to-output-colored-text-to-a-linux-terminal
inline string text_style(Char_I color = 'n', Char_I style = 'n')
{
	if (color == 'n' && style == 'n')
	    return "\033[0m";
	string str = "\033[";
	if (style == 'n') ;
	else if (style == 'b') str += '1'; // bold
	else if (style == 'u') str += '4'; // underline
	str += ';';
	if (color == 'r') str += "31";
	else if (color == 'k') str += "30"; // black
	else if (color == 'g') str += "32"; // green
	else if (color == 'y') str += "33"; // yellow
	else if (color == 'b') str += "34"; // blue
	else if (color == 'm') str += "35"; // magenta
	else if (color == 'c') str += "36"; // cyan
	else if (color == 'w') str += "37"; // white
	str += 'm';
	return str;
}

} // namespace slisc
