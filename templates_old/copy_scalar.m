cd(mfilepath);
file = 'copy_scalar.tp';
type = {
    'VecChar', 'Char';
    'VecInt', 'Int';
    'VecDoub', 'Doub';
%     'SvecDoub', 'Doub';
%     'SvecComp', 'Comp';
%     'DvecDoub', 'Doub';
%     'DvecComp', 'Comp';
%     'CmatDoub', 'Doub';
%     'CmatComp', 'Comp';
%     'ScmatDoub', 'Doub';
%     'ScmatComp', 'Comp';
%     'DcmatDoub', 'Doub';
%     'DcmatComp', 'Comp';
%     'MatDoub', 'Doub';
%     'Mat3Doub', 'Doub';
%     'Cmat3Doub', 'Doub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/copy_scalar.inl', str);
