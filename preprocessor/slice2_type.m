function ret = slice2_type(type)
Ts = contain_type(type);
if is_Cmat(type) || is_Scmat(type) || is_Dcmat(type)
    ret = ['Dvec' Ts];
elseif is_Mat(type)
    ret = ['Svec' Ts];
else
    error('not implemented!');
end
