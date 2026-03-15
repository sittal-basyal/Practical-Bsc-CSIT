f = @(x) x^3 - 2*x - 5; 
df = @(x) 3*x^2 - 2; 
x0 = 02; 
tol = 1e-6; 
maxIter = 100; 
x = x0; 
for iter = 1:maxIter 
    x_next = x - f(x)/df(x); 
    % Check for convergence 
    if abs(x_next - x) < tol 
        fprintf('Root found at x = %.8f\n', x_next); 
        break; 
    end 
% Update x for next iteration 
    x = x_next; 
end 
if iter == maxIter 
fprintf('Maximum iterations reached without convergence\n'); 
end 