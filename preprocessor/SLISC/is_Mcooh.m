function ret = is_Mcooh(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Mcooh');
end
end
