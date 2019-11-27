function ret = is_Jcmat(type)
ret = strcmp(type(1:5), 'Jcmat') && ~strcmp(type(1:6), 'Jcmat3') ;
end
