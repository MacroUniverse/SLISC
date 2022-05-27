function ret = is_Jcmat(T)
ret = strcmp(T(1:5), 'Jcmat') && is_scalar(T(6:end)) ;
end
