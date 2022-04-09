# Code by Desh Iyer

# Experiment 7
# Design and implement a Perceptron learner and Neural Networks learner and test on real-world problem data sets.

import numpy as np

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

print("For AND Logic Function")


def unitStep(v):

    if v >= 0:
        return 1
    else:
        return 0


def perceptronModel(x, w, b):
    v = np.dot(w, x)+b
    y = unitStep(v)
    return y


def AND_LogicFunction(x):
    w = np.array([1, 1])
    b = -1.5
    return perceptronModel(x, w, b)


test1 = np.array([0, 1])
test2 = np.array([1, 1])
test3 = np.array([0, 0])
test4 = np.array([1, 0])

print("AND({}, {}) = {}".format(0, 1, AND_LogicFunction(test1)))
print("AND({}, {}) = {}".format(1, 1, AND_LogicFunction(test2)))
print("AND({}, {}) = {}".format(0, 0, AND_LogicFunction(test3)))
print("AND({}, {}) = {}".format(1, 0, AND_LogicFunction(test4)))


print("\nFor OR Logic Function")


def unitStep(v):
    if v >= 0:
        return 1
    else:
        return 0


def perceptronModel(x, w, b):
    v = np.dot(w, x) + b
    y = unitStep(v)
    return y


def OR_logicFunction(x):
    w = np.array([1, 1])
    b = -0.5
    return perceptronModel(x, w, b)


test1 = np.array([0, 1])
test2 = np.array([1, 1])
test3 = np.array([0, 0])
test4 = np.array([1, 0])

print("OR({}, {}) = {}".format(0, 1, OR_logicFunction(test1)))
print("OR({}, {}) = {}".format(1, 1, OR_logicFunction(test2)))
print("OR({}, {}) = {}".format(0, 0, OR_logicFunction(test3)))
print("OR({}, {}) = {}".format(1, 0, OR_logicFunction(test4)))
