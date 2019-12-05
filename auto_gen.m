function auto_gen(file)
cd('templates');
addpath('../preprocessor');
addpath('../preprocessor/case_conflict');
delete('../SLISC/*.inl');
tp_list = ls('*.tp');
Ntp = size(tp_list, 1);
for i = 1:Ntp
    tp_file = strtrim(tp_list(i,:));
    if nargin > 0 && ~strcmp(tp_file, file)
        continue;
    end
    disp(tp_file);
    str = fileread(tp_file);
    ind = strfind(str, '//%-----');
    if (numel(ind) ~= 1)
        error('there must be exactly one divider!');
    end
    type_str = strrep(str(1:ind-1), '//%', '');
    eval(type_str);
    ind = next_line(str, ind);
    str = str(ind:end);
    Ninst = size(types, 1);
    code = cell(Ninst, 1);
    for j = 1:Ninst
        code{j} = [instantiate(str, types{j,:}), char(10)];
    end
    code_cat = [code{:}];
    filewrite(['../SLISC/' tp_file(1:end-3) '.inl'], code_cat);
    clear types;
end
end
