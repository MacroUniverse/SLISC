// delete a table (or sub table satisfying a condition) and insert new records are slow, when there are lots of unchanged records
// this is a optimized version

#include "../str/str.h"
#include "../util/STL_util.h"
#include <forward_list>
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Transaction.h>

namespace slisc  {

// SQL table cell value (unsafe!)
struct SQLval {
	char type; // 's' string; 'i' int64_t; 'n' no value;
	union {
        int64_t i;
        const char *s;
    };
	SQLval() = default;
	explicit SQLval(char type) : type(type) {}
	SQLval &operator=(Str_I val) { type = 's'; s = val.c_str(); return *this; };
	SQLval &operator=(Long_I val) { type = 'i'; i = val; return *this; };
	bool operator==(const SQLval &rhs) const {
		if (type == 's')
			return strcmp(s, rhs.s) == 0;
		else
			return i == rhs.i;
	}
	bool operator!=(const SQLval &rhs) const { return !(operator==(rhs)); }
};

typedef const SQLval &SQLval_I;
typedef vector<SQLval> vecSQLval;

inline void bind(SQLite::Statement &stmt, Int_I i, SQLval_I val)
{
	if (val.type == 's')
		stmt.bind(i, val.s);
	else if (val.type == 'i')
		stmt.bind(i, val.i);
	else
		throw sls_err(SLS_WHERE);
}

inline void getColumn(SQLval &val, SQLite::Statement &stmt, Int_I i, Str &str_cache)
{
	if (val.type == 's') {
		str_cache = stmt.getColumn(i).getString();
		val.s = str_cache.c_str();
	}
	else if (val.type == 'i')
		val.i = stmt.getColumn(i).getInt64();
	else
		throw sls_err(SLS_WHERE);
}

} // namespace slisc

namespace std {

template <>
struct hash<slisc::SQLval> {
	size_t operator()(slisc::SQLval_I val) {
		if (val.type == 's')
			return slisc::hash_cstr(val.s);
		else
			return std::hash<int64_t>{}(val.i);
	}
};

} // namespace std

