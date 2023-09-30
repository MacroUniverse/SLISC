function ret = is_ScmatC(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1 : 6), 'ScmatC') && is_scalar(T(7:end));
end
end
