import matplotlib.pyplot as plt
import numpy as np

xRange = int(input("Enter the range of x coordinates: "))
xScale = int(input("Enter the scale of x axis: "))

# Making list of x coordinates
xPointsList = range(0, xRange, xScale)
# Convert list to numpy array
xPoints = np.array(xPointsList)

# Create a list of y coordinates for each x coordinate
yPointsList = []
# f(x) = y^2
for elt in xPoints:
    yPointsList.append(2 ** elt)

# Converting list to numpy array
yPoints = np.array(yPointsList)

# Plot the graph
plt.plot(xPoints, yPoints)
# Display the graph
plt.show()