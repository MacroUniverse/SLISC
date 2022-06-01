function ret = is_Cmat3(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Cmat3');
end
end
