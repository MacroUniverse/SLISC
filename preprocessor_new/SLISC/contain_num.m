function ret = contain_num(T)
if (is_Vec(T)), ret = 0;
elseif (is_Mat(T)), ret = 1;
elseif (is_Cmat(T)), ret = 2;
elseif (is_Mat3(T)), ret = 3;
elseif (is_Cmat3(T)), ret = 4;
% elseif (is_Mat4d(T)), ret = 5;
elseif (is_Cmat4(T)), ret = 6;

elseif (is_Fvec(T)), ret = 20;
elseif (is_Fcmat(T)), ret = 22;

elseif (is_Diag(T)), ret = 31;
elseif (is_Mcoo(T)), ret = 32;
elseif (is_Mcooh(T)), ret = 33;
elseif (is_Cmobd(T)), ret = 34;

elseif (is_Svec(T)), ret = 40;
elseif (is_Dvec(T)), ret = 41;
elseif (is_Smat(T)), ret = 42;
elseif (is_Scmat(T)), ret = 43;
elseif (is_Dmat(T)), ret = 44;
elseif (is_Dcmat(T)), ret = 45;
elseif (is_Jcmat(T)), ret = 46;
elseif (is_Jcmat3(T)), ret = 47;
elseif (is_Svec_c(T)), ret = 48;
elseif (is_Scmat_c(T)), ret = 49;
elseif (is_Scmat3(T)), ret = 50;
elseif (is_Scmat3_c(T)), ret = 51;
else, ret = -1;
end
end
