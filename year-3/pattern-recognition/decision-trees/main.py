#%%
# Import libraries
from sklearn.datasets import load_iris
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.tree import plot_tree
import matplotlib.pyplot as plt

#%%
# Load dataset
iris = load_iris()

#%%
# Split dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, test_size=0.2, random_state=42)

#%%
# Create decision tree classifier
clf = DecisionTreeClassifier(random_state=42)

#%%
# Train the classifier on the training data
clf.fit(X_train, y_train)

#%%
# Evaluate the classifier on the testing data
y_pred = clf.predict(X_test)

#%%
# Calculate and print accuracy score
print("Accuracy:", accuracy_score(y_test, y_pred))

#%%
# Print classification report
print("Classification Report:")
print(classification_report(y_test, y_pred))

#%%
# Print confusion matrix
print("Confusion Matrix:")
print(confusion_matrix(y_test, y_pred))

#%%
# Plot decision tree
plt.figure(figsize=(20,10))
plot_tree(clf, filled=True, rounded=True, class_names=iris.target_names, feature_names=iris.feature_names)
plt.show()