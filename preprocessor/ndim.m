function ret = ndim(type)
if (is_dense_vec(type) || is_FixVec(type) ||...
    is_Svector(type) || is_Svector_c(type) || is_Dvector(type))
    ret =1;
elseif (is_dense_mat(type) || is_sparse_mat(type) ||...
    is_FixCmat(type) || is_Scmat(type) || is_Scmat_c(type) ||....
    is_Dcmat(type) || is_Jcmat(type) || is_CmatObd(type))
    ret =2;
elseif (is_Mat3d(type) || is_Cmat3d(type) || is_Jcmat3d(type))
    ret =3;
elseif (is_Cmat4d(type) || is_Jcmat4d(type))
    ret =4;
else
    error("unknown!");
    ret = 'e';
end
