# Code by Desh Iyer

# ----------------------------------------------------------------

# PROBLEM STATEMENT

# Import the z table as a data structure in python. Create some 5 demo examples to find the area under the curve and report the answer from the z-table.  

# ----------------------------------------------------------------

# SOLUTION

# Consider the situation:
# The scores - the number of which are determined by user input - on an exam are normally distributed with a mean of 65 and a std of 9
# Find the percentage of scores, 
    # (i). less than 54
    # (ii). less than 20
    # (iii). at least 80
    # (iv). at least 90
    # (v.) between 40 and 50


# Import libs
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


# Function to plot the graphs of both generated lists of data
def pltGraphs(normallyDistributedData, zDistributedData):
    # Plot two graphs
    plt.title("Normal distribution w/ Mean: 65 & Std. Deviation: 9")
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


# Function to generate the lists of normalized and z-converted data
def generateNormalDataAndConvertToStdNormal():
    # Take user input for number of samples
    numberSamples = int(input("Enter number of samples: "))

    # Generate a normal distribution with arbitrary mean 65 and std 9 
    normallyDistributedData = np.random.normal(65, 9, numberSamples)

    # Calculate summary stats
    normalMean = np.mean(normallyDistributedData)
    normalStd = np.std(normallyDistributedData)

    # Convert the above generated normally distributed data to Z-distributed data using list comprehension
    zDistributedData = [calcZScore(i, normalMean, normalStd) for i in normallyDistributedData]
    
    # Print the lists
    print("Normally Distributed Data:")
    print(normallyDistributedData)

    print("\nStandardized Normally Distributed Data (Z):")
    print(zDistributedData)

    # Plot lists using aforementioned function
    pltGraphs(normallyDistributedData, zDistributedData)


# Simple function to return the z-Score of a given value
def calcZScore(x, mean, std):
    return ((x - mean) / std)


# The main meat of the program
# A function to return the value in the z-Table provided the true value as per the question
# This function first converts the value into a z-Score and then finds the cell in the z-Table correspoinding to the z-Score calculated
def returnAreaUnderCurve(x, zTable):
    # Calc z-Score
    zScore = np.round(calcZScore(x, 65, 9), 2)
    displayZScore = np.round(calcZScore(x, 65, 9), 5)
    
    # Calculate z-Table indices
    rowIndex = np.round(zScore, 1)
    strRowIndex = str(rowIndex)

    colIndex = ((zScore * 100) % 10) / 100 if zScore > 0 else ((-zScore * 100) % 10) / 100
    strColIndex = str(colIndex)

    # Attain cell and store its value
    zTableValue = float(zTable.at[strRowIndex, strColIndex])

    # Print data
    print(f"Z-Score = {displayZScore}")
    print(f"Reading at ({rowIndex}, {colIndex}) = {zTableValue}")

    # Return the cell value
    return zTableValue


# Function that processes questions of "Score < " type
def calculateAndPrintLessThan(reqValue, zTable):
    reqArea = returnAreaUnderCurve(reqValue, zTable)

    print(f'The area under the graph = {np.round(reqArea * 100, 10)}%')


# Function that processes questions of "Score at least" type
def calculateAndPrintAtLeast(reqValue, zTable):
    lessThanArea = returnAreaUnderCurve(reqValue, zTable)
    reqArea = 1 - lessThanArea

    print(f'The required area = 1 - {lessThanArea} = {reqArea}\nThe area under the graph = {np.round(reqArea * 100, 10)}%')


# Function that processes questions of "Score in between" type
def calculateAndPrintBetween(firstReqValue, secondReqValue, zTable):
    firstReading = returnAreaUnderCurve(firstReqValue, zTable)
    secondReading = returnAreaUnderCurve(secondReqValue, zTable)
    
    inBetweenReading = abs(firstReading - secondReading)

    print(f'The required area in between {firstReqValue} and {secondReqValue} = {np.round(inBetweenReading * 100, 10)}%')


# Function to display all the sample questions, call the respective function to calculate the cell value and display results
def calculateCases(zTable):
    print("\n\nPROBLEM STATEMENT:\nConsider the situation:\nThe scores - the number of which are determined by user input - on an exam are normally distributed with a mean of 65 and a std of 9 Find the percentage of scores,\n(i). less than 54\n(ii). less than 20 \n(iii). at least 80\n(iv). at least 90\n(v.) between 40 and 50")

    # Case (i). -> % less than 54
    print("\n\nCase (i). -> percentage less than 54")
    calculateAndPrintLessThan(54, zTable)

    # Case (ii). -> % less than 20
    print("\n\nCase (ii). -> percentage less than 20")
    calculateAndPrintLessThan(20, zTable)

    # Case (iii). -> % at least 80 -> 1 - (% less than 80)
    print("\n\nCase (iii). -> % at least 80 -> 1 - (% less than 80)")
    calculateAndPrintAtLeast(80, zTable)
    
    # Case (iv). -> % at least 90 -> 1 - (% less than 90)
    print("\n\nCase (iv). -> % at least 90 -> 1 - (% less than 90)")
    calculateAndPrintAtLeast(90, zTable)

    # # Case (v). -> % between 40 and 50
    print("\n\nCase (v). -> between 40 and 50")
    calculateAndPrintBetween(40, 50, zTable)


# Main driver function
def main():
    # Read the zTable from the csv file containing details of the zTable in comma separated format & set the first column as the index col
    zTable = pd.read_csv(r"/home/volt/code/cemetery-of-culture/year-2/applied-statistics/lab/experiment-5/zTable.xlsx", index_col=0)

    print("The generated z-Table is:\n", zTable)

    zTable = zTable.astype(str)
    zTable.index = zTable.index.map(str)

    generateNormalDataAndConvertToStdNormal()
    calculateCases(zTable)


# Invoke main()
if __name__ == "__main__":
    main()