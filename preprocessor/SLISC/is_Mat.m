function ret = is_Mat(T)
if ~ischar(T) || numel(T) < 3
    ret = false;
else
    ret = strcmp(T(1:3), 'Mat') && is_scalar(T(4:end));
end
end
