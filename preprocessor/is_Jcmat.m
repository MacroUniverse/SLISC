function ret = is_Jcmat(T)
ret = strcmp(T(1:5), 'Jcmat') && ~strcmp(T(1:6), 'Jcmat3') ;
end
