function ret = is_rmajor(T)
if (is_Mat(T) || is_Mat3(T) ||...
        is_Smat(T) || is_Dmat(T))
    ret = true;
else
    ret = false;
end
end
