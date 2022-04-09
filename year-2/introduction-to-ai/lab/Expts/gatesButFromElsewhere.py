# importing Python library
import numpy as np
  
# define Unit Step Function
def unitStep(v):
    if v >= 0:
        return 1
    else:
        return 0
  
# design Perceptron Model
def perceptronModel(x, w, b):
    v = np.dot(w, x) + b
    y = unitStep(v)
    return y

# w1 = 1, w2 = 1, b = -0.5 (OR) / -1.5 (AND)
def OR_logicFunction(x):
    w = np.array([1, 1])
    # Have value be -0.5/-1 for OR and -1.5 for AND
    b = -0.5
    return perceptronModel(x, w, b)
  
# testing the Perceptron Model
test1 = np.array([0, 1])
test2 = np.array([1, 1])
test3 = np.array([0, 0])
test4 = np.array([1, 0])

print("OR({}, {}) = {}".format(0, 1, OR_logicFunction(test1)))
print("OR({}, {}) = {}".format(1, 1, OR_logicFunction(test2)))
print("OR({}, {}) = {}".format(0, 0, OR_logicFunction(test3)))
print("OR({}, {}) = {}".format(1, 0, OR_logicFunction(test4)))