namespace slisc {

// queries for update_sqlite_table()
inline void update_sqlite_table_query(
		Str_O q_select, Str_O q_insert, Str_O q_update, Str_O q_delete,
		Str_I table_name, Str_I condition, vecStr_I field_names, Long_I Npk
) {
	// SELECT statement
	clear(q_select) << "SELECT ";
	for (auto &field : field_names)
		q_select << '"' << field << "\", ";
	q_select.resize(q_select.size()-2);
	q_select << " FROM \"" << table_name << '"';
	if (!condition.empty())
		q_select << " WHERE " << condition << ';';

	// INSERT statement
	clear(q_insert) << "INSERT INTO \"" << table_name << "\" (";
	for (auto &field : field_names)
		q_insert << '"' << field << "\", ";
	q_insert.resize(q_insert.size()-2);
	q_insert << ") VALUES (";
	for (Long i = 0; i < size(field_names); ++i)
		q_insert << "?, ";
	q_insert.resize(q_insert.size()-2);
	q_insert << ");";

	// UPDATE statement
	if (Npk < size(field_names)) {
		clear(q_update) << "UPDATE \"" << table_name << "\" SET ";
		for (Long i = Npk; i < size(field_names); ++i)
			q_update << '"' << field_names[i] << "\"=?, ";
		q_update.resize(q_update.size()-2);
		q_update << " WHERE ";
		for (Long i = 0; i < Npk; ++i)
			q_update << '"' << field_names[i] << "\"=? AND ";
		q_update.resize(q_update.size()-5);
		q_update << ';';
	}

	// DELETE statement
	clear(q_delete) << "DELETE FROM \"" << table_name << "\" WHERE ";
	for (Long i = 0; i < Npk; ++i)
		q_delete << '"' << field_names[i] << "\"=? AND ";
	q_delete.resize(q_delete.size()-5);
}

// update rows in db table satisfying `condition` to `data`
// equivalent to deleting the rows satisfying `condition` then insert each row in `data`
// rows that's unchanged will not be touched, which is much more efficient
// each inserted/updated/deleted row will call the optional `callback()` function
// `data` will be cleared empty after return
inline void update_sqlite_table(
	unordered_map<vecSQLval, vecSQLval> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"
	vecStr_I field_names, // field names of `data`, in order
	Int_I Npk, // first Npk of field_names are primary keys
	SQLite::Database &db_rw,
	void (*callback) ( // callback for db change
		char act, // [i] insert [u] update [d] delete
		Str_I table, vecStr_I field_names,
		const pair<vecSQLval, vecSQLval> &row, // the inserted/updated/deleted row
		vecLong_I ind_changed, const vecSQLval &old_vals, // row.second(ind_changed[j]) was old_vals[j]
		void *data // user data
	) = nullptr,
	void *callback_data = nullptr // user data for callback()
) {
	vecSQLval old_vals;
	vecLong ind_changed;
	Str stmp; // temporary string
	const pair<vecSQLval,vecSQLval> row_empty;

	Int Nval = (int)size(field_names) - Npk;
	Str q_select, q_insert, q_update, q_delete;
	update_sqlite_table_query(q_select, q_insert, q_update, q_delete,
		table_name, condition, field_names, Npk);
	SQLite::Statement stmt_select(db_rw, q_select); // select db rows with `condition`
	SQLite::Statement stmt_insert(db_rw, q_insert); // insert a row
	SQLite::Statement stmt_update(db_rw, q_update); // update a row
	SQLite::Statement stmt_delete(db_rw, q_delete); // delete a row

	pair<vecSQLval, vecSQLval> db_row{Npk, Nval};
	vecSQLval &db_keys = db_row.first;
	vecSQLval &db_vals = db_row.second;
	vecStr str_cache(Npk+Nval); // temporary strings for SQLval to point to

	// get field types
	if (!data.empty()) {
		auto it_row0 = data.begin();
		for (Long i = 0; i < Npk; ++i)
			db_keys[i].type = it_row0->first[i].type;
		for (Long i = 0; i < Nval; ++i)
			db_vals[i].type = it_row0->second[i].type;
	}
	else {
		// the actual types don't matter
		for (Long i = 0; i < Npk; ++i)
			db_keys[i].type = 's';
		for (Long i = 0; i < Nval; ++i)
			db_vals[i].type = 's';
	}

	// loop through db rows satisfying `condition`
	while (stmt_select.executeStep()) {
		ind_changed.clear(); old_vals.clear();
		for (Int j = 0; j < Npk; ++j)
			getColumn(db_keys[j], stmt_select, j, str_cache[j]);
		for (Int j = 0; j < Nval; ++j)
			getColumn(db_vals[j], stmt_select, Npk+j, str_cache[Npk+j]);

		auto it_data_row = data.find(db_keys);
		if (it_data_row == data.end()) {
			// key not found in `data`, deleted
			for (Int j = 0; j < Npk; ++j)
				bind(stmt_delete, j+1, db_keys[j]);
			if (stmt_delete.exec() != 1)
				SLS_ERR(SLS_WHERE);
			stmt_delete.reset();
			if (callback)
				callback('d', table_name, field_names, db_row, ind_changed, old_vals, callback_data);
			continue;
		}
		// check for value updates
		else if (Nval > 0) {
			auto &data_vals = it_data_row->second;
			for (Int j = 0; j < Nval; ++j) {
				if (data_vals[j] != db_vals[j]) {
					ind_changed.push_back(j);
					old_vals.push_back(db_vals[j]);
				}
			}
			if (!ind_changed.empty()) {
				// update db record
				for (Int j = 0; j < Nval; ++j)
					bind(stmt_update, j+1, data_vals[j]);
				for (Int j = 0; j < Npk; ++j)
					bind(stmt_update, Nval+j+1, db_keys[j]);
				if (stmt_update.exec() != 1)
					SLS_ERR(SLS_WHERE);
				stmt_update.reset();
				if (callback)
					callback('u', table_name, field_names, *it_data_row, ind_changed, old_vals, callback_data);
			}
		}
		data.erase(it_data_row);
	}
	stmt_select.reset();

	// new records
	for (auto &row : data) {
		for (Int j = 0; j < Npk; ++j)
			bind(stmt_insert, j+1, row.first[j]);
		for (Int j = 0; j < Nval; ++j)
			bind(stmt_insert, Npk+j+1, row.second[j]);
		stmt_insert.exec(); stmt_insert.reset();
		if (callback)
			callback('i', table_name, field_names, row, ind_changed, old_vals, callback_data);
	}
	data.clear();
}

// a more static version
// we can compare dynamic static typing of the 2 approches
inline void update_sqlite_table(
	unordered_map<tuple<Str>, tuple<int64_t,Str,Str,Str>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"
	vecStr_I field_names, // field names of `data`, in order
	Long_I Npk, // number of primary keys
	SQLite::Database &db_rw
) {
	Str q_select, q_insert, q_update, q_delete;
	update_sqlite_table_query(q_select, q_insert, q_update, q_delete,
		table_name, condition, field_names, Npk);
	SQLite::Statement stmt_select(db_rw, q_select);
	SQLite::Statement stmt_insert(db_rw, q_insert);
	SQLite::Statement stmt_update(db_rw, q_update);
	SQLite::Statement stmt_delete(db_rw, q_delete);

	while (stmt_select.executeStep()) {
		auto key = make_tuple(
			(Str)stmt_select.getColumn(0).getString()
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<0>(key));
			if (stmt_delete.exec() != 1) SLS_ERR(SLS_WHERE);
			stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data.at(key);
		if (get<0>(vals) != (int64_t)stmt_select.getColumn(1))
			changed = true;
		else if (get<1>(vals) != (Str)stmt_select.getColumn(2).getString())
			changed = true;
		else if (get<2>(vals) != (Str)stmt_select.getColumn(3).getString())
			changed = true;
		else if (get<3>(vals) != (Str)stmt_select.getColumn(4).getString())
			changed = true;
		if (changed) {
			// update db record
			stmt_update.bind(1, get<0>(vals));
			stmt_update.bind(2, get<1>(vals));
			stmt_update.bind(3, get<2>(vals));
			stmt_update.bind(4, get<3>(vals));
			stmt_update.bind(5, get<0>(key));
			if (stmt_update.exec() != 1) SLS_ERR(SLS_WHERE);
			stmt_update.reset();
		}
		data.erase(key);
	}
	stmt_select.reset();

	// new records
	for (auto &pair : data) {
		stmt_insert.bind(1, get<0>(pair.first));
		stmt_insert.bind(2, get<0>(pair.second));
		stmt_insert.bind(3, get<1>(pair.second));
		stmt_insert.bind(4, get<2>(pair.second));
		stmt_insert.bind(5, get<3>(pair.second));
		stmt_insert.exec(); stmt_insert.reset();
	}
}

inline void update_sqlite_table(
	unordered_map<tuple<Str,Str>, tuple<>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"
	vecStr_I field_names, // field names of `data`, in order
	Long_I Npk, // number of primary keys
	SQLite::Database &db_rw
) {
	Str q_select, q_insert, q_update, q_delete;
	update_sqlite_table_query(q_select, q_insert, q_update, q_delete,
		table_name, condition, field_names, Npk);
	SQLite::Statement stmt_select(db_rw, q_select);
	SQLite::Statement stmt_insert(db_rw, q_insert);
	SQLite::Statement stmt_delete(db_rw, q_delete);

	while (stmt_select.executeStep()) {
		auto key = make_tuple(
			(Str)stmt_select.getColumn(0).getString(),
			(Str)stmt_select.getColumn(1).getString()
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<0>(key));
			stmt_delete.bind(2, get<1>(key));
			if (stmt_delete.exec() != 1) SLS_ERR(SLS_WHERE);
			stmt_delete.reset();
			continue;
		}
		data.erase(key);
	}
	stmt_select.reset();

