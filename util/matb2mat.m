% convert one .matt files in the current folder to .mat file
function matb2mat(fname, replace)
if (nargin == 1)
    replace = false;
end
varnames = matbload(fname);
if ~isempty(varnames)
    save(fname(1:end-1), varnames{:});
    if replace
        delete(fname);
    end
end
end
