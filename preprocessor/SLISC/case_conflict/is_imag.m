function ret = is_imag(T)
ret = strcmp(T, 'Fimag') || strcmp(T, 'Imag') ||...
    strcmp(T, 'Fimag') || strcmp(T, 'Qimag');
end
