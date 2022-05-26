% str is everything under the '//%---------'
% `varargin` is a list of template params
function code = instantiate(str, varargin)
newline = char(10);
ind_meta = strfind(str, '//%');
Nmeta = numel(ind_meta);
Ncell = 2*Nmeta + 1;
cstr = cell(Ncell, 1);
if Nmeta > 0
    k = 1;
    cstr{k} = str(1:ind_meta(1)-1);
    k = k + 1;
    is_meta = false(1, Ncell);
    for i = 1 : Nmeta - 1
        cstr{k} = get_line(str, ind_meta(i));
        is_meta(k) = true;
        ind = next_line(str, ind_meta(i));
        cstr{k+1} = str(ind : ind_meta(i+1)-1);
        k = k + 2;
    end
    cstr{k} = get_line(str, ind_meta(end));
    is_meta(k) = true;
    ind = next_line(str, ind_meta(end));
    cstr{k+1} = str(ind : end);
else
    cstr{1} = str;
    is_meta = false;
end
% disp([cstr{:}]); % debug

% replace @xxx@ in a `code`
repvar = [
    'ind2 = 1;', newline,...
    'while true', newline,...
    '    ind1 = find_next(code, ''@.*@'', ind2) + 1;', newline,...
    '    if (isempty(ind1))', newline...
    '        break;', newline,...
    '    end', newline,...
    '    ind2 = find_next(code, ''@'', ind1) - 1;', newline,...
    '    type = code(ind1:ind2);', newline,...
    '    newstr = eval(type);', newline,...
    '    if isscalar(newstr) && isnumeric(newstr)', newline,...
    '        newstr = num2str(newstr);', newline,...
    '    end', newline,...
    '    code = strrep(code, [''@'' type ''@''], newstr);', newline,...
    '    ind2 = ind2 - numel(type) + numel(newstr);', newline,...
    'end', newline
];
eval_str = ['code = '''';' newline];
for i = 1 : Ncell
    if (is_meta(i))
        eval_str = [eval_str, cstr{i}(5:end)];
    else
        eval_str = [eval_str, 'code = [code, ', 'cstr{', num2str(i), '}];', newline];
        eval_str = [eval_str, repvar, newline];
    end
end
eval_str = [eval_str, newline];
eval(eval_str);
% filewrite('cpp_gen.m', eval_str);
% cpp_gen;
end
