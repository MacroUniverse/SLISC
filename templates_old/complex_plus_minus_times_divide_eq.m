file = 'complex_plus_minus_times_divide_eq.tp';
type = {
    'Comp', 'Float';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/complex_plus_minus_times_divide_eq.inl', str);
