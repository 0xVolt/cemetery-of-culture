# Code by Desh Iyer

# Python program to generate a z-Table using numpy and pandas
# This is an easier alternative to scouring the internet to find a csv file of a z-Table imo

# Import libs
from scipy.integrate import quad
import numpy as np
import pandas as pd

# Function to calculate the y value for corresponding x using
# https://www.thoughtco.com/thmb/pYkVzv3wJGeULFip-z1t75557WA=/1500x1124/filters:no_upscale():max_bytes(150000):strip_icc()/bellformula-56b749555f9b5829f8380dc8.jpg
# Where for a standard normal dist, mean = 0, sigma = 1
def normalProbabilityDensity(x):
    constant = 1.0 / np.sqrt(2 * np.pi)
    returnValue = constant * np.exp((-x ** 2) / 2.0)

    return returnValue

# Create a pandas dataframe with rows and cols indexed appropriately
zTable = pd.DataFrame(
    data = [],
    index = np.round(np.arange(8, -8.1, -.1), 2),
    columns = np.round(np.arange(0.00, .1, .01), 2)
)

# Set the cell values for the dataframe using the function to calc PDF of a Standard Normal Distribution
for index in zTable.index:
    for column in zTable.columns:
        z = np.round(index + column, 2)
        # Calculate the definite integral of the PDF using quad() and formula https://miro.medium.com/max/523/1*kIhMH2ny-EwkZJm-jV4BdQ.png
        value, _ = quad(normalProbabilityDensity, np.NINF, z)
        # Assign cell the value
        zTable.loc[index, column] = value

print(f'Z Table\n\n{zTable}')

zTable.to_excel(r'C:\Users\Volt\Code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-5\zTable.xlsx')

zTable.to_csv(r'C:\Users\Volt\Code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-5\zTable.txt')