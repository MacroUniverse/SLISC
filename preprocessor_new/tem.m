function tem(name, param)
global tem_db;
ind = tem_search(name);
if ind > 0
    N = size(param, 1);
    for i = 1:N
        
    end
else
    ind = numel(tem_db)+1;
    tem_db(ind).name = name;
    tem_db(ind).param = param;
end
assignin('caller', 'current_tem', name);
end
