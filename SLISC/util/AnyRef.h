#pragma once
#include "../global.h"

namespace slisc {

struct AnyRef;
struct AnyRefC;

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

	operator const AnyRefC &() const {
		return reinterpret_cast<const AnyRefC &>(*this);
	}
	operator AnyRefC &() {
		return reinterpret_cast<AnyRefC &>(*this);
	}
};

struct AnyRefC {
	const void *p;
	size_t type; // typeid, possibly from `typeid(...).hash_code()`

	// check type
	template <class T>
	bool is() const {
		return type == typeid(T).hash_code();
	}

	
	// compare
	bool operator==(const AnyRefC &rhs) const {
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
	void bind(const T &s) {
		p = (const void *)&s;
		type = typeid(s).hash_code();
	}

	// get const reference
	template <class T>
	const T &get() const {
		if (!is<T>())
			SLS_ERR("getting wrong type");
		return *(T*)p;
	}

};


typedef const AnyRefC &AnyRef_I;
typedef const AnyRef &AnyRef_O, &AnyRef_IO;

// hasher for STL containers like unordered_set<>
struct hash_AnyRef {
	size_t operator()(AnyRef_I s) const {
		if (s.is<Int>())
			return std::hash<Int>{}(s.get<Int>());
		else if (s.is<Str>())
			return std::hash<Str>{}(s.get<Str>());
		else
			SLS_ERR("unsupported type!");
	}
};

} // namespace
