# -*- coding: utf-8 -*-
"""
Created on Tue Mar  8 13:15:06 2022

@author: Volt
"""

# %%

# Import libraries
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
import numpy as np
import matplotlib.pyplot as plt

# %%

# Function to print the summary statistics of a variable
def printSummary(var, x):
    print("\nSummary Statistics for '{}'".format(var))
    print(f"Mean = {np.mean(x)}\nStandard Deviation = {np.std(x)}")
    
# %%
# Creating the classification dataset
numberSamples = 100
testSize = 0.3
classes = 2
# X, t = make_classification(numberSamples, 1, n_classes=2, shuffle=True, random_state=21)
X, t = make_classification(numberSamples, 1, n_classes=classes, n_informative=1, n_redundant=0, shuffle=True, random_state=6, n_clusters_per_class=1)

trainSampleSize = int((1 - testSize) * numberSamples)
testSampleSize = int(testSize * numberSamples)

# Creating X_0 column vector to append
# X_0 = np.repeat(1, numberSamples).reshape(1, numberSamples)

# Appending X_0
# X = np.append(np.transpose(X_0), X, axis=1)

# %%

# Splitting the dataset into training and testing data
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=0.3, random_state=0)

# %%

reg = LogisticRegression(random_state=0).fit(X_train, y_train)

# %%

predictedOutput = reg.predict(X_test)

# print("True y:\n", y_test)
# print("\nPredicted y:\n", predictedOutput)

# Comparing true y_test with predicted y_test
count = 0

for i in range(len(y_test)):
    if y_test[i] == predictedOutput[i]:
        count += 1
        
accuracy = (count / (testSampleSize)) * 100

print(f'\nAccuracy: {accuracy:.3f}%')

# %%

plt.xlabel("X")
plt.ylabel("t")

# Plotting scatterplot
plt.scatter(X, t)
plt.show()