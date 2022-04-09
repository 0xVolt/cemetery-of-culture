import numpy as np

# Makng the AND gate

# Define unit step function
def unitStep(v):
    if v >= 0:
        return 1
    else:
        return 0

# Define perceptron model function
def perceptronModel(x, w, b):
    v = np.dot(w, x) + b
    y = unitStep(v)

    return y

# Define the function to process AND gate
def andLogicFunction(x):
    w = np.array([1, 1])
    b = -1.5
    return perceptronModel(x, w, b)

p = int(input("Enter a boolean for p (1 / 0): "))
q = int(input("Enter a boolean for q (1 / 0): "))

test1 = np.array([p, q])

print("Output: ", andLogicFunction(test1))