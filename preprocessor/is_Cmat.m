function ret = is_Cmat(T)
ret = strcmp(T(1:4), 'Cmat') && is_scalar(T(5:end));
end
