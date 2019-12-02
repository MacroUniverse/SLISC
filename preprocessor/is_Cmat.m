function ret = is_Cmat(type)
ret = strcmp(type(1:4), 'Cmat') && is_scalar(type(5:end));
end
