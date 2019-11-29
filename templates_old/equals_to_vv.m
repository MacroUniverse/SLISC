cd(mfilepath);
file = 'equals_to_vv.tp';
type = {
    'Doub', 'Doub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/equals_to_vv.inl', str);
