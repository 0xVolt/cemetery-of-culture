import numpy as np

oneDimArr = np.array([
    1, 2, 3, 4, 5, 6, 7, 8, 9
])

# Split array into 3 equal parts
newOneDimArr = np.array_split(oneDimArr, 3)

# Prints three different arrays
    # print(newOneDimArr)

print('Original Array: {}\nSplit Arrays: {}\nFirst array after split: {}'.format(oneDimArr, newOneDimArr, newOneDimArr[0]))