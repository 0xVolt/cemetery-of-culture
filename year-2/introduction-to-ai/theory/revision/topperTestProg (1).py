import pandas as pd
import random

marksList = [random.randint(20, 100) for i in range(20)]
percentageList = [(x / 100) * 100 for x in marksList]

data = {
    'SAP': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20],
    'Name': [
        'Ona Yamanaka',
        'Mellissa Begay',
        'Leonard Liedtke',
        'Francisca Tully', 
        'Dovie Watt',
        'Felipa Creasman',  
        'Olin Tongue',  
        'Lincoln Henriquez',  
        'Virgie Litteral',  
        'Landon Scurry',  
        'Tona Hadnott',  
        'Lily Garrigan',  
        'Kit Steidl',  
        'Angla Hurd',  
        'Jacki Grimes', 
        'Karisa Fortman',  
        'Wes Heitz',  
        'Efrain Lacross',  
        'Isabell Parrett',  
        'Jared Kavanagh'  
    ],
    'Semester': [random.randint(3, 5) for i in range(20)],
    'Subjects': [random.randint(4, 5) for i in range(20)],
    'Marks': marksList,
    'Percentage': percentageList 
}

df = pd.DataFrame(data)

sortedData = df.sort_values(by=['Percentage'], ascending=False)
topperList = sortedData[sortedData['Percentage'] > 80]

# Takes the 'set difference' between topperList and sortedData
# Sort of what remains in sortedData after topperList is subtracted
setDifference = sortedData[~sortedData.isin(topperList)].dropna()

if len(topperList) == 5:
    topperList.to_csv('topperList.txt', 'w')
elif len(topperList) < 5:
    while (len(topperList) != 5): 
        nextStudentWithFiveSubs = setDifference[setDifference.Subjects == 5].iloc[0]
        topperList.loc[len(topperList)] = nextStudentWithFiveSubs
else:
    while (len(topperList) != 5):
        nextStudentwithFourSubs = topperList[topperList.Subjects == 4].iloc[0]
        topperList = topperList.drop(
            topperList[topperList.Name == nextStudentwithFourSubs.Name].index
        )

topperList.to_excel('topperList.xlsx')