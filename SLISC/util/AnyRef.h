#pragma once
#include "../global.h"

// 用 code gen 吧， 太多重复了

namespace slisc {

struct AnyRef {
	void *p;
	size_t type; // typeid, possibly from `typeid(...).hash_code()`
	AnyRef &operator=(const AnyRef &rhs) {
		if (p == rhs.p)
			SLS_ERR("self assignment!");
		if (type != rhs.type)
			SLS_ERR("assignment of different types!");
		if (type == typeid(Str).hash_code())
			*(Str*)p = *(Str*)rhs.p;
		else if (type == typeid(Int).hash_code())
			*(Int*)p = *(Int*)rhs.p;
		else
			SLS_ERR("unsupported type!");
	}
	bool operator==(const AnyRef &rhs) {
		if (type != rhs.type) return false;
		if (type == typeid(Str).hash_code())
			return *(Str*)p == *(Str*)rhs.p;
		else if (type == typeid(Int).hash_code())
			return *(Int*)p == *(Int*)rhs.p;
		else
			SLS_ERR("unsupported type!");
	}
	void set(Int_I s) { p = (void *)&s; type = typeid(s).hash_code(); }
	void set(Str_I s) {	p = (void *)&s; type = typeid(s).hash_code(); }
	Int &getInt() {
		if (type != typeid(Int).hash_code())
			SLS_ERR("getting wrong type");
		return *(Int*)p;
	}
	Str &getStr() {
		if (type != typeid(Str).hash_code())
			SLS_ERR("getting wrong type");
		return *(Str*)p;
	}
};

// hasher for STL containers like unordered_set<>
struct hash_AnyRef {
	size_t operator()(const AnyRef &s) const {
		if (s.type == typeid(Str).hash_code())
			return std::hash<Str>{}(*(const Str*)s.p);
		else if (s.type == typeid(Int).hash_code())
			return std::hash<Int>{}(*(const Int*)s.p);
		else
			SLS_ERR("unsupported type!");
	}
};

} // namespace
