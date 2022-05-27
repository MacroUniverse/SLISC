% search an element of {'str1', 'str2', ... }
function ind = cellstr_search(cellstr, str)
for ind = 1:numel(cellstr)
    if strcmp(cellstr{ind}, str)
        return;
    end
end
ind = -1;
end
