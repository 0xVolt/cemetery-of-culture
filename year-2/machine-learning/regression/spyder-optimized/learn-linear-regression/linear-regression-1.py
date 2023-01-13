# Code by Desh Iyer

# EXPERIMENT
# To implement Simple Linear Regression (or) Ordinary Least Square Regression (OLSR) from scratch

# Note: Run in Spyder for optimal results

# Import libraries
from sklearn.datasets import make_regression
import numpy as np
import matplotlib.pyplot as plt

# Function to print the summary statistics of a variable
def printSummary(var, x):
    print("\nSummary Statistics for '{}'".format(var))
    print(f"Mean = {np.mean(x)}\nStandard Deviation = {np.std(x)}")

# Create training dataset to test linear regression
x, t = make_regression(100, 1, shuffle=True, bias=1, noise=0, random_state=5)

# Printing the summary statistics
printSummary('x', x)
printSummary('t', t)

# Plotting scatter plot
plt.scatter(x, t)
plt.show()

#%% New Cell

# Calculate mean of both variables
xMean = np.mean(x)
tMean = np.mean(t)

# Calculate deltaX, deltaT and deltaXSquare
deltaX = [float(i - xMean) for i in x]
deltaXSquare = [float(pow(i, 2)) for i in x]
deltaT = [float(i - tMean) for i in t]

# Calculate the list in the numerator
productDelta = []
for i in range(0, len(deltaT)):
    productDelta.append(deltaX[i] * deltaT[i])

# Calculate slope and y-intercept
m = sum(productDelta) / sum(deltaXSquare)
c = tMean - (m * xMean)

# Print final output
print(f'\n\nc = {c}\nm = {m}')

#%%

# Resources
# 1. https://scikit-learn.org/stable/modules/generated/sklearn.datasets.make_regression.html
# 2. https://www.geeksforgeeks.org/random-seed-in-python/