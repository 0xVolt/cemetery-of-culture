# Code by Desh Iyer

# Experiment 1.c - Regression (Vector)
# Objective: To perform regression with multi-dimensional output given a multi-dimensional input

# Import libraries
from sklearn.linear_model import LinearRegression
from sklearn.datasets import make_regression
import numpy as np


# Calculating W using the formula - [W = inverse(X'X) X' t]
def calculateWVectorX(X, t):
    XTranspose = np.transpose(X)

    tempTerm1 = np.linalg.inv(np.matmul(XTranspose, X))

    tempTerm2 = np.matmul(tempTerm1, XTranspose)

    W = np.matmul(tempTerm2, t)

    print("\nPrinting the W vector:")
    print(W)

    return W


# Create a dataset where X is a vector of 100 elements and the output is a target of 2
X, T = make_regression(100, 5, n_targets=2, shuffle=True,
                       bias=0, noise=0, random_state=5)

# Printing details of X and t for verification
print("Type of X:", type(X), "| Type of array:",
      np.shape(X), "| Count:", np.count_nonzero(X))
print("Type of T:", type(T), "| Type of array:",
      np.shape(T), "| Count:", np.count_nonzero(T))

# Using a function to calculate W for vector X and t
W = calculateWVectorX(X, T)

# Using sklearn to verify previous solution
reg = LinearRegression().fit(X, T)

print("\nRegression score:", reg.score(X, T))

coeff = reg.coef_
bias = reg.intercept_

print("\nCoefficient:\n{}\n\nBias:\n{}".format(coeff, bias))
