fun = @(x) x.^2; 
a = 0; 
b = 2; 
n = 6;  % must be even
h = (b - a)/n;

% Start with endpoints
integral_approx = fun(a) + fun(b);

% Odd indices: 1,3,5,...
for i = 1:2:n-1
    integral_approx = integral_approx + 4*fun(a + i*h);
end

% Even indices: 2,4,...,n-2
for i = 2:2:n-2
    integral_approx = integral_approx + 2*fun(a + i*h);
end

% Multiply by h/3
integral_approx = integral_approx * h / 3;

fprintf('Approximation of the integral using Simpson''s 1/3 Rule: %.6f\n', integral_approx);