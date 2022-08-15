% convert 'Long' related types to 'Llong' or 'Int'

function out = convert_Long(type)
global SLS_USE_INT_AS_LONG;
if SLS_USE_INT_AS_LONG
    out = strrep(type, 'Long', 'Int');
else
    out = strrep(type, 'Long', 'Llong');
end
end
