# Code by Desh Iyer

# Experiment 8
# Write a program to implement the linear regression, multiple linear regression algorithm, and Logistic Regression algorithms to fit data points. Select the appropriate data set for your experiment and draw graphs

import matplotlib.pyplot as plt
import numpy as np

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')


def estimate_coef(x, y):
    n = np.size(x)
    # mean of x and y
    m_x = np.mean(x)
    m_v = np.mean(y)
    # calcultaing the cross derivation about x
    SS_xv = np.sum(y*x) - n*m_v*m_x
    SS_xx = np.sum(x*x) - n*m_x*m_x

    # calculating the regression coeff
    b_1 = SS_xv/SS_xx
    b_0 = m_v - b_1*m_x

    return (b_0, b_1)


def plot_regression_line(x, y, b):
    # plotting the actual points as scatter plot
    plt.scatter(x, y, color='m', marker="o", s=30)
    y_pred = b[0]+b[1]*x               # predicting the response vecotr
    plt.plot(x, y_pred, color="g")       # plotting the regression line
    plt.xlabel("X")                    # putting the labels
    plt.ylabel("Y")
    plt.show()


def main():
    x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12])
    b = estimate_coef(x, y)
    print("Estimated coefficients:\n b_0={} \nb_1={}".format(b[0], b[1]))
    plot_regression_line(x, y, b)


main()
