cd(mfilepath);
file = 'shape_cmp.tp';
type = {
    'VecDoub', 'VecDoub';
%     'VecComp', 'VecComp';
%     'CmatDoub', 'CmatDoub';
%     'CmatComp', 'CmatComp';
%     'Cmat3Doub', 'Cmat3Doub';
%     'Cmat4Doub', 'Cmat4Doub';
%     'CmatInt', 'MatChar';
%     'MatDoub', 'CmatDoub';
%     'Mat3Doub', 'Mat3Comp';
%     'MatComp', 'VecInt';
%     'CmatInt', 'CmatInt';
%     'Mat3Doub', 'Mat3Doub';
%     'DcmatInt', 'DcmatInt';
%     'MatComp', 'MatComp';
%     'VecComp', 'VecLdoub';
%     'CmatComp', 'MatComp';
%     'DvecDoub', 'DvecDoub';
%     'VecLdoub', 'VecComp';
%     'VecDoub', 'VecComp';
%     'VecInt', 'VecInt';
%     'VecLcomp', 'VecComp';
%     'VecComp', 'VecLcomp';
%     'DvecInt', 'DvecInt';
%     'VecLlong', 'VecLlong';
%     'McooInt', 'McooInt';
%     'VecLcomp', 'VecLcomp';
%     'CmatDoub', 'MatDoub';
%     'MatInt', 'MatInt';
%     'MatDoub', 'MatDoub';
%     'Jcmat3Doub', 'Cmat3Doub';
%     'DcmatDoub', 'CmatDoub';
    };

N = size(type, 1);
code = cell(0);
for i = 1:N
    code{i} = [preproc(file, type{i,:}), newline];
end
str = [code{:}];
filewrite('../SLISC/shape_cmp.inl', str);
