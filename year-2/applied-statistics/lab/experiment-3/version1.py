# Code by Desh Iyer

# TODO
# [X] - Generate a random sample with mean = 5, std. dev. = 2. 
# [X] - Plot the distribution.
# [X] - Give the summary statistics

import numpy as np
import matplotlib.pyplot as plt
import random

# Input number of samples
numberSamples = int(input("Enter number of samples in the sample list: "))

# Generate sample list
sampleList = [random.normalvariate(5, 2) for x in range(numberSamples)]

# Printing details
print('\nGenerated sample list containing {} elements: '.format(numberSamples))
print(sampleList)
print('\n\nCalculated Mean = {:.3f}\nRounded Calculated Mean = {}\n\nCalculated Std. Deviation = {:.3f}\nRounded Calculated Std. Deviation = {}'.format(
    np.mean(sampleList), round(np.mean(sampleList)), np.std(sampleList), round(np.std(sampleList)) 
    )
)

plt.hist(sampleList)
plt.show()

# Reference:
# https://stackoverflow.com/questions/51515423/generate-sample-data-with-an-exact-mean-and-standard-deviation