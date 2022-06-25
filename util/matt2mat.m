% convert one .matt files in the current folder to .mat file
function matt2mat(matt_fname)
matt_varnames = mattload(matt_fname);
save(matt_fname(1:end-1), matt_varnames{:});
end
