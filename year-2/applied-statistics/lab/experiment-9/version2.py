# Code by Desh Iyer

# ----------------------------------------------------------------

# PROBLEM STATEMENT

# Create a random variable and insert 1000 random numbers (population). Plot the distribution. Create 30 samples from the population each of size 100. Compute the means and finally find the sampling distribution (plot)

# ----------------------------------------------------------------

# SOLUTION

# Import libs
import numpy as np
import random as rm
import matplotlib.pyplot as plt

# Generating random 1000 numbers as population
population = []
for i in range(1000):
    n = rm.randint(1, 1000)
    population.append(n)

print("\nThe population of different areas: ")
print(population)
print("\nMean of this data set: ")
print(np.mean(population))

# Plotting the data
plt.hist(population, bins=100)
plt.title("Data set of Population from different areas")
plt.show()

# Creating 30 samples of size 100
print("\n30 samples of size 100: ")
new_data = []
for i in range(30):
    choice = np.random.choice(population, 100)
    new_data = np.append(new_data, choice)
    new_data = np.array(new_data)

print(new_data)

# Plotting the sampling Distribution
x_var = new_data.mean()
plt.hist(x_var, bins=30)
plt.title("Sampling Distribution of new data set")
plt.show()
