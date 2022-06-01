function ret = is_Fcmat(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Fcmat');
end
end
