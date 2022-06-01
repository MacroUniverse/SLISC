function ret = is_Jcmat3(T)
if ~ischar(T) || numel(T) < 6
    ret = false;
else
    ret = strcmp(T(1:6), 'Jcmat3');
end
end
