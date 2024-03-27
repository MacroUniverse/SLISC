// 用 code gen 吧， 太多重复了
struct AnyRef {
	void *p;
	size_t type; // typeid, possibly from `typeid(...).hash_code()`
	bool operator==(const AnyRef &rhs) {
		if (type != rhs.type) return false;
		if (type == typeid(Str).hash_code())
			return *(Str*)p == *(Str*)rhs.p;
		if (type == typeid(Int).hash_code())
			return *(Int*)p == *(Int*)rhs.p;
	}
}

struct hash_AnyRef {
	size_t operator()(const AnyRef &s) const {
		if (type == typeid(Str).hash_code())
			return std::hash{}(*(Str*)s);
		if (type == typeid(Int).hash_code())
			return std::hash{}(*(Int*)s);
	}
};
