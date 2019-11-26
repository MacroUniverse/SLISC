cd(mfilepath);
file = 'diag_Diag.tp';
type = {
    'Int'; 'Doub'; 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/diag_Diag.inl', str);
