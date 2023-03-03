# Experiment 1 - Simple Linear Regression (Scalar)

# Objective: To perform simple linear regression with one-dimensional input and output

# Import libraries
from sklearn.linear_model import LinearRegression
from sklearn.datasets import make_regression
import numpy as np
import matplotlib.pyplot as plt

# Function to print the summary statistics of a variable
def printSummary(var, x):
    print("\nSummary Statistics for '{}'".format(var))
    print(f"Mean = {np.mean(x)}\nStandard Deviation = {np.std(x)}")

# Create training dataset to test linear regression
X, t = make_regression(100, 1, shuffle=True, bias=0, noise=25, random_state=5)

# Printing the summary statistics
printSummary('x', X)
printSummary('t', t)

# Plotting scatter plot
plt.scatter(X, t)
plt.show()

# Calculate mean of both variables
xMean = np.mean(X)
tMean = np.mean(t)

# Calculate deltaX, deltaT and deltaXSquare
deltaX = [float(i - xMean) for i in X]
deltaXSquare = [float(pow(i, 2)) for i in X]
deltaT = [float(i - tMean) for i in t]

# Calculate the list in the numerator
productDelta = []
for i in range(0, len(deltaT)):
    productDelta.append(deltaX[i] * deltaT[i])

# Calculate slope and y-intercept
m = sum(productDelta) / sum(deltaXSquare)
c = tMean - (m * xMean)

# Print final output
print('\n\nSlope = {}\nBias / y-Intercept = {}\n'.format(m, c))

# Note: slope (m) ==> beta_1 || y-intercept (c) ==> beta_0

# Using an alternate method using sklearn sub-modules
reg = LinearRegression().fit(X, t)

print("Regression score:", reg.score(X, t))

# Obtain m and c from attributes of variable reg
slope = float(reg.coef_)
bias = reg.intercept_

# Printing details
print("Slope = {}\nBias / y-Intercept = {}".format(slope, bias))
print(f'Method #1\nm = {m} | c = {c}')
print(f'Method #2\nm = {slope} | c = {bias}')
