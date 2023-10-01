function ret = is_Svbase(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Svbase') && T(end) ~= 'C';
end
end
