// delete a table (or sub table satisfying a condition) and insert new records are slow, when there are lots of unchanged records
// this is a optimized version

#include "../str/str.h"
#include "../util/STL_util.h"

namespace slisc {

// similar to std::hash, for pair<T,T1> as key

inline size_t operator()(const vector<const void *> &v,
		const vector<char> &types // type for each column, 'i' is int, 's' is string
	) const {
		size_t h = 0;
		for (Long i = 0; i < size(data); ++i) {
			if (types[i] == 'i')
				hash_combine(h, *(*int)v[i]);
			else if (types[i] == 's')
				hash_combine(h, *(*Str)v[i]);
		}
		return h;
	}
};

// sync `data` to a db table, perform DELETE and UPDATE as needed, unchanged records won't be touched
// only record in db satisfying `condition` will be checked
// assume `data` satisfy `condition` (no check)
inline void update_sqlite_table(
	const unordered_map<tuple<Str,Int>, tuple<Str,Int,Str,Str,Int>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"s
	vecStr_I field_names, // field names of `data`s
	vecLong_I primary_keys, // which columns of `data` are primary keys
	SQLite::Database &db_rw
) {
	Str tmp;
	
	// SELECT statement
	tmp = "SELECT ";
	for (auto &field : field_names)
		tmp << field << ", ";
	tmp.resize(tmp.size()-2);
	tmp << " FROM " << table_name << " WHERE " << condition;
	SQLite::Statement stmt_select0(db_rw, tmp);

	// INSERT statement
	clear(tmp) << "INSERT INTO " << table_name << '(';
	for (auto &field : field_names)
		tmp << field << ", ";
	tmp.resize(tmp.size()-2);
	tmp << ") VALUES (";
	for (Long i = 0; i < size(field_names); ++i)
		tmp << "?, ";
	tmp.resize(tmp.size()-3);
	tmp << ");";
	SQLite::Statement stmt_insert(db_rw, tmp);

	// UPDATE statement
	clear(tmp) << "UPDATE " << table_name << " SET ";
	for (auto &field : field_names)
		tmp << field << "=?, ";
	tmp.resize(tmp.size()-2);
	tmp << ';';
	SQLite::Statement stmt_update(db_rw, tmp);

	// DELETE statement
	clear(tmp) << "DELETE FROM " << table << " WHERE ";
	for (Long i : primary_keys)
		tmp << field_names[i] << "=? AND ";
	tmp.resize(tmp.size()-5);
	SQLite::Statement stmt_delete(db_rw, tmp);

	while (stmt_select0.execStep()) {
		auto key = make_tuple(
			(Str)stmt_select0.getColumn(1),
			(Int)stmt_select0.getColumn(2)
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<1>(key));
			stmt_delete.bind(2, get<2>(key));
			stmt_delete.exec(); stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data[key];
		if (!changed && get<1>(vals) != (Str)stmt_select0.getColumn(1))
			changed = true;
		if (!changed && get<2>(vals) != (Int)stmt_select0.getColumn(2))
			changed = true;
		if (!changed && get<3>(vals) != (Str)stmt_select0.getColumn(3))
			changed = true;
		if (!changed && get<4>(vals) != (Str)stmt_select0.getColumn(4))
			changed = true;
		if (!changed && get<5>(vals) != (Int)stmt_select0.getColumn(5))
			changed = true;
		if (changed) {
			// update db record
			stmt_update.bind(j, get<1>(vals));
			stmt_update.bind(j, get<2>(vals));
			stmt_update.bind(j, get<3>(vals));
			stmt_update.bind(j, get<4>(vals));
			stmt_update.bind(j, get<5>(vals));
			stmt_update.bind(2+j, get<1>(key));
			stmt_update.bind(2+j, get<2>(key));
			stmt_update.exec(); stmt_update.reset();
		}
	}
}


} // namespace
