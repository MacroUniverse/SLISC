cd(mfilepath);
file = 'arithmetic_shape_cmp.tp';
Tc = {'Vec', 'Svec', 'Dvec', 'Cmat', 'Scmat', ...
    'Dcmat', 'Jcmat3', 'Cmat3', 'Cmat4', 'Mat', ...
    'Mat3', 'Mcoo', 'Mcooh'};
Ts = {'Char', 'Int', 'Llong', 'Float', 'Doub',...
    'Ldoub', 'Comp', 'Lcomp'};

type = cell(0);
i = 1;
for tc = Tc
    for ts = Ts
        type{i} = [tc{1}, ts{1}];
        i = i + 1;
    end
end

code = cell(0);
for T1 = type
    for T2 = type
        code{i} = [preproc(file, T1{1}, T2{1}), newline];
        i = i + 1;
    end
end
str = [code{:}];
filewrite('../SLISC/arithmetic_shape_cmp.inl', str);
