# EXPLANATION:

# The dataFrame has the following fields:
# Name, Marks, CGPU & Quality of Assignment

# The Name field is of Nominal datatype since each record is a nominee of the field. Mode can be found out.

# The Marks field is of Ordinal datatype since it can be sorted and comparison operations can be performed. Mode, Median and Mean can be found out.

# The CGPA field is of Ratio datatype. Thus, Mode, Median and Mean can be obtained

# Quality of Assignment, as the name of the field suggests, is a field of Qualitative type rather than Quantitative type. Since its a textual field and is dependent on conext rather than numeric value. The mode can be obtained from this field.


# ---------------------------------------------------------------------------------------


# TODO
# [X] - Read excel file as dataframe

# [X] - Figure our what kind of data it is, eg:. Nominal, Ordinal, etc

# [X] - Depending on the type, figure out the mesaure of central tendency that can be found out by ops on the data, eg: if we can find the summation, we cant find the mean, if its not ordinal, we cant sort and we cant find the median, etc.

# [X] - Fill in the missing value in the CGPI field


# ---------------------------------------------------------------------------------------

# =>
# ->
# ==

import pandas as pd

# Read the dataset from excel file by passing raw string as argument to read_excel() fn
dataFrame = pd.read_excel(r'C:\Users\deshi\code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-1\Demo.xlsx')

# Print the pandas dataFrame obtained from the excel file
print('\n-----------ORIGINAL DATA-------------')
print(f'\nPrinting the original dataset:\n\n{dataFrame}')

# Starting with Name field
print('\n-----------NAME-------------')

# Calculating mode
nameMode = dataFrame['Name'].mode()

# Note: Since mode() returns a pandas series, we use indexing to access the name instead of printing the entire record
print(f"\nName field is of Nominal datatype\nMode of this data is = {nameMode[0]}")

# Marks field
print('\n-----------MARKS-------------')
# Sorting the marks column
sortedMarksCol = dataFrame['Marks'].sort_values(ascending=False)

# Printing the marks column
print(f'\nMarks field is of Ordinal datatype\nPrinting the sorted marks column:\n{sortedMarksCol.to_string(index=False)}')

# Calculating mode, median, mean
marksMode = sortedMarksCol.mode() # We use indexing only for mode since the return type is a pandas series
marksMedian = sortedMarksCol.median()
marksMean = sortedMarksCol.mean()

# Printing results
print(f"Results of statistical calculations on Marks:\nMean = {marksMean}\nMedian = {marksMedian}\nMode = {marksMode[0]}")

# CGPA field
print('\n-----------CGPA-------------')
# Sorting the CGPA column
sortedCGPACol = dataFrame['CGPI'].sort_values(ascending=False)

# Print the CGPA column
print(f'\nCGPA field is of Ratio datatype\nPrinting the sorted CGPA column:\n{sortedCGPACol.to_string(index=False)}')

# Calculating mode, median, mean
CGPAMode = sortedCGPACol.mode()
CGPAMedian = sortedCGPACol.median()
CGPAMean = sortedCGPACol.mean()

# Printing results
print("Results of statistical calculations on CGPA:\nMean = {:.2}\nMedian = {}\nMode = {}".format(CGPAMean, CGPAMedian, CGPAMode[0]))

# QoA field
print('\n-----------Quality of Assignment-------------')
QoAMode = dataFrame['Quality of Assignment'].mode()

print(f"\nQuality of Assignment field is of Qualitative datatype\nMode of this data is = {QoAMode[0]}")

# Filling the missing value
print('\n-----------UPDATED DATA-------------')
dataFrame['CGPI'].fillna(value=CGPAMean, inplace=True)

print(f'\nUpdated data frame with filled missing value for CGPA:\n{dataFrame}')