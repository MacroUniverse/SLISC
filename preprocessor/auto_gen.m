cd(mfilepath);
cd('../templates');
tp_list = ls('*.tp');
Ntp = size(tp_list, 1);
for i = 1:Ntp
    tp_file = strtrim(tp_list(i,:));
    fileread(tp_file);
end



type = {
    'VecDoub', 'VecDoub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/contain_eq_ne.inl', str);