from sklearn.datasets import make_classification

XSampleNum = 100
Classes = 2
TestSize = 0.3

X,T = make_classification(XSampleNum,2,n_classes = Classes,n_informative=2,n_redundant=0, shuffle=True, random_state=68)
Data = []
for i in range(len(X)):
    Data.append(X[i])
#%%
from sklearn.cluster import KMeans
nClusters = int(input("Enter the number of clusters: "))
model = KMeans(n_clusters = nClusters, random_state = 0).fit(X)
#%%
Kcenter = model.cluster_centers_
labels = model.labels_
# clusterCentroids = model.cluster_centroids_

#%%

from random import randint

randomColours = []

for i in range(nClusters):
    randomColours.append('#%06X' % randint(0, 0xFFFFFF))


# %%

uniqueLabels = set(labels)

# %%

for i in range(len(Data)):
    if labels[i] == 0:
        colors.append(random.choice(randomColours))
    elif labels[i] == 1:
        c1 = random.choice(colorSet)
        if c1 not in colorSet:
            colors.append(c1)
    elif labels[i] == 2:
        c2 = random.choice(colorSet)
        if c2 not in colorSet:
            colors.append(c2)
    else:
        c3 = random.choice(colorSet)
        if c3 not in colorSet:
            colors.append(c3)

#%%
import matplotlib.pyplot as plt

plt.scatter(Kcenter[:,0], Kcenter[:,1], color = 'black')
for i in range(len(Data)):
    plt.scatter(Data[i][0], Data[i][1], color = colors[i])