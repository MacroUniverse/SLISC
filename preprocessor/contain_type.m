function ret = contain_type(type)
if any(strfind(type, 'Char'))
    ret = 'Char';
elseif any(strfind(type, 'Int'))
    ret = 'Int';
elseif any(strfind(type, 'Llong'))
    ret = 'Llong';
elseif any(strfind(type, 'Float'))
    ret = 'Float';
elseif any(strfind(type, 'Doub'))
    ret = 'Doub';
elseif any(strfind(type, 'Ldoub'))
    ret = 'Ldoub';
elseif any(strfind(type, 'Fcomp'))
    ret = 'Fcomp';
elseif any(strfind(type, 'Comp'))
    ret = 'Comp';
elseif any(strfind(type, 'Lcomp'))
    ret = 'Lcomp';
elseif any(strfind(type, 'Imag'))
    ret = 'Imag';
else
    error('not implemented');
end
end
