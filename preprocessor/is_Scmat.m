function ret = is_Scmat(T)
ret = strcmp(T(1 : 5), 'Scmat') && is_scalar(T(6:end));
end
