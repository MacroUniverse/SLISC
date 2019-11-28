cd(mfilepath);
file = 'global_contain_typedef.tp';
type = {
    {'Vbase', 'Char', 'Int', 'Llong', 'Long', 'Fdoub', ...
    'Doub', 'Ldoub', 'Fcomp', 'Comp', 'Lcomp';}
    {'Vec', 'Char', 'Int', 'Llong', 'Long', 'Fdoub', ...
    'Doub', 'Ldoub', 'Fcomp', 'Comp', 'Lcomp';}
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i}{:}), newline];
end
str = [code{:}];
filewrite('../SLISC/global_contain_typedef.inl', str);
