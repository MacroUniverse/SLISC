function ret = is_imag(type)
ret = strcmp(type, 'Fimag') || strcmp(type, 'Imag') ||...
    strcmp(type, 'Fimag');
end
