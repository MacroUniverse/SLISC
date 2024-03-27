#pragma once
#include "../global.h"

// 用 code gen 吧， 太多重复了
// 需要一个 lower level const 的版本

namespace slisc {

struct AnyRef {
	void *p;
	size_t type; // typeid, possibly from `typeid(...).hash_code()`

	// check type
	template <class T>
	bool is() const {
		return type == typeid(T).hash_code();
	}

	// copy assignment
	AnyRef &operator=(const AnyRef &rhs) const {
		if (p == rhs.p)
			SLS_ERR("self assignment!");
		if (type != rhs.type)
			SLS_ERR("assignment of different types!");

		if (is<Str>())
			get<Str>() = rhs.get<Str>();
		else if (is<Int>())
			get<Int>() = rhs.get<Int>();
		else
			SLS_ERR("unsupported type!");
	}
	
	// compare
	bool operator==(const AnyRef &rhs) const {
		if (type != rhs.type) return false;
		if (is<Int>())
			return get<Int>() == rhs.get<Int>();
		else if (is<Str>())
			return get<Str>() == rhs.get<Str>();
		else
			SLS_ERR("unsupported type!");
	}
	
	// bind
	template <class T>
	void bind(T &s) {
		p = (void *)&s;
		type = typeid(s).hash_code();
	}

	// get const reference
	template <class T>
	T &get() const {
		if (!is<T>())
			SLS_ERR("getting wrong type");
		return *(T*)p;
	}
};

// hasher for STL containers like unordered_set<>
struct hash_AnyRef {
	size_t operator()(const AnyRef &s) const {
		if (s.is<Int>())
			return std::hash<Int>{}(s.get<Int>());
		else if (s.is<Str>())
			return std::hash<Str>{}(s.get<Str>());
		else
			SLS_ERR("unsupported type!");
	}
};

} // namespace
