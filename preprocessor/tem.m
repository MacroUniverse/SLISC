% define template and required params
function tem(name, param)
global tem_db is_batch_mode;
if isempty(name)
    error('template name empty!');
end
disp(['scaning template: ' name]);
ind = tem_search(name);
if ind > 0
    if is_batch_mode && ~isempty(tem_db(ind).body)
        error(['redefinition of template: ' name]);
    end
    req(name, param, true);
else
    ind = numel(tem_db)+1;
    tem_db(ind, 1).name = name;
    for j = 1:size(param, 2)
        if isa(param{1, j}, 'char')
            param{1, j} = convert_Long(param{1, j});
        end
    end
    tem_db(ind, 1).param = param(1,:);
    req(name, param);
end
assignin('caller', 'current_tem', name);
end
