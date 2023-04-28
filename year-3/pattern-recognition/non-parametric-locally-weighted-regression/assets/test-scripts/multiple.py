import numpy as np
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings('ignore')

# Define global variables
number_samples = 500
tau_list = np.arange(0, 0.2, step=0.01)
tau_test = 0.08

# Lambda function to de-linearize input function
de_linearize = lambda X: np.cos(1.5 * np.pi * X) + np.cos(5 * np.pi * X)

# Define X and y
X = np.sort(np.random.rand(number_samples)) * 2
y = de_linearize(X) + np.random.randn(number_samples) * 0.1

X = X.reshape(X.shape[0], 1)
y = y.reshape(y.shape[0], 1)

# Function to calculate weight matrix
def calculate_weight_matrix(point, X, tau):
    m = X.shape[0]
    w = np.mat(np.eye(m))
    for i in range(m):
        xi = X[i]
        d = (-2 * tau * tau)
        w[i, i] = np.exp(np.dot((xi - point), (xi - point).T) / d)
    return w

# Function to predict for a single point in the input vector
def predict_single_point(X, y, point, tau):
    w = calculate_weight_matrix(point, X, tau)
    theta = np.linalg.pinv(X.T * (w * X)) * (X.T * (w * y))
    point_prediction = np.dot(point, theta)
    return theta, point_prediction

# Function to predict for a single tau value for all the points in the input vector
def predict_single_tau(X_test, tau):
    prediction_for_single_tau = []
    for point in X_test:
        _, point_prediction = predict_single_point(X, y, point, tau)
        prediction_for_single_tau.append(point_prediction)
    prediction_for_single_tau = np.array(prediction_for_single_tau).reshape(number_samples, 1)
    return prediction_for_single_tau

# Plot the training data
plt.figure(figsize=(15, 10), dpi=80)
plt.scatter(X, y, s=10, c='orange', marker='o', alpha=0.6)

# Define testing data to predict
X_test = np.sort(np.random.rand(number_samples)) * 2
X_test = np.array(X_test).reshape(number_samples, 1)

# Predict for each tau value and plot
for i, tau in enumerate(tau_list):
    prediction = predict_single_tau(X_test, tau)
    # Lower delta value to reverse gradient
    color = plt.cm.BuPu(0.9 - (i / len(tau_list)))
    plt.plot(X_test, prediction, color=color, alpha=0.4, label=f'tau={tau:.2f}')

# Set plot attributes
plt.title("Locally Weighted Regression")
plt.xlabel("X")
plt.ylabel("y")
plt.legend()
plt.show()
