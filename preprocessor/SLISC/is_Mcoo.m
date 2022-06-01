function ret = is_Mcoo(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Mcoo');
end
end
