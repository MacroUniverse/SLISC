cd(mfilepath);
file = 'copy_matcpy.tp';
type = {
    'Int', 'Int';
    'Doub', 'Doub';
    'Comp', 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/copy_matcpy.inl', str);
