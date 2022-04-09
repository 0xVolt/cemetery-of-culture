import pandas as pd

guessList = [
    92,
    120,
    123,
    123,
    130,
    112,
    111,
    189,
    190,
    193,
    200,
    201,
    201,
    210,
    214,
    218,
    223,
    223,
    232,
    234,
    234,
    238,
    243,
    247,
    250,
    261,
    273,
    280,
    289,
    290,
    300,
    311,
    321,
    321,
    321,
    334,
    340,
    340,
    342,
    345,
    345,
    356,
    376,
    380,
    390,
    392,
    400,
    450,
    455,
    456,
    456,
    459,
    480,
    497,
    500,
    500,
    540,
    542,
    543,
    546,
    560,
    564,
    567,
    567,
    567,
    667,
    670,
    670,
    890,
    900,
    1000,
    1200,
    1300,
    928,
    1000
]

data = {
    'Guesses': guessList
}

df = pd.DataFrame(data)
df = df.sort_values(by=['Guesses'], ascending=False)

optimalGuess = 375
meanDelta = abs(int(df.mean() - optimalGuess))

if (meanDelta < 5):
    pass
else:
    while (newMeanDelta > 5):
        downSizeAmt = int(len(guessList) * 0.1)
        downSizedDf = df.iloc[downSizeAmt:(len(df) - downSizeAmt)]
        newMeanDelta = abs(int(downSizedDf.mean() - optimalGuess))

     