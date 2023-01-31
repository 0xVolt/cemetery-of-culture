# -*- coding: utf-8 -*-
"""
Created on Tue Mar 15 13:10:36 2022

@author: Volt
"""

# %%

# TODO
# [X] - Randomly generate rows
# [X] - Randomly populate rows
# [ ] - Make prediction list user driven or less hard-coded at least

# %%

# Importing libraries
import pandas
import random
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier

# %%

'''
Creating data to fit to a dataframe. Data consists of a table with the features 
CGPA, Interaction, Practical Knowledge and Communication Skills. What needs to be predicted, i.e., 
the output metric, is Job. The boolean value that tells us whether a student gets the job or not.

In this cell, we make it our mission to refactor the given code and make sure it generates 
as random of a dataset as possible, 

if thats even a thing...
'''

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

print('Displaying the dynamically generated dataset:\n\n', table)

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

# %% Use RandomForestClassifier class. The most important parameter used is n_estimators. It determines the number of trees used in the Random Forest

model = RandomForestClassifier(n_estimators=3, criterion="entropy")
model.fit(X_train,t_train)

# The non-numerical equivalent of the new instance [0, 1, 1, 1] given is [‘g9’, ‘Y’, ‘==’, ‘G’]

print("\nResult according to the Random Forest Classifier:")

if model.predict([[0,1,1,1]])==1:
    print("Got JOB")
else:
    print("Didn't get JOB")

# %%

from sklearn.ensemble import AdaBoostClassifier

ada = AdaBoostClassifier()
ada = ada.fit(X_train,t_train)

print("\nResult according to the AdaBoost Classifier:")

if model.predict([[0,1,1,0]])==1:
    print("Got JOB")
else:
    print("Didn't get JOB")
