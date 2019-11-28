cd(mfilepath);
file = 'arithmetic_linspace.tp';
type = {'VecInt'; 'VecLlong'; 'VecDoub'; 'SvecDoub';...
    'CmatDoub'; 'Cmat3Doub'; 'Cmat4Int'; 'CmatInt';...
    'MatInt'; 'CmatComp'; 'Cmat3Int'; 'MatComp';...
    'VecComp'; 'VecChar'; 'MatDoub'; 'ScmatInt';...
    'Mat3Comp'; 'MatChar'; 'Mat3Doub';
    };

N = size(type);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/arithmetic_linspace.inl', str);
