# For documentation on the ttg package, visit https://pypi.org/project/truth-table-generator/

import ttg
import pandas as pd

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

def checkBoolean(p):
    if p == 1:
        result = True
    elif p == 0:
        result = False
    else:
        print("Invalid boolean value encountered!")
        exit()

    return result


andTable = ttg.Truths(['P', 'Q'], ['P and Q'], ints=False)
orTable = ttg.Truths(['P', 'Q'], ['P or Q'], ints=False)

print("AND Gate:")
print(andTable)

print("\nOR Gate:")
print(orTable)

# andDF = andTable.as_pandas()
# orDF = orTable.as_pandas()

# p = int(input("Enter a boolean for p (1 / 0): "))
# q = int(input("Enter a boolean for q (1 / 0): "))

# p = checkBoolean(p)
# q = checkBoolean(q)

# df['color'] = np.where(((df.A < borderE) & ((df.B - df.C) < ex)), 'r', 'b')