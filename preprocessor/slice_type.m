function ret = slice_type(type)
Ts = contain_type(type);
if is_Vec(type) || is_Svec(type)
    ret = ['Svec' Ts];
elseif is_Dvec(type)
    ret = ['Dvec' Ts];
elseif is_Cmat(type) || is_Scmat(type) || is_Dcmat(type)
    ret = ['Dcmat' Ts];
else
    error('not implemented!');
end
end
