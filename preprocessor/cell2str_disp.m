function str = cell2str_disp(c)
str = '';
for i = 1:numel(c)
    if strcmp(class(c{i}), 'char')
        temp = c{i};
    elseif islogical(c{i})
        if c{i}
            temp = 'true';
        else
            temp = 'false';
        end
    elseif isnumeric(c{i})
        temp = num2str(c{i});
    end
    str = [str ', ' temp];
end
str = str(3:end);
end
