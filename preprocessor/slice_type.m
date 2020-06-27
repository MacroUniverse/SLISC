function ret = slice_type(T)
Ts = value_type(T);
if is_Vec(T) || is_Svec(T)
    ret = ['Svec' Ts];
elseif is_Dvec(T)
    ret = ['Dvec' Ts];
elseif is_Cmat(T) || is_Scmat(T) || is_Dcmat(T)
    ret = ['Dcmat' Ts];
elseif is_Cmat3(T)
    ret = ['Jcmat3' Ts];
else
    error('slice_type.m: not implemented!');
end
end
