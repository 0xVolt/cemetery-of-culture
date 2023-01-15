# Experiment 1 - Pandas Review
# Code by Desh Iyer

# Problem Statement
# Create a pandas dataframe with student data, impute values and calculate the average of a feature.

# Import necessary libraries.

# %%
import pandas as pd
import numpy as np
import random

# Define the number of students (i.e., records) to generate data for. Then, generate two lists, one for height and another for weight, of those students.
numberOfStudents = 1000

listOfHeights = [random.randint(130, 200) for i in range(numberOfStudents)]
listOfWeights = [random.randint(50, 150) for i in range(numberOfStudents)]

# Arrange the generated data into a pandas dataframe.
df = pd.DataFrame(data = {
        'Student ID': list(np.arange(1, numberOfStudents + 1)),
        'Student Weights (kgs)': listOfWeights,
        'Student Heights (cms)': listOfHeights 
    }   
)

# Set the index of the dataframe to be the 'Student ID' column.
df.set_index('Student ID')

# Describe summary statistics of the dataframe.
df.describe()

# Calculate the averages of weights and heights of all students and print them out.
meanStudentHeight = df['Student Heights (cms)'].mean()
meanStudentWeight = df['Student Weights (kgs)'].mean()

print('The average student height in cms is:', meanStudentHeight, 'cm')
print('The average student weight in kgs is:', meanStudentWeight, 'kg')
