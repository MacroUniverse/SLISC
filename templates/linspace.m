cd(mfilepath);
file = 'linspace.tp';
type = {'VecInt'; 'VecLlong'; 'VecDoub'; 'CmatDoub'; ...
%      'Cmat3Doub'; 'Cmat4Int'; 'CmatInt';...
%     'SvecDoub'; 'MatInt'; 'CmatComp'; 'Cmat3Int'; 'MatComp';...
%     'VecComp'; 'VecChar'; 'MatDoub'; 'ScmatInt';...
%     'Mat3Comp'; 'MatChar'; 'Mat3Doub';
    };

N = size(type);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/linspace.inl', str);
