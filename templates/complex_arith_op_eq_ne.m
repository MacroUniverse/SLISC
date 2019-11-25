cd(mfilepath);
file = 'complex_arith_op_eq_ne.tp';
type = {
    'Float', 'Comp';
    'Fcomp', 'Comp';
    'Comp', 'Int';
    'Int', 'Comp';
    'Lcomp', 'Comp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/complex_arith_op_eq_ne.inl', str);
