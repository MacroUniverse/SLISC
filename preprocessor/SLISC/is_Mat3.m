function ret = is_Mat3(T)
if ~ischar(T) || numel(T) < 4
    ret = false;
else
    ret = strcmp(T(1:4), 'Mat3');
end
end
