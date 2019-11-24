fname = 'complex_arith_op_plus_minus_times_divide_eq.tp.inl';
type = {
    'Comp', 'Float';
    'Lcomp', 'Float';
    'Lcomp', 'Comp';
    };
N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = preproc(fname, type{i,:});
end
str = [code{:}];
filewrite('complex_arith_op_plus_minus_times_divide_eq.inl', str);
