% Define the data points (x, y) 
x = [0 1 2 3 4]; 
y = [1 2 4 8 16]; 
% Number of data points 
n = length(x); 
% Calculate forward difference coefficients 
forward_diff = zeros(n); 
forward_diff(:,1) = y'; 
for j = 2:n 
forward_diff(1:n-j+1, j) = diff(forward_diff(1:n-j+2, j-1)); 
end 
% Define the value of x for interpolation 
x_interp = 2.5; 
% Initialize interpolated value 
y_interp = forward_diff(1,1); 
% Compute the interpolated value 
for j = 2:n 
term = prod(x_interp - x(1:j-1)); 
y_interp = y_interp + forward_diff(1,j) * term / factorial(j-1); 
end 
% Display the interpolated value 
fprintf('Interpolated value at x = %.1f: %.4f\n', x_interp, y_interp);