// delete a table (or sub table satisfying a condition) and insert new records are slow, when there are lots of unchanged records
// this is a optimized version

#include "../str/str.h"
#include "../util/STL_util.h"

#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Transaction.h>

namespace slisc {

// helper for update_sqlite_table()
inline tuple<SQLite::Statement,SQLite::Statement,SQLite::Statement,SQLite::Statement>
	update_sqlite_table_stmt(
		Str_I table_name, Str_I condition, vecStr_I field_names, Long_I Npk,
		SQLite::Database &db_rw
) {
	// SELECT statement
	Str tmp = "SELECT ";
	for (auto &field : field_names)
		tmp << field << ", ";
	tmp.resize(tmp.size()-2);
	tmp << " FROM " << table_name;
	if (!condition.empty())
		tmp << " WHERE " << condition;
	SQLite::Statement stmt_select(db_rw, tmp);

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
	for (Long i = 0; i < Npk; ++i)
		tmp << field_names[i] << "=? AND ";
	tmp.resize(tmp.size()-5);
	SQLite::Statement stmt_delete(db_rw, tmp);

	return make_tuple(stmt_select, stmt_insert, stmt_update, stmt_delete);
}

// sync `data` to a db table, perform DELETE and UPDATE as needed, unchanged records won't be touched
// only record in db satisfying `condition` will be checked
// assume `data` satisfy `condition` (no check)
inline void update_sqlite_table(
	const unordered_map<tuple<Str,Int>, tuple<Str,Int,Str,Str,Int>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"s
	vecStr_I field_names, // field names of `data`, in order
	Long_I Npk, // number of primary keys
	SQLite::Database &db_rw
) {
	auto ret = update_sqlite_table_stmt(table_name, condition, field_names, Npk, db_rw);
	auto &stmt_select = get<0>(ret);
	auto &stmt_insert = get<1>(ret);
	auto &stmt_update = get<2>(ret);
	auto &stmt_delete = get<3>(ret);

	while (stmt_select.executeStep()) {
		auto key = make_tuple(
			(Str)stmt_select.getColumn(0).getString(),
			(Int)stmt_select.getColumn(1)
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<0>(key));
			stmt_delete.bind(2, get<1>(key));
			stmt_delete.exec(); stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data.at(key);
		if (!changed && get<0>(vals) != (Str)stmt_select.getColumn(0).getString())
			changed = true;
		if (!changed && get<1>(vals) != (Int)stmt_select.getColumn(1))
			changed = true;
		if (!changed && get<2>(vals) != (Str)stmt_select.getColumn(2).getString())
			changed = true;
		if (!changed && get<3>(vals) != (Str)stmt_select.getColumn(3).getString())
			changed = true;
		if (!changed && get<4>(vals) != (Int)stmt_select.getColumn(4))
			changed = true;
		if (changed) {
			// update db record
			stmt_update.bind(1, get<0>(vals));
			stmt_update.bind(2, get<1>(vals));
			stmt_update.bind(3, get<2>(vals));
			stmt_update.bind(4, get<3>(vals));
			stmt_update.bind(5, get<4>(vals));
			stmt_update.bind(2, get<0>(key));
			stmt_update.bind(3, get<1>(key));
			stmt_update.exec(); stmt_update.reset();
		}
	}
}

// sync `data` to a db table, perform DELETE and UPDATE as needed, unchanged records won't be touched
// only record in db satisfying `condition` will be checked
// assume `data` satisfy `condition` (no check)
inline void update_sqlite_table(
	const unordered_map<tuple<Str>, tuple<Int,Str,Str,Str>> &data, // (primary keys) -> (other fields)
	Str_I table_name,
	Str_I condition, // the SQL statement after "WHERE"s
	vecStr_I field_names, // field names of `data`, in order
	Long_I Npk, // number of primary keys
	SQLite::Database &db_rw
) {
	auto ret = update_sqlite_table_stmt(table_name, condition, field_names, Npk, db_rw);
	auto &stmt_select = get<0>(ret);
	auto &stmt_insert = get<1>(ret);
	auto &stmt_update = get<2>(ret);
	auto &stmt_delete = get<3>(ret);

	while (stmt_select.executeStep()) {
		auto key = make_tuple(
			(Str)stmt_select.getColumn(0).getString()
		);
		if (!data.count(key)) {
			// key not found, deleted
			stmt_delete.bind(1, get<0>(key));
			stmt_delete.exec(); stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data.at(key);
		if (!changed && get<0>(vals) != (Int)stmt_select.getColumn(0))
			changed = true;
		if (!changed && get<1>(vals) != (Str)stmt_select.getColumn(1).getString())
			changed = true;
		if (!changed && get<2>(vals) != (Str)stmt_select.getColumn(2).getString())
			changed = true;
		if (!changed && get<3>(vals) != (Str)stmt_select.getColumn(3).getString())
			changed = true;
		if (changed) {
			// update db record
			stmt_update.bind(1, get<0>(vals));
			stmt_update.bind(2, get<1>(vals));
			stmt_update.bind(3, get<2>(vals));
			stmt_update.bind(4, get<3>(vals));
			stmt_update.bind(1, get<0>(key));
			stmt_update.exec(); stmt_update.reset();
		}
	}
}


} // namespace
