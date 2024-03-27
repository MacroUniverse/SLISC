// delete a table (or sub table satisfying a condition) and insert new records are slow, when there are lots of unchanged records
// this is a optimized version

#include "../str/str.h"
#include "../util/STL_util.h"

namespace slisc {

struct VecRefAny
{
	vector<const void *> data; // a vector of pointer to actual data
	char *types; // type for each column, 'i' is int, 's' is string
	bool operator==(const VecRefAny &rhs) {
		if (data.size() != rhs.data.size())
			return false;
		for (Long i = 0; i < size(data); ++i) {
			if (types[i] == 'i') {
				if (*(* int)data[i] != *(* int)rhs.data[i])
					return false;
			}
			else if (types[i] == 's') {
				if (*(* Str)data[i] != *(* Strs)rhs.data[i])
					return false;
			}
		}
		return true;
	}
}

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

inline void update_table(
	Str_I table_name,
	vecStr_I field_names, // field names of `data`s
	Str_I condition, // the SQL statement after "WHERE"s
	vecLong_I primary_keys, // which columns of `data` are primary keys
	TabRefAny_I data, // new records
	// assuming `data` doesn't have repeated primary keys
	// assuming `data` satisfy `condition`
	SQLite::Database &db_rw
) {
	Str tmp;
	
	// SELECT statement
	tmp = "SELECT ";
	for (Long i : parimary_keys)
		tmp << field_names[i] << ", ";
	tmp.resize(tmp.size()-2);
	tmp << " FROM " << table_name << " WHERE " << condition;
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
	for (Long i : primary_keys)
		tmp << field_names[i] << "=? AND ";
	tmp.resize(tmp.size()-5);
	SQLite::Statement stmt_delete(db_rw, tmp);

	unordered_set<size_t> deleted;
	
	while (stmt_select.executeStep()) {
		for (Long j = 0; j < size(field_names); ++j) {
			 stmt_select.getColumn(j);
		}
		deleted.push_back(make_tuple(, 
			stmt_select.getColumn(primary_key2_ind)))
	}

	for (auto &record : data) {
		Tpk pk = make_tuple(record.key1, record.key2);
		if (!deleted.count(pk)) {
			// insert
		}
		else { // record exist
			deleted.erase(pk);
			// get all columns of record
			for (j in columns) {
				// check change of field j
				if (/*changed*/) {
					// update field j
				}
			}
		}
	}
}

} // namespace
