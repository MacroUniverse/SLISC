% convert a mat file to a matt file

function mat2matt(filename)
data = load(filename);
var_names = fieldnames(data);
Nvars = numel(var_names);
name_vars = cell(1, 2*Nvars);
for i = 1 : Nvars
    name_vars{2*i-1} = var_names{i};
    name_vars{2*i} = data.(var_names{i});
end
mattsave([filename 't'], name_vars{:});
end
