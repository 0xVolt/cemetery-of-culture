import numpy as np
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings('ignore')

numberSamples = 100

deLinearise = lambda X: np.cos(1.5 * np.pi * X) + np.cos(5 * np.pi * X)

X = np.sort(np.random.rand(numberSamples)) * 2
y = deLinearise(X) + np.random.randn(numberSamples) * 0.1

X = X.reshape(X.shape[0], 1)
y = y.reshape(y.shape[0], 1)


def main():
    tauList = np.arange(0, 1, step=0.2)
    
    predictionsList = []

    for tau in tauList:
        XTest, predictions = getPredictionsForSingleTau(numberSamples, tau)
        
        predictionsList.append(predictions)
        
    predictionsList = np.array(predictionsList)
    print(predictionsList.shape)
        
    
def getPredictionsForSingleTau(numberPredictions, tau):
    XTest = np.sort(np.random.rand(numberPredictions)) * 2

    # Empty list for storing predictions.
    predictions = []

    # Predicting for all numberPredictions values and storing them in predictions.
    for point in XTest:
        theta, predicted = predict(X, y, point, tau)
        predictions.append(predicted)

    # Reshaping X_test and predictions
    XTest = np.array(XTest).reshape(numberPredictions, 1)
    predictions = np.array(predictions).reshape(numberPredictions, 1)
    
    return XTest, predictions


def predict(X, y, point, tau):
    # m = number of training examples.
    m = X.shape[0]

    onesColumn = np.ones(m).reshape(m, 1)

    # Appending a column of ones in X to add the bias term. Just one parameter: theta, that's why adding a column of ones to X and also adding a 1 for the point where we want to predict.
    X_ = np.append(X, onesColumn, axis=1)

    # point is the x where we want to make the prediction.
    point_ = np.array([point, 1])

    # Calculating the weight matrix using the wm function we wrote      #  # earlier.
    w = calculateWeightMatrix(point_, X_, tau)

    # Calculating parameter theta using the formula.
    theta = np.linalg.pinv(X_.T * (w * X_)) * (X_.T * (w * y))

    # Calculating predictions.
    pred = np.dot(point_, theta)

    # Returning the theta and predictions
    return theta, pred


def calculateWeightMatrix(point, X, tau):
    '''
    The parameters of this function are,
		tau --> bandwidth
		X --> Training data.
		point --> the x where we want to make the prediction.
    '''

    # m is the No of training examples .
    m = X.shape[0]

    # Initialising W as an identity matrix.
    w = np.mat(np.eye(m))

    # Calculating weights for all training examples [x(i)'s].
    for i in range(m):
        xi = X[i]
        d = (-2 * tau * tau)
        w[i, i] = np.exp(np.dot((xi - point), (xi - point).T) / d)

    return w


if __name__ == "__main__":
    main()
    

# COPYPASTA HERE!

# Plotting
    # plt.figure(figsize=(20, 15), dpi=80)

    # plt.title(f'Best Fit Curve for tau = {tau}')

    # # Tip: using `marker="o"`, gives you dots with a line joining them
    # plt.plot(X, y, marker="o", color='orange', alpha=0.45, label='Training Data Points')
    # plt.plot(XTest, predictions, 'c--', label='Best Fit Curve')

    # plt.legend()
    # plt.show()