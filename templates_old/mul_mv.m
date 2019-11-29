cd(mfilepath);
file = 'arithmetic_mul_mv.tp';
type = {'VecDoub', 'CmatDoub', 'VecDoub';
    'VecLcomp', 'MatComp', 'VecInt';
    'VecInt', 'CmatInt', 'VecInt';
    'VecComp', 'CmatComp', 'VecComp';
    'VecComp', 'CmatDoub', 'VecComp';
    'DvecComp', 'DcmatDoub', 'DvecComp';
    'VecComp', 'MatComp', 'VecComp';
    'VecComp', 'CmatImag', 'VecComp';
    'VecComp', 'MatDoub', 'VecComp';
    'SvecComp', 'MatDoub', 'VecComp';
    };

N = size(type);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/arithmetic_mul_mv.inl', str);
