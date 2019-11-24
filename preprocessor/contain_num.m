function ret = contain_num(type)
if (is_Vector(type)), ret = 0;
elseif (is_Matrix(type)), ret = 1;
elseif (is_Cmat(type)), ret = 2;
elseif (is_Mat3d(type)), ret = 3;
elseif (is_Cmat3d(type)), ret = 4;
% elseif (is_Mat4d(type)), ret = 5;
elseif (is_Cmat4d(type)), ret = 6;

elseif (is_FixVec(type)), ret = 20;
elseif (is_FixCmat(type)), ret = 22;

elseif (is_Diag(type)), ret = 31;
elseif (is_MatCoo(type)), ret = 32;
elseif (is_MatCooH(type)), ret = 33;
elseif (is_CmatObd(type)), ret = 34;

elseif (is_Svector(type)), ret = 40;
elseif (is_Dvector(type)), ret = 41;
elseif (is_Smat(type)), ret = 42;
elseif (is_Scmat(type)), ret = 43;
elseif (is_Dmat(type)), ret = 44;
elseif (is_Dcmat(type)), ret = 45;
elseif (is_Jcmat(type)), ret = 46;
elseif (is_Jcmat3d(type)), ret = 47;
elseif (is_Svector_c(type)), ret = 48;
elseif (is_Scmat_c(type)), ret = 49;
else, ret = -1;
end
end
