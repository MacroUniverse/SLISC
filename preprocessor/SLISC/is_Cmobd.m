function ret = is_Cmobd(T)
if ~ischar(T) || numel(T) < 5
    ret = false;
else
    ret = strcmp(T(1:5), 'Cmobd');
end
end
