# Code by Desh Iyer

# ----------------------------------------------------------------------------

# PROBLEM STATEMENT
# For the data in Lab 1, find the range, standard deviation and variance for each of the variables. (Discuss measures of dispersion for Nominal and Ordinal Data)

# ----------------------------------------------------------------------------

# TODO
# [X] - Using previously obatined results from the analyis of the data types, find out which Measures of Spread can be applied

# [X] - Calculate the appropriate Measures of Spread for each column

# [X] - Print results

# ----------------------------------------------------------------------------

import pandas as pd

df = pd.read_excel(r'C:\Users\Volt\code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-2\Demo.xlsx')

# Finding range of Marks column
print('----------MARKS-----------\n')

marksCol = df['Marks'].sort_values(ascending=False)

marksRange = marksCol.max() - marksCol.min()
marksStdDeviation = marksCol.std()
marksVariance = marksCol.var()

print(marksCol)

print("The range of the Marks column = {}\nThe standard deviation of the Marks column = {:.2}\nThe variance of the Marks column = {:.2}".format(marksRange, marksStdDeviation, marksVariance))

# Finding range, std deviation and variance from CGPA
print('\n----------CGPA-----------\n')

CGPACol = df['CGPI'].sort_values(ascending=False, ignore_index=True)

CGPARange = CGPACol.max() - CGPACol.min()
CGPAStdDeviation = CGPACol.std()
CGPAVariance = CGPACol.var()

print(CGPACol)
print("The range of the CGPA column = {}\nThe standard deviation of the CGPA column = {:.2}\nThe variance of the CGPA column = {:.2}".format(CGPARange, CGPAStdDeviation, CGPAVariance))
