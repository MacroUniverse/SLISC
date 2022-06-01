function ret = is_Dmat(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Dmat');
end
end
