import numpy as np

def conjugate_gradient(A,b):
    # This function comtes the approximation vector x_n using conjugate method
    # Input: Matrix A, and vector b
    # Output: Solution Vector x
    
    n = A.shape[0]
    x = np.zeros(n)
    r = b
    p = r
    r_old = r
    for k in range(n):
        v = A.dot(p)
        a = (r.T).dot(r)/((p.T).dot(v))
        x = x + a*p
        r = r - a*(v)
        betta = (r.T).dot(r)/((r_old.T).dot(r_old))
        p = r + betta*p
        r_old = r
    
    return x
