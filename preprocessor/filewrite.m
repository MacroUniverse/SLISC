% write a string to a file

function filewrite(file_name, str)
fid = fopen(file_name, 'wt');
fprintf(fid, '%s', str);
fclose(fid);
end
