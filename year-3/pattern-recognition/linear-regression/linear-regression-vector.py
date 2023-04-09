# Experiment 1 - Regression (Vector input)

# Objective: To perform regression with multi-dimensional input and single dimensional output

# Import libraries
from sklearn.datasets import make_regression
import numpy as np

# Verifying the correctness of our approach by creating the same dataset used in the previous program to verify linear regression using this method when X is a vector
# X, t = make_regression(100, 1, shuffle=True, bias=0, noise=25, random_state=5)

# Create a dataset where X is a vector of 10 elements
X, t = make_regression(100, 5, shuffle=True, bias=0, noise=0, random_state=5)

print("Type of X:", type(X), "| Type of array:",
      np.shape(X), "| Count:", np.count_nonzero(X))
print("Type of t:", type(t), "| Type of array:",
      np.shape(t), "| Count:", np.count_nonzero(t))
XTranspose = np.transpose(X)

term1 = np.linalg.inv(np.matmul(XTranspose, X))

term2 = np.matmul(term1, XTranspose)

W = np.matmul(term2, t)

print("Printing the W vector:")
print(W)