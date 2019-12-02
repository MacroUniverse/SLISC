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

T = varargin{:};
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


