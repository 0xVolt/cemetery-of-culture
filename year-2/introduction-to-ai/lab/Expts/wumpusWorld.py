# Part 1

# 4x4 grid
# S     B P
# W BGS P B
# S     B 
# A 

# Location of the agent is fixed in a corner of the grid

# All other rooms and locations are random
# rooms neighbouring pits must have breeze

import random

charSet = ['G', 'W', 'B', 'P', ' ']

initialWorld = [
    ['S', ' ', 'B', 'P'],
    ['W', 'G', 'P', 'B'],
    ['S', ' ', 'B', ' '],
    ['A', ' ', ' ', ' ']
]

count = 0

for row in initialWorld:
    initialWorld.remove(row)

    ls = []

    for i in range(4):
        ls.append(random.choice(charSet))

    initialWorld.insert(count, ls)

    count += 1

print(*initialWorld, sep='\n')