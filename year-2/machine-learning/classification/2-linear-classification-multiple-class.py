# -*- coding: utf-8 -*-
"""
Created on Tue Feb 22 13:03:20 2022

@author: Desh Iyer
"""

# %%

# Resources
# https://scikit-learn.org/stable/modules/generated/sklearn.datasets.make_classification.html

# %%

# Import libraries
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np

# %%

# Calculating W using the formula - [W = inverse(X'X) X' t]
def calculateWVectorX(X, t):
    XTranspose = np.transpose(X)

    tempTerm1 = np.linalg.inv(np.matmul(XTranspose, X))

    tempTerm2 = np.matmul(tempTerm1, XTranspose)

    W = np.matmul(tempTerm2, t)

    print("Printing the W vector:")
    print(W)
    print("Shape:", np.shape(W))
    
    return W

#%% 

# Generate data for classification
# numberSamples = 100
# testSize = 0.3
# X, t = make_classification(numberSamples, 5, n_classes=2, shuffle=True, random_state=21)

# %%

numberSamples = 100
testSize = 0.3
testSampleSize = int(testSize * numberSamples)
trainSampleSize = int((1 - testSize) * numberSamples)
classes = 3

X, t = make_classification(numberSamples, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)

# Creating X_0 column vector to append
X_0 = np.repeat(1, numberSamples).reshape(1, numberSamples)

# Appending X_0
X = np.append(np.transpose(X_0), X, axis=1)

# Splitting the dataset into training and testing data
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=testSize, random_state=0)

res = np.zeros((y_train.shape[0], classes), dtype=int)
res[np.arange(y_train.shape[0]), y_train] = 1



# %%

# Describe the shape of X and t
print(np.shape(X))
print(np.shape(t))

# Opening the variable explorer, we can clearly see that value in t is either 0 or 1

# %%

# Calculate W using a function using X_train and res
W = calculateWVectorX(X_train, res)

# %%

# Calculating y = X_test * W

y = np.matmul(X_test, W)

print("Printing y = X_test * W:")
print(y)
print("Shape:", np.shape(y))

# %%

oneHotEncoded = np.zeros((testSampleSize, 3), dtype=int)

index = 0
for row in y:
    if row[0] > row[1] and row[0] > row[2]:
        oneHotEncoded[index][0] = 1
    elif row[1] > row[0] and row[1] > row[2]:
        oneHotEncoded[index][1] = 1
    else:
        oneHotEncoded[index][2] = 1
        
    index += 1
    
# %%

convertedDecisionList = []

'''
for i in range(len(oneHotEndcoded)):
    convertedDecisionList.append(
        np.where(
            oneHotEndcoded[i] == max(oneHotEndcoded[i])    
        )[0][0]
    )
'''
    
# OR
convertedDecisionList = np.argmax(oneHotEncoded, axis=1)

# %%

# Comparing convertedDecisionList with y_test
count = 0

for i in range(testSampleSize):
    if convertedDecisionList[i] == y_test[i]:
        count += 1
        
accuracy = (count / (testSampleSize)) * 100

print(f'Accuracy: {accuracy:.3f}%')