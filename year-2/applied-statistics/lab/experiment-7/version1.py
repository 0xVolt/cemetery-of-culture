# Code by Desh Iyer

# ----------------------------------------------------------------

# PROBLEM STATEMENT

# Observe the dataset: https://www.kaggle.com/subhashinimariappan/numerical-dataset Compute all the statistical measures learnt till the last class: central tendency, dispersion, covariance, correlation, eq of a straight line for all comb. where r>0.6

# ----------------------------------------------------------------

# SOLUTION

# Import libs
import pandas as pd
import numpy as np
from scipy.stats import pearsonr

# Read data from csv file given
df = pd.read_csv(r'C:\Users\Volt\Code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-7\phpB0xrNj.csv')

# Print the dataset
print("\nGiven Data Set")
print(df)

# Give user input
column = input("\nEnter column name to proceed: ")
new_data = df[column]

# Calculating details
Mean = new_data.mean()
Mode = new_data.mode()
Median = new_data.median()
sd = np.std(new_data)
var = np.var(new_data)

# Printing relevant details
print("\nDetails for the column: " + column)

print("\nMeasures of Central Tendency")

print("Calculated Mean of the selected column:", Mean)
print("Calculated Mode of the selected column:", Mode)
print("Calculated Median of the selected column:", Median)

print("\nMeasures of Dispersion")

print("Calculated Standard Deviation of the selected column:", sd)
print("Calculated variance of the selected column: ", var)

# Taking input for second col and printing relevant details
column2 = input("\nEnter the name of another column for finding covariance :")

y = df[column2]

print("\nCovariance matrix for columns: " + column + " and " + column2 + " :")
print(np.cov(new_data,y))

corr, _ = pearsonr(new_data,y)

print("Correlation for columns: " + column + " and " + column2 + " :")
print(corr)