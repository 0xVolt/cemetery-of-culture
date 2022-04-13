# Experiment 1.d - Regression (Polynomial Features)
# Objective: To perform regression with transformation of x taking y (t) as scalar

# Import libraries
import numpy as np
from sklearn.datasets import make_regression


# Calculating W using the formula - [W = inverse(Ø'Ø) Ø' t]
def calculateWVectorX(X, t):
    XTranspose = np.transpose(X)

    tempTerm1 = np.linalg.inv(np.matmul(XTranspose, X))

    tempTerm2 = np.matmul(tempTerm1, XTranspose)

    W = np.matmul(tempTerm2, t)

    print("Printing the W vector:")
    print(W)

    return W


# Create a dataset where X is a vector of 10 elements
X, t = make_regression(100, 5, shuffle=True, bias=0, noise=0, random_state=5)

# Printing details of X and t for verification
print("Type of X:", type(X), "| Type of array:",
      np.shape(X), "| Count:", np.count_nonzero(X))
print("Type of t:", type(t), "| Type of array:",
      np.shape(t), "| Count:", np.count_nonzero(t))

exponentialList = [np.exp(i) for i in X]

W = calculateWVectorX(exponentialList, t)
