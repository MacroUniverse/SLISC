cd(mfilepath);
file = 'copy_contain.tp';
type = {
    'VecDoub', 'VecDoub';
    'CmatDoub', 'CmatDoub';
%     'Cmat3Doub', 'Cmat3Doub';
%     'Jcmat3Doub', 'Jcmat3Doub';
%     'MatDoub', 'MatDoub';
%     'Mat3Doub', 'Mat3Doub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/copy_contain.inl', str);
