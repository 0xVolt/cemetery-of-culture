import matplotlib.pyplot as plt
import numpy as np

# Set up figure and subplots
fig, axs = plt.subplots(3, 3)

# Scatter plot
x = np.random.normal(0, 1, 100)
y = np.random.normal(0, 1, 100)
axs[0, 0].scatter(x, y)
axs[0, 0].set_title("Scatter Plot")

# Line plot
x = np.linspace(0, 2 * np.pi, 100)
y = np.sin(x)
axs[0, 1].plot(x, y)
axs[0, 1].set_title("Line Plot")

# Bar plot
x = ["A", "B", "C", "D"]
y = [1, 2, 3, 4]
axs[0, 2].bar(x, y)
axs[0, 2].set_title("Bar Plot")

# Histogram
x = np.random.normal(0, 1, 100)
axs[1, 0].hist(x)
axs[1, 0].set_title("Histogram")

# Pie chart
labels = ["A", "B", "C", "D"]
sizes = [15, 30, 45, 10]
axs[1, 1].pie(sizes, labels=labels, autopct="%1.1f%%")
axs[1, 1].set_title("Pie Chart")

# Box plot
x = np.random.normal(0, 1, 100)
axs[1, 2].boxplot(x)
axs[1, 2].set_title("Box Plot")

# Violin plot
x = np.random.normal(0, 1, 100)
axs[2, 0].violinplot(x)
axs[2, 0].set_title("Violin Plot")

# Contour plot
def f(x, y):
    return np.sin(x) + np.cos(y)

x = np.linspace(0, 2 * np.pi, 100)
y = np.linspace(0, 2 * np.pi, 100)
X, Y = np.meshgrid(x, y)
Z = f(X, Y)
axs[2, 1].contour(X, Y, Z)
axs[2, 1].set_title("Contour Plot")

# 3D scatter plot
#x = np.random.normal(0, 1, 100)
#y = np.random.normal(0, 1, 100)
#z = np.random.normal(0, 1, 100)
#axs[2, 2].scatter3D(x, y, z)
#axs[2, 2].set_title("3D Scatter Plot")

#,,plt.show()
