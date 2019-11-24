cd(mfilepath);
file = 'mul_gen.tp.inl';
Cv = {'Vec', 'Svec', 'Dvec'};
Cm = {'Cmat', 'Scmat', 'Dcmat', 'Mat'};
TS = {
    'Float', 'Float', 'Float';
    'Doub', 'Doub', 'Doub';
    'Comp', 'Comp', 'Comp';
    'Comp', 'Doub', 'Comp';
    };

type = cell(0);
for Ca = Cm
    for Cx = Cv
        for Cy = Cv
            new_type = TS;
            for i = 1:size(TS,1)
                new_type{i,1} = [Cy{1}, new_type{i,1}];
                new_type{i,2} = [Ca{1}, new_type{i,2}];
                new_type{i,3} = [Cx{1}, new_type{i,3}];
            end
            type = [type; new_type];
        end
    end
end
disp(type);

N = size(type, 1);
code = cell(N, 1);
for i = 1:N
    disp(['generating:' type{i,:}]);
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('mul_gen.inl', str);
