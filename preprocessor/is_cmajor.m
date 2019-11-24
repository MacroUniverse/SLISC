function ret = is_cmajor(type)
if (is_Cmat(type) || is_FixCmat(type) || is_Cmat3d(type) ||...
        is_Scmat(type) || is_Scmat_c(type) || is_Dcmat(type))
    ret = true;
else
    ret = false;
end
end
