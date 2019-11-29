cd(mfilepath);
file = 'copy_Mcoo_Mcoo.tp';
type = {
    'Doub', 'Doub';
    'Comp', 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/copy_Mcoo_Mcoo.inl', str);
