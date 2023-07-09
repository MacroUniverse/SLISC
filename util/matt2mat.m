% convert one .matt files in the current folder to .mat file
function matt2mat(matt_fname, replace)
if (nargin == 1)
    replace = false;
end
matt_varnames = mattload(matt_fname);
save(matt_fname(1:end-1), matt_varnames{:});
if replace
    delete(fname);
end
end
