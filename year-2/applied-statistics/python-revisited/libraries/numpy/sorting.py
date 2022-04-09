import numpy as np

testArr1 = np.array([1, 20, 23, 14, 2, 1, 234, 12, 1, 3]) # Sorts in ascending order
testArr2 = np.array([True, False, False, True]) # False at the start of the array and then True
testArr3 = np.array(['C', 'A', 'Z', 'V']) # Sorts Alphabetically

print('1: {}\n2: {}\n3: {}'.format(np.sort(testArr1), np.sort(testArr2), np.sort(testArr3)))