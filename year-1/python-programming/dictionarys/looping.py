testDict = {
    "k1": "v1",
    "k2": "v2",
    "k3": "v3"
}

# Printing keys
print("Printing keys:")
for i in testDict: # or for i in testDict.keys()
    print(i)

# Printing values
print("Printing values:")
for i in testDict: # or for i in testDict.values()
    print(testDict[i])

# Printing items (both keys and values)
print("Printing items:")
for i in testDict.items():
    print(i)