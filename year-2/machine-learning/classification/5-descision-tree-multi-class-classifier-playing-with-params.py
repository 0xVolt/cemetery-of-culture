# -*- coding: utf-8 -*-
"""
Created on Tue Mar  8 13:21:23 2022

@author: Volt

Implementation through experimentation, of a multi-class decision tree classifier in python using sklearn
"""

# %%

# Import libraries
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np
from sklearn import tree

# %%

# Creating the classification dataset
numberSamples = 100
testSize = 0.3
testSampleSize = int(testSize * numberSamples)
trainSampleSize = int((1 - testSize) * numberSamples)
classes = 4

X, t = make_classification(numberSamples, 5, n_classes=classes, random_state=40, n_informative=2, n_clusters_per_class=1)

# Creating X_0 column vector to append
X_0 = np.repeat(1, numberSamples).reshape(1, numberSamples)

# Appending X_0
X = np.append(np.transpose(X_0), X, axis=1)

# %%

# Splitting the dataset into training and testing data
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=testSize, random_state=0)

# %%

# Play around with the arguments to this function
# Note: For demo, change the max_leaf_nodes and illustrate the tree and observe the change in accuracy
clf = tree.DecisionTreeClassifier(
    criterion="entropy",
    max_leaf_nodes=None
    ).fit(X_train, y_train)

# Default way:
# clf = tree.DecisionTreeClassifier().fit(X_train, y_train)

# %%

# Calculating the accuracy of the model without calling a a function or an attribute

print("\nCalculating the accuracy of the model")
predictedOutput = clf.predict(X_test)

print("True y:\n", y_test)
print("\nPredicted y:\n", predictedOutput)

# Comparing true y_test with predicted y_test
count = 0

for i in range(len(y_test)):
    if y_test[i] == predictedOutput[i]:
        count += 1
        
accuracy = (count / (testSampleSize)) * 100

print(f'\nAccuracy: {accuracy:.3f}%')

# %%

# Plotting the decision tree
tree.plot_tree(clf)