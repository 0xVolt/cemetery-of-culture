testDict = {
    "key1": "val1",
    "key2": "val2",
    "key3": ["val3", "val4", "val5"]
}
print(testDict)

testDict.pop("key1")
print(testDict)

# Use the pop() method to remove keys from the dictionary
testDict.pop("key3")
# or
# del testDict["key3"] to remove the item
print(testDict)

# Use the clear() method to empty the dictionary
testDict.clear()
print(testDict)

del testDict
# print(testDict) will return error