function ret = is_Cband(T)
ret = numel(T) >= 5 && strcmp(T(1:5), 'Cband') && is_scalar(T(6:end));
end
