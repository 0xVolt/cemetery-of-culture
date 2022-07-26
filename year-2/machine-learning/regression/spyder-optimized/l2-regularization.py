# -*- coding: utf-8 -*-
"""
Created on Tue Feb 15 13:03:14 2022

@author: Desh Iyer
"""

# %%

# Resources
# https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.Ridge.html

# %%

# Instructions

# Two graphs for test and train for L. Regression model
# Two graphs for test and train for Ridge Regression model
# Analyse the differences/similarities for low and high noise
# Assume alpha = 1.0

# %%

# Import libraries
from sklearn.datasets import make_regression
from sklearn.linear_model import Ridge
from sklearn.metrics import r2_score
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt
import numpy as np

# %%

# Code to learn syntax

# X, T = make_regression(1000, 5, n_targets=2, shuffle=True, bias=0, noise=25, random_state=66)

# reg = LinearRegression().fit(X, T)
# clf = Ridge(alpha=1.0)
# clf.fit(X, T)

# %%

# Create lists to store 

# Create noise and score vectors
noiseVector = np.arange(0, 110, 10)

# Create arrays to store values for Linear Regression Model
rScoreDifferenceLinearRegression = []
rTrainingListLinearRegression = []
rTestingListLinearRegression = []

# Create arrays to store values for Ridge Regression Model
rScoreDifferenceRidgeRegression = []
rTrainingListRidgeRegression = []
rTestingListRidgeRegression = []

# %%

# Creating models for each value of noise in noiseVector

for i in noiseVector:
    # Create data to fit into Regression models
    X, T = make_regression(100, 1, n_targets=1, shuffle=True, bias=0, noise=i, random_state=42)
    
    # Split dataset into training and testing data
    X_train, X_test, y_train, y_test = train_test_split(X, T, test_size=0.3, random_state=42)
    
    # Create the LR and RR Models with training data
    reg = LinearRegression().fit(X_train, y_train)
    clf = Ridge(alpha=25.0)
    clf.fit(X_train, y_train)

    # Calculate r2 scores for Linear Regression
    rTrainingLR = r2_score(y_train, reg.predict(X_train))
    rTestingLR = r2_score(y_test, reg.predict(X_test))
    
    # Calculate r2 scores for Ridge Regression
    rTrainingRR = r2_score(y_train, clf.predict(X_train))
    rTestingRR = r2_score(y_test, clf.predict(X_test))

    # Append to Linear Regression Lists
    rTrainingListLinearRegression.append(rTrainingLR)
    rTestingListLinearRegression.append(rTestingLR)
    
    # Append to Ridge Regression Lists
    rTrainingListRidgeRegression.append(rTrainingRR)
    rTestingListRidgeRegression.append(rTestingRR)
    
    # Update rScoreDifference Lists
    rScoreDifferenceLinearRegression.append(abs(rTestingLR - rTrainingLR))
    rScoreDifferenceRidgeRegression.append(abs(rTestingRR - rTrainingRR))
    
# %%    

# Plotting the graph for Linear Regression Model

plt.title("Linear Regression Model")

plt.xlabel("Noise")
plt.ylabel("R-Score")

plt.plot(noiseVector, rTestingListLinearRegression, "-", label="Testing")
plt.plot(noiseVector, rTrainingListLinearRegression, "-", label="Training")

plt.legend(loc="lower left")

# %%

# Plotting the graph for Ridge Regression Model

plt.title("Ridge Regression Model")

plt.xlabel("Noise")
plt.ylabel("R-Score")

plt.plot(noiseVector, rTestingListRidgeRegression, "-", label="Testing")
plt.plot(noiseVector, rTrainingListRidgeRegression, "-", label="Training")

plt.legend(loc="lower left")

# %% 

# Plotting difference in noise values between training and testing
plt.title("Linear Regression Model")
plt.xlabel("Noise Values")
plt.ylabel("Absolute Difference of R-Scores - Linear Regression")
plt.plot(noiseVector, rScoreDifferenceLinearRegression)

# %% 

# Plotting difference in noise values between training and testing
plt.title("Ridge Regression Model")
plt.xlabel("Noise Values")
plt.ylabel("Absolute Difference of R-Scores - Ridge Regression")
plt.plot(noiseVector, rScoreDifferenceRidgeRegression)

# %%

# Notes

# As number of training samples, the model becomes more generalized, i.e., 
# the lines come closer to each other

# Check the models taking 100 samples, output as 1 dimension, alpha 500.0