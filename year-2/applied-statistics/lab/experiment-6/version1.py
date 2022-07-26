# Code by Desh Iyer

# ----------------------------------------------------------------

# PROBLEM STATEMENT

# In Lab 1 we discussed a dataset having variables 'Marks' and 'CGPI'. Plot both of them as two different axes. Discuss the covariance and correlation coefficient.

# ----------------------------------------------------------------

# TODO

# [X] - Import excel file as a dataframe using pandas
# [X] - Extract marks and CGPI cols into their own dataframes
# [X] - Calculate covariance and correlation coefficient
# [X] - Create two identical axes only differing in the value plotted
# [X] - Plot both curves

# ----------------------------------------------------------------

# SOLUTION

# Import libs
import pandas as pd
import matplotlib.pyplot as plt

# Extract dataframe from excel file
df = pd.read_excel(r"C:\Users\Volt\Code\B.Tech-CSE-Y2\applied-statistics\lab\experiment-6\Demo.xlsx")

# Store marks and CGPI cols
marksCol = df['Marks']
CGPICol = df['CGPI']

# Calculate values
covariance = marksCol.cov(CGPICol)
correlationCoeff = marksCol.corr(CGPICol, method='pearson')

print(f'Covariance of Marks w.r.t CGPI: {covariance:.3f}\nCorrelation Coefficient of Marks w.r.t CGPI: {correlationCoeff:.3f}')

# Define the x, y for first axis and y for second axis
x = df.index
y1 = marksCol
y2 = CGPICol

# Define the first axis
fig, ax1 = plt.subplots()

# Create the second axis using twinx() function
ax2 = ax1.twinx()

# Plot both curves
curve1 = ax1.plot(x, y1, label="Marks", color='r')
curve2 = ax2.plot(x, y2, label="CGPI", color='b')

# Display both curves
plt.plot()
plt.show()