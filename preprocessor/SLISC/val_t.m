function varargout = val_t(varargin)
varargout = cell(size(varargin));
for i = 1:nargin
    varargout{i} = val_t1(varargin{i});
end
end

function ret = val_t1(T)
if any(strfind(T, 'Bool'))
    ret = 'Bool';
elseif any(strfind(T, 'Char'))
    ret = 'Char';
elseif any(strfind(T, 'Uchar'))
    ret = 'Uchar';
elseif any(strfind(T, 'Int'))
    ret = 'Int';
elseif any(strfind(T, 'Llong'))
    ret = 'Llong';
elseif any(strfind(T, 'Long'))
    ret = 'Long';
elseif any(strfind(T, 'Float'))
    ret = 'Float';
elseif any(strfind(T, 'Doub'))
    ret = 'Doub';
elseif any(strfind(T, 'Ldoub'))
    ret = 'Ldoub';
elseif any(strfind(T, 'Qdoub'))
    ret = 'Qdoub';
elseif any(strfind(T, 'Fcomp'))
    ret = 'Fcomp';
elseif any(strfind(T, 'Comp'))
    ret = 'Comp';
elseif any(strfind(T, 'Lcomp'))
    ret = 'Lcomp';
elseif any(strfind(T, 'Qcomp'))
    ret = 'Qcomp';
elseif any(strfind(T, 'Fimag'))
    ret = 'Fimag';
elseif any(strfind(T, 'Imag'))
    ret = 'Imag';
elseif any(strfind(T, 'Limag'))
    ret = 'Limag';
elseif strcmp(T, 'vecStr')
    ret = 'Str';
elseif strcmp(T, 'vecStr32')
    ret = 'Str32';
elseif strcmp(T, 'Str')
    ret = 'Char';
elseif strcmp(T, 'Str32')
    ret = 'Char32';
else
    error(['val_t.m: not implemented: ' T]);
end
end
