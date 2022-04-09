import numpy as np

originalArr = np.array([1, 2, 3, 4, 5, 6, 7, 8])

find4 = np.where(originalArr == 4)
evenArr = np.where(originalArr % 2 == 0)

print('Original: {}\nIndex where 4 is found: {}\nArray of even nos from original: {}'.format(
    originalArr, find4, evenArr
))