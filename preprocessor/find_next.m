function ind = find_next(str, key, start)
ind = regexp(str(start:end), key, 'once') + start - 1;
end
