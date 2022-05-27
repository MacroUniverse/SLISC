% if input filename, only that file is processed
% otherwise, all '.in' files will be processed
function auto_gen(path, file)
global tem_db is_batch_mode;
is_batch_mode = false;
if nargin == 1
    is_batch_mode = true;
end
paths = {'../preprocessor', ...
    '../preprocessor/SLISC', ...
    '../preprocessor/SLISC/case_conflict'};
old_path = pwd;
cd(path);
if is_batch_mode && exist('tem_db.mat', 'file')
    delete 'tem_db.mat';
end
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
    in_list = cellstr(ls('*.in', '-1'));
else
    in_list = cellstr(ls('*.in'));
end
Nfile = size(in_list);

%% first scan through all files
% do not deal with template body
% execute all meta outside template body
for i = 1:Nfile
    in_file = in_list{i};
    if nargin > 1 && ~strcmp(in_file, file)
        continue;
    end
    fprintf(['scan: ' in_file '...' newline]);
    str = fileread(in_file);
    str(str == 13) = [];
    ind = 1;
    while true
        ind1 = find_next(str, '//% ', ind);
        ind2 = find_next(str, '//%-----', ind);
        if isempty(ind1) && isempty(ind2)
            break;
        elseif isempty(ind2) || ind1 < ind2 % found meta block
            [temp, ind3] = get_meta_block(str, ind1);
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

%% recursive instantiation
changed_file = {};
quit = false;
while ~quit
    quit = true;
    for i = 1:numel(tem_db)
        Np = size(tem_db(i).param, 1);
        for j = 1:Np
            if ~tem_db(i).done(j)
                disp([tem_db(i).name ': ' cell2str_disp(tem_db(i).param(j,:))]);
                tem_db(i).out{j} = instantiate(tem_db(i).body, tem_db(i).param{j,:});
                tem_db(i).done(j) = true; quit = false;
                if cellstr_search(changed_file, tem_db(i).file) < 1
                    changed_file = [changed_file; {tem_db(i).file}];
                end
            end
        end
    end
end

%% generate output template
% for changed files only
ind = 1;
out_strs = cell(numel(changed_file), 1);
for i = 1:numel(changed_file)
    disp(['output template: ' changed_file{i}]);
    str = fileread(changed_file{i}); ind = 1;
    str(str == 13) = [];
    while true
        ind1 = find_next(str, '//% ', ind);
        ind2 = find_next(str, '//%-----', ind);
        if isempty(ind1) && isempty(ind2)
            break;
        elseif isempty(ind2) || ind1 < ind2 % found meta block
            [temp, ind3] = get_meta_block(str, ind1);
            [~, ind4] = find_next(temp, 'tem\s*(\s*''', 1);
            if ind4 > 0
                ind5 = find_next(temp, '''', ind4+1);
                current_tem = temp(ind4+1:ind5-1);
            end
            str(ind1:ind3) = [];
            ind = ind1;
            continue;
        elseif isempty(ind1) || ind2 < ind1 % found template body
            ind3 = find_next(str, '//%-----', ind2+3);
            if (isempty(ind3))
                error('no closing //%-----');
            end
            str = [str(1:ind2-1) ['tem@' current_tem '@'] str(next_line(str,ind3)-1:end)];
        end
    end
    % str(str == 13)
    out_strs{i} = str;
end

%% write output files
for i = 1:numel(changed_file)
    disp(['writing (' num2str(i) '): ' changed_file{i}]);
    str = out_strs{i};
    ind = 1;
    while true
        [ind1, ind2] = find_next(str, 'tem@.*?@', ind);
        if isempty(ind1)
            break;
        end
        current_tem = str(ind1+4:ind2-1);
        ind3 = tem_search(current_tem);
        if ind3 < 0
            error('something wrong!');
        end
        temp = '';
        for j = 1:numel(tem_db(ind3).out)
            temp = [temp, tem_db(ind3).out{j}, newline];
        end
        str = [str(1:ind1-1), temp(1:end-1), str(ind2+1:end)];
        ind = ind1;
    end
    filewrite(changed_file{i}(1:end-3), str);
end

rmpath(paths{:});
cd(old_path);
end
