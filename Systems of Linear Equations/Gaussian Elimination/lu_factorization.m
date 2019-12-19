function [L, U] = lu_factorization(A)
n = length(A); U = A; L = eye(n);
for k=1:n
    for j=k+1:n
        L(j,k) = U(j,k)/U(k,k);
        U(j,k:n) = U(j,k:n) - L(j,k)*U(k,k:n);
    end
end
end