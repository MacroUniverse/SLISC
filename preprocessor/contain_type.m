function ret = contain_type(T)
if any(strfind(T, 'Char'))
    ret = 'Char';
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
elseif any(strfind(T, 'Fcomp'))
    ret = 'Fcomp';
elseif any(strfind(T, 'Comp'))
    ret = 'Comp';
elseif any(strfind(T, 'Lcomp'))
    ret = 'Lcomp';
elseif any(strfind(T, 'Imag'))
    ret = 'Imag';
elseif strcmp(T, 'Str')
    ret = 'Char';
elseif strcmp(T, 'Str32')
    ret = 'Char32';
else
    error('not implemented');
end
end
