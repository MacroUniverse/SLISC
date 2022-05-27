function tem(name, param)
global tem_db is_batch_mode;
if isempty(name)
    error('template name empty!');
end
disp(['tem: ' name]);
ind = tem_search(name);
if ind > 0
    if is_batch_mode
        error(['redefinition of template: ' name]);
    end
    req(name, param, true);
else
    ind = numel(tem_db)+1;
    tem_db(ind, 1).name = name;
    tem_db(ind, 1).param = param;
end
assignin('caller', 'current_tem', name);
end
