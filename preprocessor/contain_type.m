function ret = contain_type(type)
if (type(end-3:end) == "Doub")
    ret = "Doub";
elseif (type(end-3:end) == "Comp")
    ret = "Comp";
end
end
