function ret = is_Jmat(T)
ret = strcmp(T(1:4), 'Jmat') && is_scalar(T(5:end));
end
