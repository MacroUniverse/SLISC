function ret = is_Svec(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Svec') && T(end) ~= 'C';
end
end
