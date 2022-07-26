# -*- coding: utf-8 -*-
"""
Created on Tue Mar 15 10:11:07 2022

@author: gopal.singh
"""

import pandas
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier


#%% Create a list ‘data’ with the sample dataset
data = {'CGPA':['g9','l9','g9','l9','g9'],
        'Inter':['Y','N','N','N','Y'],
        'PK':['++','==','==','==','=='],
        'CS':['G','G','A','A','G'],
        'Job':['Y','Y','N','N','Y']}

#%% Create pandas dataframe “table” using the structure DataFrame with the given dataset
table=pandas.DataFrame(data,columns=["CGPA","Inter","PK","CS","Job"])


#%% Use a value ["CGPA"]=="g9" in the table to select matching row and count the number of columns.

count = table.where(table["CGPA"]=="g9").count()
print(count)



#%% Use LabelEncoder() to encode target labels with value between 0 and no_of_classes-1.

encoder=LabelEncoder()



#%% Then transform non-numerical labels to numerical labels.

for i in table:
    table[i]=encoder.fit_transform(table[i])


#%% Use iloc property to select by position.

X=table.iloc[:,0:4].values
t=table.iloc[:,4].values

X_train,X_test,t_train,t_test=train_test_split(X,t,test_size=0.2,random_state=2)




#%% Use RandomForestClassifier class. The most important parameter used is n_estimators. It determines the number of trees used in the Random Forest

model = RandomForestClassifier(n_estimators=3)
model.fit(X_train,t_train)

#%% the fitted model can be used to predict a new instance.

# The non-numerical equivalent of the new instance [0, 1, 1, 1] given is [‘g9’, ‘Y’, ‘==’, ‘G’]

if model.predict([[0,1,1,1]])==1:
    print("Got JOB")
else:
    print("Didn't get JOB")


# The non-numerical equivalent of the new instance [0, 0, 1, 0] given is [g9’, ‘N’, ‘==’, ‘A’]












