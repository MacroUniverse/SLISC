% if input filename, only that file is processed
% otherwise, all '.in' files will be processed
function auto_gen(path, file)
paths = {'../preprocessor', ...
    '../preprocessor/SLISC', ...
    '../preprocessor/SLISC/case_conflict'};
old_path = pwd;
cd(path);
load('db.mat', 'tem');
% template database
% tem.name: name of the template
% tem.file: path/file of the template
% tem.body: template body code
% tem.param{i,:}: i-th parameter set
% tem.done(i): is the i-th parameter set instanciated?
% tem.out(i): output for i-th param set
addpath(paths{:});
newline = char(10);
if in_octave
    in_list = ls('*.in', '-1');
else
    in_list = ls('*.in');
end
Ntp = size(in_list, 1);

for i = 1:Ntp
    in_file = strtrim(in_list(i,:));
    if nargin > 1 && ~strcmp(in_file, file)
        continue;
    end
    fprintf([in_file '...']);
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
    fprintf('done!\n');
end
rmpath(paths{:});
cd(old_path);
end
