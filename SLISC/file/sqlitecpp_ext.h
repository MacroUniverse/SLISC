// delete a table (or sub table satisfying a condition) and insert new records are slow, when there are lots of unchanged records
// this is a optimized version

#include "../str/str.h"
#include "../util/STL_util.h"
#include <SQLiteCpp/Statement.h>
#include <SQLiteCpp/Database.h>
#include <SQLiteCpp/Transaction.h>

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
	clear(q_update) << "UPDATE \"" << table_name << "\" SET ";
	for (Long i = Npk; i < size(field_names); ++i)
		q_update << '"' << field_names[i] << "\"=?, ";
	q_update.resize(q_update.size()-2);
	q_update << " WHERE ";
	for (Long i = 0; i < Npk; ++i)
		q_update << '"' << field_names[i] << "\"=? AND ";
	q_update.resize(q_update.size()-5);
	q_update << ';';

	// DELETE statement
	clear(q_delete) << "DELETE FROM \"" << table_name << "\" WHERE ";
	for (Long i = 0; i < Npk; ++i)
		q_delete << '"' << field_names[i] << "\"=? AND ";
	q_delete.resize(q_delete.size()-5);
}

// sync `data` to a db table, perform DELETE and UPDATE as needed, unchanged records won't be touched
// only record in db satisfying `condition` will be checked
// assume `data` satisfy `condition` (no check)
// might violate 'UNIQUE' for non-primary-key fields
inline void update_sqlite_table(
	unordered_map<tuple<Str>, tuple<Int,Str,Str,Str>> &data, // (primary keys) -> (other fields)
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
			stmt_delete.exec(); stmt_delete.reset();
			continue;
		}
		// check for change
		bool changed = false;
		auto &vals = data.at(key);
		if (get<0>(vals) != (Int)stmt_select.getColumn(1))
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
			stmt_update.exec(); stmt_update.reset();
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


} // namespace
