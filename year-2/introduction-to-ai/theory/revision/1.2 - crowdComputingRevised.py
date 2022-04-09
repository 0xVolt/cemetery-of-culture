import pandas as pd
import math
import statistics

trueCountOfCandy = 375

# Read the excel file
data = pd.read_excel(r'C:\Users\Volt\Code\AIML-Year-2\intro-AI\Lab\Experiment 1\crowd_computing.xlsx')

# Get the required data in the form of a list
# this can also be done: personsGuessList = data.iloc[:, 0]
personsGuessCol = data["Person's Guess"]
personsGuessList = list(personsGuessCol)

# Sort the list
personsGuessList.sort()

# Calculate and format the mean
guessMean = statistics.mean(personsGuessList)

# Calculate delta
guessMeanDelta = guessMean - trueCountOfCandy

# Calculate median
guessMedian = statistics.median(personsGuessList)

# Calculate mode
guessMode = statistics.mode(personsGuessList)

# Calculate trim as 10% of the total number of guesses
trimVal = math.floor(len(personsGuessCol) * 0.1)

# Print results
print(f'Actual number of Candy = {trueCountOfCandy}\n\nMean = {guessMean}\nMedian = {guessMedian}\nMode = {guessMode}\nTrim = {trimVal}')

# Triming the list using trimVal
trimList = personsGuessList[trimVal:len(personsGuessList) - trimVal]
trimMean = statistics.mean(trimList)
print("Trimmed Mean = {:2f}".format(trimMean))