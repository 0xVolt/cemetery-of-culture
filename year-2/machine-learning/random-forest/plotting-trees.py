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
import pandas
from sklearn.preprocessing import LabelEncoder
import random

# %%

# numberRows = int(input("Enter the number of samples: "))
numberRows = 5

# Create sample sets for the kind of values the features can take
choiceOfCGPA = ['g9', 'l9']
choiceOfCS = ['A', 'G']
choiceOfPK = ['++', '==']
choiceOfYN = ['Y', 'N']

CGPA = []
interactive = []
pracKnowledge = []
commSkills = []
getsJob = []

for i in range(numberRows):
    chooseCGPA = random.choice(choiceOfCGPA)
    chooseInter = random.choice(choiceOfYN)
    choosePK = random.choice(choiceOfPK)
    chooseCS = random.choice(choiceOfCS)
    chooseJob = random.choice(choiceOfYN)
    
    CGPA.append(chooseCGPA)
    interactive.append(chooseInter)
    pracKnowledge.append(choosePK)
    commSkills.append(chooseCS)
    getsJob.append(chooseJob)

# %%

data = {
    'CGPA': CGPA,
    'Interactiveness': interactive,
    'Practical Knowledge': pracKnowledge,
    'Comm. Skills': commSkills,
    'Gets Job': getsJob
}

# %% 

# Creating a dataframe using pandas with the columns populated in the above cell
table = pandas.DataFrame(data)

print(table)

# %%

# Use a value ["CGPA"]=="g9" in the table to select matching row and count the number of columns

count = table.where(table["CGPA"] == "g9")

print("Count of each column:")
print(count.count())

# %% Use LabelEncoder() to encode target labels with value between 0 and no_of_classes-1.

encoder=LabelEncoder()


#%% Then transform non-numerical labels to numerical labels.

for i in table:
    table[i]=encoder.fit_transform(table[i])


#%% Use iloc property to select by position.

X=table.iloc[:,0:4].values
t=table.iloc[:,4].values

X_train,X_test,t_train,t_test=train_test_split(X,t,test_size=0.2,random_state=2)

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