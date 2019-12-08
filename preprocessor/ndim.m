function ret = ndim(type)
if is_Vbase(type) || is_dense_vec(type) || is_Fvec(type) ||...
    is_Svec(type) || is_Svec_c(type) || is_Dvec(type)
    ret =1;
elseif is_dense_mat(type) || is_sparse_mat(type) ||...
    is_Fcmat(type) || is_Scmat(type) || is_Scmat_c(type) ||....
    is_Dcmat(type) || is_Jcmat(type) || is_Cmobd(type) 
    ret =2;
elseif is_Mat3(type) || is_Cmat3(type) || is_Jcmat3(type)
    ret =3;
elseif is_Cmat4(type) || is_Jcmat4(type)
    ret =4;
else
    error("unknown!");
    ret = 'e';
end
