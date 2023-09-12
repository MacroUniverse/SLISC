% plot fedvr basis and check ortho

close all;
matbload('./D2_mat_test.matb');
matbload('./fedvr_orthor.matb', 'x_plot6', 'y_plot6', 'x6', 'w6');

figure; plot(x_plot6, y_plot6);

figure; plot(x, y); hold on;
plot(x, d2y);

% Nx = numel(x);
% figure; surfCart(1:Ngs, 1:Ngs, df);
% 
% figure; surfCart(1:Nx, 1:Nx, Ds);
