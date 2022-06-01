function ret = is_Dcmat(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Dcmat');
end
end
