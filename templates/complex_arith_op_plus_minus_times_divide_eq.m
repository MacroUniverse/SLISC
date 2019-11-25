fname = 'complex_arith_op_plus_minus_times_divide_eq.tp';
type = {'Char', 'Int', 'Llong', 'Float', 'Doub', 'Ldoub',...
    'Fcomp', 'Comp', 'Lcomp'};

code = cell(0);
i = 1;
for T1 = type
    for T2 = type
        if is_promo(T1{1}, T2{1}) && is_comp(T1{1})
            code{i} = preproc(fname, T1{1}, T2{1});
            i = i + 1;
        end
    end
end
str = [code{:}];
filewrite('complex_arith_op_plus_minus_times_divide_eq.inl', str);
