# Code by Desh Iyer

import matplotlib.pyplot as plt
import numpy as np

# Print details
print("Bayesian Networks")
print("Desh Iyer, 500081889, B3")

def estimate_coef(x, y):
    n = np.size(x)
    
    # Mean of x and y
    m_x = np.mean(x)
    m_v = np.mean(y)
    
    # Calculating the cross derivation about x
    SS_xv = np.sum(y*x) - n*m_v*m_x
    SS_xx = np.sum(x*x) - n*m_x*m_x

    # Calculating the regression coeff
    b_1 = SS_xv/SS_xx
    b_0 = m_v - b_1*m_x

    return (b_0, b_1)


def plot_regression_line(x, y, b):
    # plotting the actual points as scatter plot
    plt.scatter(x, y, color='m', marker="o", s=30)
    
    # predicting the response vector
    y_pred = b[0]+b[1]*x               
    
    # plotting the regression line
    plt.plot(x, y_pred, color="g") 
    
    # putting the labels
    plt.xlabel("X")                    
    plt.ylabel("Y")
    plt.show()


def main():
    x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12])
    b = estimate_coef(x, y)
    print("Estimated coefficients:\n b_0={} \nb_1={}".format(b[0], b[1]))
    plot_regression_line(x, y, b)


main()
