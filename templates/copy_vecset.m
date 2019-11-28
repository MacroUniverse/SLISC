cd(mfilepath);
file = 'copy_vecset.tp';
type = {
    'Char'; 'Int'; 'Llong'; 'Float'; 'Doub'; 'Ldoub'; 'Fcomp'; 'Comp'; 'Lcomp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/copy_vecset.inl', str);