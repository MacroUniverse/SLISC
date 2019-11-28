cd(mfilepath);
file = 'arithmetic_mul_sym.tp';
type = {
    'VecDoub', 'CmatDoub', 'VecDoub';
    'VecComp', 'CmatDoub', 'VecComp';
    'SvecComp', 'DcmatDoub', 'SvecComp';
    'DvecComp', 'DcmatDoub', 'DvecComp';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/arithmetic_mul_sym.inl', str);
