# Code by Desh Iyer, to display the solutions for the n-queens problem given n as the dimensions of the board and the number of queens.

# Importing libraries
from itertools import permutations
import numpy as np


# Defining a function to implement n-queens
def NQueens(n):
    perm = list(permutations(np.array(range(n))))
    temp = []
    solutions = []

    for i in perm:
        if ((len(set(i-np.array(range(n)))) == n and len(set(i+np.array(range(n)))) == n) == True):
            temp.append(i)

    for i in range(len(temp)):
        board = np.full((n, n), '-')

        for j in range(n):
            board[j][temp[i][j]] = '♕'
            solutions.append(board)

    return solutions


N = 4
solutions = NQueens(N)
print("Total Solutions: ", len(solutions))

for i in solutions:
    print(i)
    print('\n----------------------------------\n')
