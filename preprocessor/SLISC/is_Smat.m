function ret = is_Smat(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Smat');
end
end
