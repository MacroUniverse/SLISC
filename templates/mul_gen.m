cd(mfilepath);
file = 'arithmetic_mul_gen.tp';
type = {
    'VecDoub', 'CmatDoub', 'VecDoub';
    'VecComp', 'CmatDoub', 'VecComp';
    'DvecComp', 'DcmatDoub', 'DvecComp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/arithmetic_mul_gen.inl', str);
