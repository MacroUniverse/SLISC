function ret = is_ScmatC(T)
if ~ischar(T) || numel(T) < 6 || T(end) ~= 'C'
    ret = false;
else
    ret = strcmp(T(1 : 5), 'Scmat') && is_scalar(T(6:end-1));
end
end
