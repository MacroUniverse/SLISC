function ret = is_Long(T)
global SLS_USE_INT_AS_LONG;
if strcmp(T, 'Long')
    ret = true;
elseif strcmp(T, 'Llong') && ~SLS_USE_INT_AS_LONG
    ret = true;
elseif strcmp(T, 'Int') && SLS_USE_INT_AS_LONG
    ret = true;
else
    ret = false;
end
end
