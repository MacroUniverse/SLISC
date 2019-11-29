cd(mfilepath);
file = 'resize_cpy.tp';
type = {'VecDoub'; 'CmatDoub';};

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/resize_cpy.inl', str);
