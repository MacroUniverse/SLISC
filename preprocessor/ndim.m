function ret = ndim(T)
if is_Vbase(T) || is_dense_vec(T) || is_Fvec(T) ||...
    is_Svec(T) || is_Svec_c(T) || is_Dvec(T)
    ret =1;
elseif is_dense_mat(T) || is_sparse_mat(T) ||...
    is_Fcmat(T) || is_Scmat(T) || is_Scmat_c(T) ||....
    is_Scmat3(T) || is_Scmat3_c(T) ||....
    is_Dcmat(T) || is_Jcmat(T) || is_Cmobd(T) ||....
    is_Cband(T)
    ret =2;
elseif is_Mat3(T) || is_Cmat3(T) || is_Jcmat3(T)
    ret =3;
elseif is_Cmat4(T) || is_Jcmat4(T)
    ret =4;
else
    error("unknown!");
    ret = 'e';
end
