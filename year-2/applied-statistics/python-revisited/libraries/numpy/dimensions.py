import numpy as np

# 0 D array
zeroDimensionArray = np.array(10)
print(zeroDimensionArray)
print(zeroDimensionArray.ndim)

# 1 D array -> array of 0 D arrays (elts)
oneDimensionArray = np.array([1, 2, 3, 4, 5])
print(oneDimensionArray)
print(oneDimensionArray.ndim)

# 2 D array -> array of 1 D arrays
twoDimensionArray = np.array([
    [1, 2, 3, 4, 5],
    [6, 7, 8, 9, 10]
])
print(f"{twoDimensionArray}\n{twoDimensionArray.ndim}")

# 3 D array -> array of 2 D arrays
threeDimensionArray = np.array(
    [
        [
            [1, 2, 3, 4, 5],
            [6, 7, 8, 9, 10]
        ],
        [
            [11, 12, 13, 14, 15],
            [16, 17, 18, 19, 20]
        ]
    ]
)
print(f"{threeDimensionArray}\n{threeDimensionArray.ndim}")

# Create an array of 4 dims
createArray = np.array([1, 2, 3, 4], ndmin=4)
print(f'Array:\n{createArray}\nHaving dimensions: {createArray.ndim}')