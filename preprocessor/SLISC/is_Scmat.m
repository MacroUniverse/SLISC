function ret = is_Scmat(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1 : 5), 'Scmat') && is_scalar(T(6:end));
end
end
