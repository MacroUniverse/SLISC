function ret = is_Scmat(type)
ret = strcmp(type(1 : 5), 'Scmat') && is_scalar(type(6:end));
end
