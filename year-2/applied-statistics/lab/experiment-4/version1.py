# Code by Desh Iyer

# ----------------------------------------------------------------

# PROBLEM STATEMENT

# Create a dataset of a single variable comprising of only numerical values. Create a Normal distribution for it. Convert it to Z distribution and plot both of the distribution. 

# ----------------------------------------------------------------

# TODO

# [X] - Create a dataset of a single variable comprising of only numerical values. 
# [X] - Create a Normal distribution for it. 
# [X] - Convert it to Z distribution  
# [X] - Plot both of the distribution. 

# ----------------------------------------------------------------

# SOLUTION

# Import libs
import matplotlib.pyplot as plt
import numpy as np

# Define a function to calculate the respective Z-Score for every data point
def calcZScore(x, mean, std):
    return ((x - mean) / std)

# Take user input for number of samples
numberSamples = int(input("Enter number of samples: "))

# Generate a normal distribution with arbitrary mean 5 and std 2 
normallyDistributedData = np.random.normal(5, 2, numberSamples)

# Calculate summary stats
normalMean = np.mean(normallyDistributedData)
normalStd = np.std(normallyDistributedData)

# Convert the above generated normally distributed data to Z-distributed data using list comprehension
zDistributedData = [calcZScore(i, normalMean, normalStd) for i in normallyDistributedData]

# Plot two graphs

plt.title("Normal distribution w/ Mean: 5 & Std. Deviation: 2")
plt.xlabel('x')
plt.ylabel('Normal Distribution')
plt.grid()
plt.hist(normallyDistributedData)
plt.show()

plt.title("Z - Distribution for above graph")
plt.xlabel('x')
plt.ylabel('Standard Normal / Z - Distribution')
plt.grid()
plt.hist(zDistributedData)
plt.show()