# Code by Desh Iyer

# Program demonstrating linear classification methods for two classes

# %%

# Resources
# https://scikit-learn.org/stable/modules/generated/sklearn.datasets.make_classification.html

# %%

# Import libraries
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
import numpy as np

# %%

# Function to return the weight vector W. Calculating W using the formula - [W = inverse(X'X) X' t]
def calculateWVectorX(X, t):
    XTranspose = np.transpose(X)

    # Storing inverse(X'X) into temp1
    temp1 = np.linalg.inv(np.matmul(XTranspose, X))

    # Storing inverse(X'X) X' into temp2
    temp2 = np.matmul(temp1, XTranspose)

    # Multiplying inverse(X'X) X' & t
    W = np.matmul(temp2, t)

    print("\nPrinting the W vector:")
    print(W)
    print("Shape:", np.shape(W))

    return W

#%% 

# Generate data for classification using the make_classification function part of sklearn.datasets
numberSamples = 100

# Using the testSize variable to split the data into training and testing data by (testSize * 100)% of the total data being testing data
testSize = 0.3

# The make_classification returns X (input data) and t (target prediction data) for a certain number of samples and 5 features. The n_classes=2 parameter implies that we're to be performing two class classification
X, t = make_classification(numberSamples, 5, n_classes=2, shuffle=True, random_state=21)

# %%

# Describe the shape of X and t
print("\nDescribing X and t")
print(np.shape(X))
print(np.shape(t))

# Opening the variable explorer, we can clearly see that value in t is either 0 or 1; hence the two class classification

# %%

# Creating X_0 column vector to append
X_0 = np.repeat(1, numberSamples).reshape(1, 100)

# Appending X_0
X = np.append(np.transpose(X_0), X, axis=1)

# Splitting the dataset into training and testing data with testing data size being (testSize * 100)% of the total data
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=testSize, random_state=21)


# %%

# Calculate W using a function
W = calculateWVectorX(X_train, y_train)

# %%

# Calculating y = X_test * W
y = np.matmul(X_test, W)

print("\nPrinting y = X_test * W:")
print(y)
print("Shape:", np.shape(y))

# %%

# Performing one-hot key encoding on the two class classification data

# Through y, if any values is < 0.5, make them 0 and if >= 0.5, make 1
resultY = []

for elt in y:
    if elt < 0.5:
        resultY.append(0)
    else:
        resultY.append(1)

print("\nResult of one hot key encoding:")
print(resultY)

# %%

# Comparing resultY with y_test and calculating the accuracy mathematically without the use of sklearn's score attribute
count = 0

for i in range(30):
    if resultY[i] == y_test[i]:
        count += 1

accuracy = (count / (testSize * numberSamples)) * 100

print(f'\nAccuracy: {accuracy:.3f}%') 