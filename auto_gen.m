function auto_gen(file)
cd('SLISC');
addpath('../preprocessor');
addpath('../preprocessor/case_conflict');
in_list = ls('*.in');
Ntp = size(in_list, 1);
newline = char(10);
for i = 1:Ntp
    in_file = strtrim(in_list(i,:));
    if nargin > 0 && ~strcmp(in_file, file)
        continue;
    end
    disp(in_file);
    str = fileread(in_file);
    ind = 1;
    code = cell(1, 1); k = 0;
    while true
        ind1 = find_next(str, '//%', ind);
        if (isempty(ind1))
            break;
        end
        k = k + 1;
        code{k} = str(ind:ind1-1);
        ind2 = find_next(str, '//%-----', ind1);
        type_str = str(ind1:ind2-1);
        type_str = strrep(type_str, '//%', '');
        eval(type_str);
        ind2 = next_line(str, ind2);
        ind3 = find_next(str, '//%-----', ind2);
        if (isempty(ind3))
            error('no closing //%-----');
        end
        str1 = str(ind2:ind3-1);
        Ninst = size(types, 1);
        for j = 1:Ninst
            k = k + 1;
            code{k} = [instantiate(str1, types{j,:}), newline];
        end
        clear types;
        ind = next_line(str, ind3);
    end
    k = k + 1;
    code{k} = str(ind:end);
    code_cat = [code{:}];
    filewrite(in_file(1:end-3), code_cat);
end
end
