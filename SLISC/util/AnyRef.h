#pragma once
// AnyRef is like std::any, but doesn't own the object
// AnyRefC is the lower const version
#include "../global.h"

namespace slisc {

struct AnyRefC;

struct AnyRef {
	void *p;
	size_t type; // typeid, possibly from `typeid(...).hash_code()`

	// check type
	template <class T>
	bool is() const {
		return type == typeid(T).hash_code();
	}

	// copy values
	AnyRef &operator=(const AnyRefC &rhs) const;

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

inline AnyRef &AnyRef::operator=(AnyRef_I rhs) const {
	if (p == rhs.p)
		SLS_ERR("self assignment!");
	if (type != rhs.type)
		SLS_ERR("assignment of different types!");

	if (is<Int>())
		get<Int>() = rhs.get<Int>();
	else if (is<Llong>())
		get<Llong>() = rhs.get<Llong>();

	else if (is<Float>())
		get<Float>() = rhs.get<Float>();

	else if (is<Doub>())
		get<Doub>() = rhs.get<Doub>();

	else if (is<Comp>())
		get<Comp>() = rhs.get<Comp>();

	else if (is<Str>())
		get<Str>() = rhs.get<Str>();

	else
		SLS_ERR("unsupported type!");
}

// compare
inline bool operator==(AnyRef_I a, AnyRef_I b) {
	if (a.type != b.type) return false;
	if (a.is<Int>())
		return a.get<Int>() == b.get<Int>();
	else if (a.is<Llong>())
		return a.get<Llong>() == b.get<Llong>();

	else if (a.is<Float>())
		return a.get<Float>() == b.get<Float>();

	else if (a.is<Doub>())
		return a.get<Doub>() == b.get<Doub>();

	else if (a.is<Comp>())
		return a.get<Comp>() == b.get<Comp>();

	else if (a.is<Str>())
		return a.get<Str>() == b.get<Str>();

	else
		SLS_ERR("unsupported type!");
}

// hasher for STL containers like unordered_set<>
struct hash_AnyRef {
	size_t operator()(AnyRef_I s) const {
		if (s.is<Int>())
			return std::hash<Int>{}(s.get<Int>());
		else if (s.is<Llong>())
			return std::hash<Llong>{}(s.get<Llong>());

		else if (s.is<Float>())
			return std::hash<Float>{}(s.get<Float>());

		else if (s.is<Doub>())
			return std::hash<Doub>{}(s.get<Doub>());

		else if (s.is<Str>())
			return std::hash<Str>{}(s.get<Str>());

		else
			SLS_ERR("unsupported type!");
	}
};

} // namespace
