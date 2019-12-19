def backward_forward_substitution(L,U,b):
    # This function implements backward and forward substitution
    # Input: Matrix L, Matrix U, and vector b
    # Output: solution vector x
    
    n = b.size
    
    # Backward Substitution
    y = np.zeros(n)
    y[0] = b[0]/L[0,0]
    for l in range(1,n):
        s = 0
        for m in range(0,l):
            s = s + L[l,m]*y[m]
        y[l] = (b[l] - s)/L[l,l]

    # Forward Substitution
    x = np.zeros(n)
    for l in range(n-1,-1,-1):
        t = 0
        for m in range(l+1,n):
            t = t + U[l,m]*x[m]
        x[l] = (y[l] - t)/U[l,l]
    return x.T
