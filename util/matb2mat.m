% convert one .matt files in the current folder to .mat file
function matb2mat(fname, delete_matb)
if (nargin == 1)
    delete_matb = false;
end
varnames = matbload(fname);
if ~isempty(varnames)
    save(fname(1:end-1), varnames{:});
    if delete_matb
        delete(fname);
    end
end
end
