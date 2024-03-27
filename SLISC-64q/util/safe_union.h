#pragma once
#include "../global.h"

namespace slisc {

union SafeUnionVal {
	Int v_Int;
	Llong v_Llong;
	Doub v_Doub;
	Comp v_Comp;
	SafeUnionVal() {}
	~SafeUnionVal() {}
};

struct SafeUnion
{
	char type;
	SafeUnionVal val;
	Str str; // it's too complicated to include Str in SafeUnionVal

	SafeUnion() = default;
	SafeUnion(Int s): type('i') { val.v_Int = s; }
	SafeUnion(Llong s): type('l') { val.v_Llong = s; }
	SafeUnion(Doub s): type('d') { val.v_Doub = s; }
	SafeUnion(Comp s): type('c') { val.v_Comp = s; }
	SafeUnion(const Str &s): type('s') { str = s; }

	SafeUnion &operator=(Int s) { type = 'i'; val.v_Int = s; return *this; }
	SafeUnion &operator=(Llong s) { type = 'l'; val.v_Llong = s; return *this; }
	SafeUnion &operator=(Doub s) { type = 'd'; val.v_Doub = s; return *this; }
	SafeUnion &operator=(Comp s) { type = 'c'; val.v_Comp = s; return *this; }
	SafeUnion &operator=(const Str &s) { type = 's'; str = s; return *this; }

	void clear() { type = 'n'; } // no value

	Int &Int_() {
		if (type != 'i') throw std::runtime_error("SafeUnion i");
		return val.v_Int;
	}
	Llong &Llong_() {
		if (type != 'l') throw std::runtime_error("SafeUnion l");
		return val.v_Llong;
	}
	Doub &Doub_() {
		if (type != 'd') throw std::runtime_error("SafeUnion d");
		return val.v_Doub;
	}
	Comp &Comp_() {
		if (type != 'c') throw std::runtime_error("SafeUnion c");
		return val.v_Comp;
	}
	Str &Str_() {
		if (type != 's') throw std::runtime_error("SafeUnion s");
		return str;
	}
};

} // namespace
