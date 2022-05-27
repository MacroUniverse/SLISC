function ret = is_Cband(T)
ret = strcmp(T(1:5), 'Cband') && is_scalar(T(6:end));
end
