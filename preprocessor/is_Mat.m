function ret = is_Mat(type)
ret = strcmp(type(1:3), 'Mat') && is_scalar(type(4:end));
end
