function ind = tem_search(name)
global tem_db;
ind = cellstr_search({tem_db.name}, name);
end
