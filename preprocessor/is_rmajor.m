function ret = is_rmajor(type)
if (is_Matrix(type) || is_Mat3d(type) ||...
        is_Smat(type) || is_Dmat(type))
    ret = true;
else
    ret = false;
end
end
