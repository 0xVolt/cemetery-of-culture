# %% [markdown]
# # Linear Curve Fitting
# Code by Desh Iyer

# %%
# Import libraries
from sklearn.datasets import make_regression
import numpy as np
import matplotlib.pyplot as plt


# %%
# Function to print the summary statistics of a variable
def printSummary(var, x):
    print("\nSummary Statistics for '{}'".format(var))
    print(f"Mean = {np.mean(x)}\nStandard Deviation = {np.std(x)}")


# %%
# Create training dataset to test linear regression
X, t = make_regression(1000, 1, shuffle=True, bias=1, noise=75, random_state=5)


# %%
# Printing the summary statistics
printSummary('X', X)
printSummary('t', t)


# %%
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
slope = sum(productDelta) / sum(deltaXSquare)
yIntercept = tMean - (slope * xMean)

# Print final output
print(f'\n\ny-Intercept = {yIntercept}\nSlope = {slope}')

# %%
# Create a list of values in the best fit line
bestFitLine = [(slope * i + yIntercept) for i in X]

# Plot the best fit line over the actual values
plt.scatter(X, t)
plt.plot(X, bestFitLine, 'r--')

plt.show()

# %%

# Resources
# 1. https://scikit-learn.org/stable/modules/generated/sklearn.datasets.make_regression.html
# 2. https://www.geeksforgeeks.org/random-seed-in-python/