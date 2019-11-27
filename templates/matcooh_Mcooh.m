cd(mfilepath);
file = 'matcooh_Mcooh.tp';
type = {
    'Int'; 'Doub'; 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/matcooh_Mcooh.inl', str);
