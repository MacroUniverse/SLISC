% if input filename, only that file is processed
% otherwise, all '.in' files will be processed
% in_paths must end with '/' or '\'
function auto_gen(in_paths, fname, SLS_USE_QUAD_MATH, use_int_as_long, verbose)
global tem_db is_batch_mode SLS_USE_INT_AS_LONG VERBOSE; % is_batch_mode: delete db and process all files
SLS_USE_INT_AS_LONG = use_int_as_long;

is_batch_mode = isempty(fname) || ~exist('../tem_db.mat', 'file');

% split in_paths
inds = [0 strfind(in_paths, ':') numel(in_paths)+1];
in_paths1 = cell(numel(inds)-1, 1);
for i = 1:numel(in_paths1)
    in_paths1{i} = in_paths(inds(i)+1:inds(i+1)-1);
end
in_paths = in_paths1;

if ~exist('verbose', 'var') || ~verbose, VERBOSE = false; else, VERBOSE = true; end
if ~exist('fname', 'var'), fname = []; end
proc_paths = {'../preprocessor/', ...
    '../preprocessor/SLISC/', ...
    '../preprocessor/SLISC/case_conflict/'};
old_path = pwd;
if is_batch_mode && exist('../tem_db.mat', 'file')
    delete '../tem_db.mat';
end
if exist('../tem_db.mat', 'file')
    load('../tem_db.mat', 'tem_db');
else
    tem_db = struct('name', '', 'file', '', 'body', '', ...
        'param', {}, 'done', [], 'out', []);
end
% template database
% tem.name: name of the template
% tem.file: path/file of the template
% tem.body: template body code
% tem.param{i,:}: i-th parameter set
% tem.done(i): is the i-th parameter set instanciated?
% tem.out(i): output for i-th param set
addpath(proc_paths{:});
newline = char(10); Nfile = 0;
in_list = {};
if is_batch_mode
    for i = 1:numel(in_paths)
        in_paths{i} = strrep(in_paths{i}, '\', '/');
        if isempty(dir([in_paths{i} '*.in']))
            continue;
        end
        if in_octave
            tmp = cellstr(ls([in_paths{i} '*.in'], '-1'));
        else % in matlab
            tmp = cellstr(ls([in_paths{i} '*.in']));
        end
        in_list = [in_list; tmp];
    end
    Nfile = numel(in_list);
else
    for i = 1:numel(in_paths)
        in_paths{i} = strrep(in_paths{i}, '\', '/');
        if isempty(dir([in_paths{i} '*.in']))
            continue;
        end
        if in_octave
            tmp = cellstr(ls([in_paths{i} '*.in'], '-1'));
        else % in matlab
            tmp = cellstr(ls([in_paths{i} '*.in']));
        end
        for j = 1:numel(tmp)
            if strcmp(tmp{j}(end-numel(fname)+1:end), fname)
                in_list = tmp(j); break;
            end
        end
        if ~isempty(in_list), break; end
    end
    if isempty(in_list), error('.in file not found!'); end
    Nfile = 1;
end
in_list = sort(in_list);

%% first scan through all files
% do not deal with template body
% execute all meta outside template body
for i = 1:Nfile
    in_file = in_list{i};
    if VERBOSE
        fprintf(['=========== scaning file: ' in_file ' ============' newline]);
    end
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
                error('no `tem()` command before template body!');
            end
            tem_db(ind4).body = body;
            tem_db(ind4).file = in_file;
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
        if isempty(tem_db(i).body)
            error(['template body not found: ' tem_db(i).name]);
        end
        Np = size(tem_db(i).param, 1);
        for j = 1:Np
            if ~tem_db(i).done(j)
                temp = ['instantiating template: ' ...
                    tem_db(i).name ': ' cell2str_disp(tem_db(i).param(j,:))];
                if VERBOSE, disp(temp); end
                if ~SLS_USE_QUAD_MATH && has_quad(tem_db(i).param{j,:})
                    continue;
                end
                tem_db(i).out{j} = instantiate(tem_db(i).body, tem_db(i).param{j,:});
                tem_db(i).done(j) = true; quit = false;
                if ~is_batch_mode
                    if cellstr_search(changed_file, tem_db(i).file) < 1
                        changed_file = [changed_file; {tem_db(i).file}];
                    end
                end
            end
        end
    end
end

if is_batch_mode
    changed_file = in_list;
end

%% generate output file template
% for changed files only
ind = 1;
out_strs = cell(numel(changed_file), 1);
for i = 1:numel(changed_file)
    if VERBOSE, disp(['output text: ' changed_file{i}]); end
    str = fileread(changed_file{i}); ind = 1;
    str(str == 13) = [];
    while true
        ind1 = find_next(str, '//% ', ind);
        ind2 = find_next(str, '//%-----', ind);
        if isempty(ind1) && isempty(ind2)
            break;
        elseif isempty(ind2) || ind1 < ind2 % found meta block
            [temp, ind3] = get_meta_block(str, ind1);
            [~, ind4] = find_next(temp, 'tem\s*\(\s*''', 1);
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
    if VERBOSE, disp(['writing (' num2str(i) '): ' changed_file{i}(1:end-3)]); end
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

% rmpath(paths{:});
save('../tem_db.mat', 'tem_db');
cd(old_path);
end
