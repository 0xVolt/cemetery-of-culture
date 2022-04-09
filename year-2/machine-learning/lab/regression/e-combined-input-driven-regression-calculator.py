# Import libraries
from sklearn.datasets import make_regression
import numpy as np

# Define main function
def main():    
    numberSamples = int(input("Enter number of samples to generate with sklearn: "))
    xDim = int(input("Enter the number of dimensions of X: "))
    tDim = int(input("Enter the number of dimensions of T: "))
    biasVal = float(input("Enter the bias value: "))
    noiseVal = float(input("Enter the noise value: "))
    
    X, T = make_regression(numberSamples, xDim, n_targets=tDim, shuffle=True, bias=biasVal, noise=noiseVal, random_state=5)
    

# Calculating W using the formula - [W = inverse(X'X) X' T]
def calculateWVectorX(X, T):
    XTranspose = np.transpose(X)

    tempTerm1 = np.linalg.inv(np.matmul(XTranspose, X))

    tempTerm2 = np.matmul(tempTerm1, XTranspose)

    W = np.matmul(tempTerm2, T)

    print("Printing the W vector:")
    print(W)
    
    return W


# Invoke main() function
if __name__ == "__main()__":
    main()