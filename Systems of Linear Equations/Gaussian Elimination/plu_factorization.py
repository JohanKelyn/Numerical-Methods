def plu_factorization(A):
    import numpy as np
    n = A.shape[0]
    U = A.copy()
    L = np.identity(n)
    P = np.identity(n)
    
    for k in range(n-1):
        i = select_max(U[k:,k])
        Utemp = U[k,k:].copy()
        U[k,k:] = U[i+k,k:]
        U[i+k,k:] = Utemp
        Ltemp = L[k,:k].copy()
        L[k,:k] = L[i+k,:k]
        L[i+k,:k] = Ltemp
        Ptemp = P[k,:].copy()
        P[k,:] = P[i+k,:]
        P[i+k,:] = Ptemp
        for j in range(k+1,n): # Loop to iterate every row after row k
            L[j,k] = U[j,k]/U[k,k] # Store the value of the multiplier into L
            U[j,k:] = U[j,k:] - L[j,k]*U[k,k:] # Modify the value of U
        
    
    return [P,L,U]

def select_max(vec):
    i = 0
    max_value = 0
    n = len(vec)
    for k in range(0,n):
        if abs(vec[k]) > max_value:
            max_value = vec[k]
            i = k
    return i
