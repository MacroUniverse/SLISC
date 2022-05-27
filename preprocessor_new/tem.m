function tem(name, param)
global tem_db;
ind = tem_search(name);
if ind > 0
    req(name, param, true);
else
    ind = numel(tem_db)+1;
    tem_db(ind, 1).name = name;
    tem_db(ind, 1).param = param;
end
assignin('caller', 'current_tem', name);
end
