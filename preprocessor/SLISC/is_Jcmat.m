function ret = is_Jcmat(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Jcmat') && is_scalar(T(6:end)) ;
end
end
