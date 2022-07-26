import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Import data generated as a .csv file into pandas dataframe
data = pd.read_csv(
    r'C:\Users\deshi\Code\cemetery-of-culture\year-2\data-communication\experiment-6\final-presentation-resources\out.csv'
)

# Create a dataframe with the imported data
df = pd.DataFrame(data, columns= ['Frame (#)','Attempts (k)', 'Total Time Taken (seconds)', 'Backoff Time (seconds)'])

# Set the first column to be the index
df.set_index('Frame (#)')

# Printing data
print("Printing imported data:\n")
print(df)

# Describing the dataframe that imports our csv data
print("\nPrinting the summary statistics of the dataframe:\n")
print(df.describe())

# Plot graph between Attempts and Frames
print("\nAttempts vs. Frames")
frames = df['Frame (#)']
attempts = df['Attempts (k)']

plt.title('Attempts (k) vs. Frame')
plt.xlabel('Frame')
plt.ylabel('Attempts (k)')

plt.plot(frames, attempts)
plt.show()

# Printing summary statistics
print("Mean number of attempts: ", np.mean(attempts))

# Plotting the distribution of number of attempts
print("\nDistribution of Attempts")
plt.title("Distribution of Attempts (k)")

plt.xlabel("k")
plt.ylabel("Frequency of occurrence")

plt.hist(attempts, edgecolor="white")
plt.show()

# Plot graph between Total Time Taken and Frames
print("\nTotal Time vs. Frames")
totalTime = df['Total Time Taken (seconds)']

plt.title("Total Time Taken (s) vs. Frames")
plt.xlabel("Frames")
plt.ylabel("Total Time Taken (s)")

plt.plot(frames, totalTime, color='tab:orange')
plt.show()

# Plot graph for the Distribution of Total Time Taken for Frame Transmission
print("\nDistribution of Total Time")
plt.title("Distribution of Total Time Taken (s)")

plt.xlabel("Time (s)")
plt.ylabel("Frequency of occurrence")

plt.hist(totalTime, edgecolor="white", color ='tab:orange')
plt.show()

print("Mean total time: ", np.mean(totalTime), "s")

# Plot graph between Attempts and Total Time Taken
print("\nAttempts vs. Total Time")
plt.title("Attempts vs. Total Time Taken")

plt.xlabel("Total Time Taken")
plt.ylabel("Attempts (k)")

plt.plot(totalTime, attempts, color='tab:green')
plt.show()