cd(mfilepath);
file = 'veccpy.tp';
type = {
    'Char', 'Char';
    'Int', 'Char';
    'Int', 'Int';
    'Llong', 'Llong';
    'Float', 'Float';
    'Doub', 'Doub';
    'Ldoub', 'Ldoub';
    'Fcomp', 'Fcomp';
    'Comp', 'Comp';
    'Lcomp', 'Lcomp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/veccpy.inl', str);
