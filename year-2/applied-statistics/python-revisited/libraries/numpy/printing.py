import numpy as np

oneDimArray = np.array([
    1, 2, 3, 4, 5
])

for i in oneDimArray:
    print(i, end=' ')

# Add 3 and 5 - 8
print(f'Accessing indices 3 & 5 and summing: \n{oneDimArray[2] + oneDimArray[4]}')

twoDimArray = np.array([
    [1, 2, 3, 4, 5], 
    [6, 7, 8, 9, 10]
])

print(f'Printing two dimensional arrays:')
for i in twoDimArray:
    for j in i:
        print(f'{j}', end=' ')
    print('\n')