# Cholesky Factorization

import numpy as np

def cholesky(A):
    # Factorizes the matrix A into a multiplication of two matrices A = R^T R
    # Input: Matrix A
    # Output: Upper-Triangular Matrix R
    R = A.copy()
    n = A.shape[0]
    
    for k in range(0,n):
        for j in range(k+1,n):
            R[j,j:n] = R[j,j:n] - R[k,j:n]*R[k,j]/R[k,k]
        val = np.sqrt(R[k,k])
        R[k,k:n] = R[k,k:n]/val

    R = np.triu(R)
    return R
