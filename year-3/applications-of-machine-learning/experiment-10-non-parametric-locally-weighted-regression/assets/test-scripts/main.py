# %% Import Libraries

import numpy as np
import matplotlib.pyplot as plt
import warnings
warnings.filterwarnings('ignore')

# %% Define global variables

numberSamples = 250

# %% Lambda function to de-linearise input function

deLinearise = lambda X: np.cos(1.5 * np.pi * X) + np.cos(5 * np.pi * X)

# %% Define X and y

X = np.sort(np.random.rand(numberSamples)) * 2
y = deLinearise(X) + np.random.randn(numberSamples) * 0.1

X = X.reshape(X.shape[0], 1)
y = y.reshape(y.shape[0], 1)

# %% Define tau

tauList = np.arange(0, 0.2, step=0.05)
tauTest = 0.08

# %% Function to calculate weight matrix

def calculateWeightMatrix(point, X, tau):
    '''
    The parameters of this function are,
		tau --> bandwidth
		X --> Training data.
		point --> the x where we want to make the prediction.
    '''

    # m is the number of training examples .
    m = X.shape[0]

    # Initialising W as an identity matrix.
    w = np.mat(np.eye(m))

    # Calculating weights for all training examples [x(i)'s].
    for i in range(m):
        xi = X[i]
        d = (-2 * tau * tau)
        w[i, i] = np.exp(np.dot((xi - point), (xi - point).T) / d)

    return w


# %% Function to predict for a single point in the input vector

def predictSinglePoint(X, y, point, tau):
    # Calculating the weight matrix using the wm function we wrote earlier.
    w = calculateWeightMatrix(point, X, tau)

    # Calculating parameter theta using the formula.
    theta = np.linalg.pinv(X.T * (w * X)) * (X.T * (w * y))

    # Calculating predictions.
    pointPrediction = np.dot(point, theta)

    # Returning the theta and predictions
    return theta, pointPrediction


# %% Function to predict for a single tau value for all the points in the input vector

def predictSingleTau(XTest, tau):
    # Empty list for storing predictions.
    predictionForSingleTau = []
    thetaForSingleTau = []

    # Predicting for all numberPredictions values and storing them in predictions.
    for point in XTest:
        theta, pointPrediction = predictSinglePoint(X, y, point, tau)
        predictionForSingleTau.append(pointPrediction)
        thetaForSingleTau.append(thetaForSingleTau)

    # Reshaping predictions
    predictionForSingleTau = np.array(predictionForSingleTau).reshape(numberSamples, 1)

    return thetaForSingleTau, predictionForSingleTau


# %% Plot the training data

plt.figure(figsize=(20, 15), dpi=80)
plt.plot(X, y, marker="o", color='orange', alpha=0.8, label='Training Data Points')

# %% Define testing data to predict

XTest = np.sort(np.random.rand(numberSamples)) * 2
XTest = np.array(XTest).reshape(numberSamples, 1)

# %% Predict for a single tau value

_, prediction = predictSingleTau(XTest, tauTest)
plt.plot(XTest, prediction)

# %% Render plot

plt.legend()
plt.show()