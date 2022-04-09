# -*- coding: utf-8 -*-
"""
Created on Tue Mar 29 14:23:16 2022

@author: Volt
"""

# Importing libraries
from sklearn.datasets import make_regression
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
from sklearn import tree

#%%

# Making a regression data set
X, t = make_regression(100, 5, shuffle=True, random_state=21)
X_train, X_test, y_train, y_test = train_test_split(X, t, test_size=0.3, random_state=22)

#%%

# Make and fit the model
model = RandomForestRegressor(n_estimators=3)
model.fit(X_train, y_train)

#%%

# Obtaining the scores for both testing and training
score_test = model.score(X_test, y_test)
score_train = model.score(X_train, y_train)

estimator = model.estimators_

# %%

# n = int(input("One of 3: "))

tree.plot_tree(estimator[1])