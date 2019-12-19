def lu_factorization(A):
    # Goal: Factor the matrix A into a lower-triangular matrix L and an upper-triangular matrix U
    # Input: Matrix A
    # Output: Lower-Triangular Matrix L, and Upper-Triangular Matrix U
    
    n = A.shape[0]
    U = A.copy() 
    L = np.identity(n) 
    
    for k in range(n-1): 
        for j in range(k+1,n): 
            L[j,k] = U[j,k]/U[k,k] 
            U[j,k:] = U[j,k:] - L[j,k]*U[k,k:] 
            
    return [L,U]
