cd(mfilepath);
file = 'arithmetic_reorder.tp';
type = {
    'VecInt', 'VecLlong';
    'VecLlong', 'VecLlong';
    'SvecInt', 'VecLlong';
    'SvecLlong', 'VecLlong';
    'SvecDoub', 'VecLlong';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/arithmetic_reorder.inl', str);
