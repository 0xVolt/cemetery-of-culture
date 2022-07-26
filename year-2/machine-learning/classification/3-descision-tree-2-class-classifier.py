# -*- coding: utf-8 -*-
"""
Created on Tue Mar  8 13:21:23 2022

@author: Volt

Implementation of a 2 class decision tree classifier in python using sklearn
"""

# %%

# Import libraries
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn import tree

# %%

# Creating the classification dataset
numberSamples = 10
testSize = 0.3
testSampleSize = int(testSize * numberSamples)
trainSampleSize = int((1 - testSize) * numberSamples)
classes = 2
features = 5

X, t = make_classification(numberSamples, features, n_classes=classes, shuffle=True, random_state=21)

# Creating X_0 column vector to append
X_0 = np.repeat(1, numberSamples).reshape(1, numberSamples)

# Appending X_0
X = np.append(np.transpose(X_0), X, axis=1)

# %%

# Splitting the dataset into training and testing data
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=testSize, random_state=0)

# %%

clf = tree.DecisionTreeClassifier()
clf = clf.fit(X_train, y_train)

# %%

predictedOutput = clf.predict(X_test)

print("True y:\n", y_test)
print("\nPredicted y using clf.predict():\n", predictedOutput)

# Comparing true y_test with predicted y_test
count = 0

for i in range(len(y_test)):
    if y_test[i] == predictedOutput[i]:
        count += 1
        
accuracy = (count / (testSampleSize)) * 100

print(f'\nAccuracy: {accuracy:.3f}%')

# %%

tree.plot_tree(clf)

# %%

# To verify that the root node of the decision tree is displaying the right values

print("Displaying statistics of y_train")

count1 = 0

for i in y_train:
    if i == 1:
        count1 += 1

count0 = len(y_train) - count1
        
print(y_train)
print("1s: ", count1)
print("0s: ", count0)