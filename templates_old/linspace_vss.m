cd(mfilepath);
file = 'linspace_vss.tp';
type = {'Int'; 'Llong'; 'Doub'; 'Comp';
    };

N = size(type);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/linspace_vss.inl', str);
