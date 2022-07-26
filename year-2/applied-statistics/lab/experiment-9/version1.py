# Create a random variable and insert 1000 random numbers (population). Plot the distribution. Create 30 samples from the population each of size 100. Compute the means and finally find the sampling distribution (plot)

import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import truncnorm

n = 1000
randomList = np.random.normal(loc=0, scale=1, size=n)

# Plotting the graph
# Setting a grid
plt.grid()

# Setting graph title
plt.title("Distribution of a random variable")

# Setting axes labels
plt.xlabel('x')
plt.ylabel('Normal Distribution')

# Plotting and displaying graph
plt.hist(randomList)
plt.show()

r = truncnorm.rvs(400, 500, size=100)
plt.title("Truncated Normal Distribution of 30 elements of size 100")
plt.xlabel('x')
plt.ylabel('Truncated N.Distribution')
plt.hist(r)
plt.show()