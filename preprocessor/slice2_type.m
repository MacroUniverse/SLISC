function ret = slice2_type(T)
Ts = contain_type(T);
if is_Cmat(T) || is_Scmat(T) || is_Dcmat(T) || is_Cmat3(T)
    ret = ['Dvec' Ts];
elseif is_Mat(T)
    ret = ['Svec' Ts];
else
    error('not implemented!');
end
