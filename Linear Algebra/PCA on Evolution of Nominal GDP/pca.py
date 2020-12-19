#Principal Component Analysis from scratch
#This is the module that we will be using on the dataset 
#Importing the libraries
import numpy as np
import matplotlib.pyplot as plt 
import pandas as pd
 
#Returns a orthogonal vector
def householder_reflection(a, e):
    
    assert a.ndim == 1
    assert np.allclose(1, np.sum(e**2))
    
    u = a - np.sign(a[0]) * np.linalg.norm(a) * e  
    v = u / np.linalg.norm(u)
    H = np.eye(len(a)) - 2 * np.outer(v, v)
    
    return H

#Function for qr decomposition
def qr_decomposition(A):
    n, m = A.shape
    assert n >= m
    
    Q = np.eye(n)
    R = A.copy()
    
    for i in range(m - int(n==m)):
        r = R[i:, i]
        
        if np.allclose(r[1:], 0):
            continue
            
        # e is the i-th basis vector of the minor matrix.
        e = np.zeros(n-i)
        e[0] = 1  
        
        H = np.eye(n)
        H[i:, i:] = householder_reflection(r, e)

        Q = Q @ H.T
        R = H @ R
    
    return Q, R

#Function to find eigen values and eigen vectors
def eigen_decomposition(A, max_iter=100):
    A_k = A
    Q_k = np.eye( A.shape[1] )
    
    for k in range(max_iter):
        Q, R = qr_decomposition(A_k)
        Q_k = Q_k @ Q
        A_k = R @ Q

    eigenvalues = np.diag(A_k)
    eigenvectors = Q_k
    return eigenvalues, eigenvectors

class PCA:
    def __init__(self, n_components=None):
        self.n_components = n_components
    
    def fit(self, X):
        n, m = X.shape
        
        # subtract off the mean to center the data.
        self.mu = X.mean(axis=0)
        X = X - self.mu
        
        # Eigen Decomposition of the covariance matrix
        C = X.T @ X / (n-1)
        self.eigenvalues, self.eigenvectors = eigen_decomposition(C)
        
        # truncate the number of components if doing dimensionality reduction
        if self.n_components is not None:
            self.eigenvalues = self.eigenvalues[0:self.n_components]
            self.eigenvectors = self.eigenvectors[:, 0:self.n_components]
        
        descending_order = np.flip(np.argsort(self.eigenvalues))
        self.eigenvalues = self.eigenvalues[descending_order]
        self.eigenvectors = self.eigenvectors[:, descending_order]

        return self

    def transform(self, X):
        X = X - self.mu
        return X @ self.eigenvectors
    
    def proportion_variance_explained(self):
        return self.eigenvalues / np.sum(self.eigenvalues)