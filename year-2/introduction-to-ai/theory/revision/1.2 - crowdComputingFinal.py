import pandas as pd
import math
import statistics

def trimList(ls, updatedLen):
    trimmedList = ls[trimVal:updatedLen]

    return trimmedList

def calculateDelta(ls, count):
    delta = abs(count - statistics.mean(ls))

    return delta

trueCountOfCandy = 375
deltaCutoff = 5

data = pd.read_excel(r'C:\Users\Volt\Code\AIML-Year-2\intro-AI\Lab\Experiment 1\crowd_computing.xlsx')

guessCol = data["Person's Guess"]
guessList = list(guessCol)

deltaMean = calculateDelta(guessList, trueCountOfCandy)

trimVal = math.floor(len(guessList) * 0.1)

updatedLen = len(guessList)

if deltaMean > deltaCutoff:
    while deltaMean > deltaCutoff:
        updatedLen -= trimVal
        guessList = trimList(guessList, updatedLen)
        deltaMean = calculateDelta(guessList, trueCountOfCandy)

        print(len(guessList))