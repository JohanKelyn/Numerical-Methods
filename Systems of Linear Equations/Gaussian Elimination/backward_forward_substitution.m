function x = backward_forward_substitution(L,U,b)
% This function implements backward and forward substitution
% Input: Matrix L, Matrix U, and vector b
% Output: solution vector x
    
n = length(b);
    
% Backward Substitution
y = zeros(n,1);
y(1) = b(1)/L(1,1);
for l=2:n
    s = 0;
    for m=1:l-1
        s = s + L(l,m)*y(m);
    end
    y(l) = (b(l) - s)/L(l,l);
end

% Forward Substitution
x = zeros(n,1);
x(n) = y(n)/U(n,n);
for l=n-1:-1:1
    t = 0;
    for m=l+1:n
        t = t + U(l,m)*x(m);
    end
    x(l) = (y(l) - t)/U(l,l);
end
