cd(mfilepath);
file = 'matrix_coo2dense.tp';
type = {
    'CmatDoub', 'Doub';
    'CmatComp', 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/matrix_coo2dense.inl', str);
