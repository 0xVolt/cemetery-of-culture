from itertools import permutations
import numpy as np

def NQueens(n):
    perm = list(permutations(np.array(range(n))))
    temp = []
    solutions = []

    for i in perm:
        if((len(set(i-np.array(range(n))))==n and len(set(i+np.array(range(n))))== n) == True):
            temp.append(i)

    for i in range(len(temp)):
        board = np.full((n,n),'-')

        for j in range(n):
            board[j][temp[i][j]] = '♕'
            solutions.append(board)

    return solutions

N=8
solutions = NQueens(N)
print("Total Solutions: ", len(solutions))

for i in solutions:
    print(i)
    print('----------------------------------')