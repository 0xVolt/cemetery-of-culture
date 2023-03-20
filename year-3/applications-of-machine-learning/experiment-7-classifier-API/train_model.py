from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score

import pickle

import pandas as pd

data = pd.read_csv('naive-bayes-classification-data.csv')
print(data)

X_train, X_test, y_train, y_test = train_test_split(data[['glucose', 'bloodpressure']], data['diabetes'], test_size=0.3, random_state=42)

print(f'X_Train shape: {X_train.shape}\ny_train shape: {y_train.shape}')

classifier = GaussianNB()
y_predicted = classifier.fit(X_train, y_train).predict(X_test)

print("Number of mislabeled points out of a total %d points : %d" % (X_test.shape[0], (y_test != y_predicted).sum()))
print("The resultant accuracy of the Gaussian Naive Bayes classifier is: %f" % accuracy_score(y_test, y_predicted))

# Save model
with open('model.pickle', 'wb') as f:
    pickle.dump(classifier, f)
