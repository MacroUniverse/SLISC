function ret = ndim(T)
if is_scalar(T)
    ret = 0;
elseif is_Vbase(T) || is_dense_vec(T) || is_Fvec(T) ||...
    is_Svec(T) || is_SvecC(T) || is_Dvec(T) || is_vec(T)
    ret =1;
elseif is_dense_mat(T) || is_sparse_mat(T) ||...
    is_Dcmat(T) || is_Jcmat(T) || is_Cmobd(T) ||....
    is_Cband(T) || is_Mcoo(T)
    ret =2;
elseif is_dense_mat3(T) || is_Jcmat3(T)
    ret =3;
elseif is_dense_mat4(T) || is_Jcmat4(T)
    ret =4;
else
    error(["ndim.m: unknown! T = " T]);
end
end
