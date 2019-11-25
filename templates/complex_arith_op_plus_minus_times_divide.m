cd(mfilepath);
file = 'complex_arith_op_plus_minus_times_divide.tp';

type = {'Char', 'Int', 'Llong', 'Float', 'Doub', ...
    'Ldoub', 'Fcomp', 'Comp', 'Lcomp'};

i = 1;
code = cell(0);
for T1 = type
    for T2 = type
        if is_same(rm_comp(T1{1}), rm_comp(T2{1})) ||...
                is_real(T1{1}) && is_real(T2{1})
            continue;
        end
        code{i} = [preproc(file, T1{1}, T2{1}), newline];
        i = i + 1;
    end
end

str = [code{:}];
filewrite('../SLISC/complex_arith_op_plus_minus_times_divide.inl', str);
