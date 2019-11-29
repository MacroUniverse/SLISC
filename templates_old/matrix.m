cd(mfilepath);
file = 'matrix.tp';
type = {'Bool'; 'Char'; 'Int'; 'Llong'; 'Float'; 'Doub';...
    'Ldoub'; 'Fcomp'; 'Comp'; 'Lcomp'; 'Imag';};

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/matrix.inl', str);
