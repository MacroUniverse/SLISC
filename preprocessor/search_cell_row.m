function ind = search_cell_row(mat, row)
[Ni, Nj] = size(mat);
for i = 1:Ni
    found = true;
    for j = 1:Nj
        if ischar(row{j}) && ~strcmp(mat{i,j}, row{j}) || ...
            ~ischar(row{j}) && mat{i,j} ~= row{j}
            found = false; break;
        end
    end
    if found
        ind = i; return;
    end
end
ind = -1;
end