	// new records
	for (auto &pair : data) {
		stmt_insert.bind(1, get<0>(pair.first));
		stmt_insert.bind(2, get<1>(pair.first));
		stmt_insert.exec(); stmt_insert.reset();
	}
}

inline void update_sqlite_table(
	unordered_map<tuple<Str,int64_t>, tuple<int64_t>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"
	vecStr_I field_names, // field names of `data`, in order
	Long_I Npk, // number of primary keys
	SQLite::Database &db_rw
) {
	Str q_select, q_insert, q_update, q_delete;
	update_sqlite_table_query(q_select, q_insert, q_update, q_delete,
		table_name, condition, field_names, Npk);
	SQLite::Statement stmt_select(db_rw, q_select);
	SQLite::Statement stmt_insert(db_rw, q_insert);
	SQLite::Statement stmt_update(db_rw, q_update);
	SQLite::Statement stmt_delete(db_rw, q_delete);

	while (stmt_select.executeStep()) {
		auto key = make_tuple(
			(Str)stmt_select.getColumn(0).getString(),
			(int64_t)stmt_select.getColumn(1)
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<0>(key));
			stmt_delete.bind(2, get<1>(key));
			if (stmt_delete.exec() != 1) SLS_ERR(SLS_WHERE);
			stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data.at(key);
		if (get<0>(vals) != (int64_t)stmt_select.getColumn(2))
			changed = true;
		if (changed) {
			// update db record
			stmt_update.bind(1, get<0>(vals));
			stmt_update.bind(2, get<0>(key));
			stmt_update.bind(3, get<1>(key));
			if (stmt_update.exec() != 1) SLS_ERR(SLS_WHERE);
			stmt_update.reset();
		}
		data.erase(key);
	}
	stmt_select.reset();

	// new records
	for (auto &pair : data) {
		stmt_insert.bind(1, get<0>(pair.first));
		stmt_insert.bind(2, get<1>(pair.first));
		stmt_insert.bind(3, get<0>(pair.second));
		stmt_insert.exec(); stmt_insert.reset();
	}
}


} // namespace
