function ret = is_Cmat(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Cmat') && is_scalar(T(5:end));
end
end
