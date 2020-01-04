function ret = is_Mat(T)
ret = strcmp(T(1:3), 'Mat') && is_scalar(T(4:end));
end
