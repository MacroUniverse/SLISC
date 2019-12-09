code = '';
code = [code, cstr{1}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

Tv = varargin{:};
code = [code, cstr{3}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

Tsli = slice1_type(Tv);
code = [code, cstr{5}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

if is_Cmat(Tv) || is_Scmat(Tv)
code = [code, cstr{7}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

elseif is_Dcmat(Tv)
code = [code, cstr{9}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

elseif is_Mat(Tv)
code = [code, cstr{11}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

elseif is_Cmat3(Tv)
code = [code, cstr{13}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

else
code = [code, cstr{15}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

    error('not implemented!');
code = [code, cstr{17}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end

end
code = [code, cstr{19}];
ind2 = 0;
while true
    ind1 = find_next(code, '@.*?@', ind2+1) + 1;
    if (isempty(ind1))
        break;
    end
    ind2 = find_next(code, '@', ind1) - 1;
    type = code(ind1:ind2);
    code = strrep(code, ['@' type '@'], eval(type));
end


