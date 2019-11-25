cd(mfilepath);
file = 'complex_arith_op_plus_minus_times_divide.tp';
type = {
    'Float', 'Comp';
    'Comp', 'Int';
    'Int', 'Comp';
    'Llong', 'Comp';
    'Comp', 'Llong';
    'Comp', 'Char';
    'Comp', 'Float';
    'Doub', 'Fcomp';
    'Fcomp', 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/complex_arith_op_plus_minus_times_divide.inl', str);
