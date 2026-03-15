fun = @(x) sqrt(1/x); %function to be integrated

a= 2; %check the limits
b = 7;

%no of subintervals
n = 5;

%width of each interval
h = (b-a)/n;

integral_approx = (fun(a) + fun(b))/2;
for i = 1: n-1
    integral_approx = integral_approx + fun(a+i*h);
end
integral_approx = integral_approx*(h);
fprintf('Approximation of the integral using the Trapezoidal Rule: %.6f\n', integral_approx);
fprintf("Sittal Basyal");