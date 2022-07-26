import numpy as np          # import the numpy module

# create a 1D array using np

""" 
A = np.array(
    [1, 2, 3, 4]
)

print(A) 
print(A.size)           # print size of array
print(A.itemsize)       # print the size of each item in array
"""

# create a 2D array using np

""" 
B = np.array([
        (1, 2, 3, 4),
        (5, 6, 7, 8)
    ]
)

print(B)
print(B.shape, 'in the form (rows, cols)') 
"""

# reshape an array - turn (2, 4) into (4, 2)

""" 
C = np.array(
    [
        (1, 2, 3, 4),
        (5, 6, 7, 8)
    ]
)

print('Original:\n', C)
print(C.shape)
C = C.reshape(4, 2)
print('\nNew:\n', C, '\n', C.shape) 
"""

# print the value at a certain index, i.e. SLICING in numpy arrays

""" 
D = np.array([(1, 2, 3, 4), (5, 6, 7, 8)])

print(D.shape)

# remember, numpy array notation is NOT the same as regular array notiation in C, C++
# here, instead of writing D[0][2] to print 3, 
# we write D[0, 2]

# to print the last column
print(D[0:, 3])
"""

# print 5 values between 3 and 6 which are EQUALLY spaced using np

""" 
E = np.linspace(3, 6, 5)
print(E)

"""

# more operations

""" 
F = np.array([1, 2, 3, 4])

print(F)
print('\nmax:', F.max(), '\nmin:', F.min(), '\nsum:', F.sum())
 """

# Note: Rows are named AXIS 1 and Cols are named AXIS 0

""" G = np.array([(1, 2, 3), (4, 5, 6), (7, 8, 9)])
print(G)
print('Sum of cols: ', G.sum(axis = 0))          # print sum of cols
print('Sum of rows: ', G.sum(axis = 1))          # print sum of rows
 """

# finding sqrt -> np.sqrt(array)
# finding std deviation -> np.std(array)

""" 
H = np.array([(1, 2, 3), (4, 5, 6)])

print('Original:\n{}'.format(H))
print('\nSquare root array:\n{}'.format(np.sqrt(H)))
print('\nStd deviation array:\n{}'.format(np.std(H)))
 """

# matrix operations

""" 
I = np.array([(1, 2, 3), (4, 5, 6)])
J = np.array([(7, 8, 9), (10, 11, 12)])

print(I + J)
print()
print(I - J)
print()
print(I * J)
print()
print(I / J)
 """

# display the arrays as stacks vertically or horizontally
# rememember that the arrays are passed in the form of a tuple and not naked

""" 
I = np.array([(1, 2, 3), (4, 5, 6)])
J = np.array([(7, 8, 9), (10, 11, 12)])

print(np.vstack((I, J)))
print()
print()
print(np.hstack((I, J)))
 """

# print all elts in the array in one col -> use np.ravel()

""" 
K = np.array([(1, 2, 3, 4), (5, 6, 7, 8)])
print(K)
print('\nRavelled:\n', np.ravel(K))
 """

# SPECIAL FUNCTIONS IN NUMPY

# sine and cosine using np and matplotlib

""" 
import matplotlib.pyplot as plt

x = np.arange(0, 3 * np.pi, 0.1)        # list with vals 0 -> 3 pi (not included) with 0.1 increment
y1 = np.sin(x)           # list with the sin values for each elt in x

plt.plot(x, y1)          # elt on x axis and sin value on y axis
plt.show()               # opens a graph in a new window

y2 = np.cos(x)

plt.plot(x, y2)
plt.show()               # plot shows after first one is closed
 """

# exponential and logarithmic

""" 
L = np.array([(1, 2, 3), (4, 5, 6)])

print('Original:\n', L, '\n')
print('exponential:\n', np.exp(L))
print('\nlogarithmic base 2:\n', np.log(L))
print('\nlogarithmic base 10:\n', np.log10(L))
 """

x = (1, 2, 3, 4)

print(x.group())