function str = get_line(str, start)
ind = next_line(str, start);
str = str(start : ind - 1);
end
