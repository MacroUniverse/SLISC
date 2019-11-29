cd(mfilepath);
file = 'contain_eq_ne.tp';
type = {
    'VecDoub', 'VecDoub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/contain_eq_ne.inl', str);
