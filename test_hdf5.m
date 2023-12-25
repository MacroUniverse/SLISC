A = [1.1, -2.2]; % Example matrix
filename = 'matlab_data.h5';
dataset = '/A';
h5create(filename, dataset, size(A));
h5write(filename, dataset, A);
