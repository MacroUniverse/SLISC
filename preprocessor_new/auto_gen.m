% if input filename, only that file is processed
% otherwise, all '.in' files will be processed
function auto_gen(path, file)
global tem_db;
paths = {'../preprocessor', ...
    '../preprocessor_new/SLISC', ...
    '../preprocessor_new/SLISC/case_conflict'};
old_path = pwd;
cd(path);
if exist('tem_db.mat', 'file')
    load('tem_db.mat', 'tem_db');
else
    tem_db = struct('name', '', 'file', '', 'body', '', ...
        'param', {}, 'done', [], 'out', []);
    save('tem_db.mat', 'tem_db');
end
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
    while true
        ind1 = find_next(str, '//% ', ind);
        ind2 = find_next(str, '//%-----', ind);
        if isempty(ind1) && isempty(ind2)
            break;
        elseif isempty(ind2) || ind1 < ind2 % found meta block
            [temp, ind3] = get_meta_block(str, ind1 + 3);
            eval(temp);
            ind = ind3 + 1;
            continue;
        elseif isempty(ind1) || ind2 < ind1 % found template body
            ind3 = find_next(str, '//%-----', ind2+3);
            if (isempty(ind3))
                error('no closing //%-----');
            end
            body = str(next_line(str, ind2):ind3-1);
            ind4 = tem_search(current_tem);
            if ind4 < 0
                error('no tem() before template body!');
            end
            tem_db(ind4).body = body;
            tem_db(ind4).file = [pwd '/' in_file];
            N = size(tem_db(ind4).param, 1);
            tem_db(ind4).done = false(N, 1);
            tem_db(ind4).out = repmat({''}, N, 1);
            ind = ind3 + 3; current_tem = '';
            continue;
        else
            error('something wrong!');
        end
    end        
end
rmpath(paths{:});
cd(old_path);
end
