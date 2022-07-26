""" 
PROBLEM STATEMENT

 * There are 20 students having fields: SAP, Name, Semester, Subjects, Marks, Percentage
 * Out of these, select those students having percentage > 80 and store them in a new dataframe
 * However, only 5 students are allowed to be on the topperList
 * To make the list come to length 5, we apply flg. steps (in the form of conditions):
    i. Those students having number of subjects == 4 are to be dropped and the count of the len is to be decremented
    ii. The remaining spaces in the list needs to be filled by those students in the main data that have most percentage and number of subjects === 5
    iii. export the new topperList to a text file
 """

import pandas as pd
import random


# to generate list of 20 random numbers with conditions
marksList = [random.randint(165, 500) for i in range(20)]
percentageList = [(x / 500) * 100 for x in marksList]
sapList = [random.randint(500000000, 500099999) for i in range(20)]
sapList = map(str, sapList)

data = {
    'SAP': sapList,
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

# create initial dataframe
dataFrame = pd.DataFrame(data)
dataFrame = dataFrame.sort_values(by=['Percentage'], ascending=False)

# created topperList dataframe
topperList = dataFrame[dataFrame['Percentage'] > 80]

# drop all those students from the topperList whose Subs == 4
topperList = topperList.drop(topperList[topperList.Subjects == 4].index)

if len(topperList) < 5:
    # make a new dataframe containing the elts from (dataFrame - topperList)
    setDifference = dataFrame[~dataFrame.isin(topperList)].dropna()
    i = 0
    while (len(topperList) != 5): 
        nextStudentWithFiveSubs = setDifference[setDifference.Subjects == 5].iloc[i]
        topperList.loc[len(topperList)] = nextStudentWithFiveSubs
        i += 1

# print the final topperList
print(topperList)

# convert topperList to txt file
topperList.to_csv('topperList.txt', "\t", mode = 'w', index = None)
topperList.to_excel('topperList.xlsx', "\t")