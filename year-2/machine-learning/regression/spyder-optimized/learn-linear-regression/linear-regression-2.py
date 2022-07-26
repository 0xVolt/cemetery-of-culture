# Code by Desh Iyer

# EXPERIMENT
# To check the correctness of the previous program wherein Linear Regression was implemented from scratch by using in-built functions of sklearn

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

# Plotting scatterplot
plt.scatter(x, t)
plt.show()

# %% New Cell

# Using an alternate method using sklearn sub-modules
from sklearn.linear_model import LinearRegression

reg = LinearRegression().fit(x, t)

print(reg.score(x, t))

#%% New Cell

# Obtain m and c from attributes of variable reg
slope = float(reg.coef_)
bias = reg.intercept_

# Printing details
print("Slope = {}\nBias = {}".format(slope, bias))