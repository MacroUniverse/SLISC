cd(mfilepath);
file = 'complex_arith_op_eq_neq.tp.inl';
Tr = {'Float', 'Doub', 'Ldoub'};
Tc = {'Fcomp', 'Comp', 'Lcomp'};
i = 1;
code = cell(0);
for T1 = Tr
    for T2 = Tc
        code{i} = [preproc(file, T1{1}, T2{1}), newline];
        code{i+1} = [preproc(file, T2{1}, T1{1}), newline];
        i = i + 2;
    end
end

str = [code{:}];
filewrite('complex_arith_op_eq_neq.inl', str);
