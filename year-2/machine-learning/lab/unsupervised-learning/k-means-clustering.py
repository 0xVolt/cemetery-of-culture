# -*- coding: utf-8 -*-
"""
@author: Volt

Implementation of a multi-class K-Means Clustering model using sklearn in python
"""

# %%

from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import numpy as np

# %%

numberSamples = 100
numberClasses = 2
numberFeatures = 2
testSize = 0.3

X, t = make_classification(numberSamples, n_features=numberFeatures, n_classes=numberClasses, n_informative=2, n_redundant=0, shuffle=True, random_state=0)

# %%

X_train, X_test, y_test, y_train = train_test_split(X, t, test_size=testSize, random_state=0)

# %%

numberClusters = int(input("Enter the number of clusters: "))
model = KMeans(n_clusters=numberClusters, random_state=0).fit(X_train)

# %%

clusterCenters = model.cluster_centers_

# %%

colors = []
labels = model.labels_

for i in labels:
    if i == 0:
        colors.append('red')
    elif i == 1:
        colors.append('blue')
    elif i == 2:
        colors.append('green')

# %%

plt.scatter(clusterCenters[:,0], clusterCenters[:,1], color='black')
for i in range(len(X)):
    plt.scatter(X[i][0], X[i][1], color=colors[i])
    
# %%

prediction = model.predict(X_test)
accuracy = np.count_nonzero((prediction == y_test) == True) / len(y_test) * 100

print("Mathematically Computed Accuracy = {:.3}%\nSklearn's Accuracy Attribute = {:3}%".format(accuracy, model.score_))