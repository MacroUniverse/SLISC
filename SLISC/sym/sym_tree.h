#pragma once
#include "../global.h"
// syntax tree for math expression

namespace slisc {

enum class sym_type {
	sym,   // unparsed
	int,   // integer
	var,   // variable
	// imag,  // imaginary unit
	add, sub, mul, // div, pow // binary ops: +, -, *, /
	// neg, sqrt, abs // unary ops: -, () // TODO: neg
}

// base class for a symbolic expression
struct sym {
	sym_type type; // operator
	sym *arg;  // first argument
	sym *next; // next arg of parent

	bool is_num; // is (an expression of) number
	virtual Str print() {
		return "expr";
	}
};

struct sint : public sym {
	Long val;
	sint() : type(sym_type::int) {}
	Str print() override {
		return to_string val;
	}
};

struct svar : public sym {
	Str name;
	svar(Str_I name) : name(name), type(sym_type::var) {}
	Str print() override {
		return name;
	}
};

struct sadd : public sym {
	static int prece = 50;
	sadd() : type(sym_type::add) {}
	Str print() override {
		Str str = "(";
		str += this->arg.print();
		str += ") + (";
		str += this->arg.next.print();
		str += ")";
		return str;
	}
};

struct smul : public sym {
	static int prece = 55;
	smul() : type(sym_type::mul) {}
	Str print() override {
		Str str = "(";
		str += this->arg.print();
		str += ") * (";
		str += this->arg.next.print();
		str += ")";
		return str;
	}
};

// struct sdiv : public sym {
	
// };

struct sym_pool {
	ObjPool<sint> int;
	ObjPool<svar> var;
	ObjPool<sadd> add;
	ObjPool<smul> mul;
}

struct op_prop {
	int preci; // precedance
	char assoc; // association
}

// operation -> (precedence, association [l|r])
typedef op_props_t unordered_map<sym_type, pair<int, op_prop>>;

op_props_t op_props;

inline void op_prop_init(op_props_t &op_props) {
	op_props[sym_type::add] = {50, 'l'};
	op_props[sym_type::sub] = {50, 'l'};
	op_props[sym_type::mul] = {51, 'l'};
	op_props[sym_type::div] = {51, 'l'};
}

inline Str to_string(const sym &ex)
{
	if (ex.type == sym_type::int)
}

} // namespace slisc
