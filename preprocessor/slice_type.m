function ret = slice_type(type)
Ts = contain_type(type);
if is_Vec(type) || is_Svec(type)
    ret = ['Svec' Ts];
elseif is_Dvec(type)
    ret = ['Dvec' Ts];
elseif is_Cmat(type) || is_Scmat(type) || is_Dcmat(type)
    ret = ['Dcmat' Ts];
elseif is_Cmat3(type)
    ret = ['Jcmat3' Ts];
else
    error('not implemented!');
end
end
