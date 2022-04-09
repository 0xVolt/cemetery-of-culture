# A dictionary is defined with = and curly braces
# Every dictionary has 'keys' with 'values' which are defined as keys:values which are ',' separated
# Each pair of key and value is called an item

# Printing dictionaries
    # You can print:
        # Entire dict
        # List of keys
        # Values associated with each key

# Define testDict
testDict = {
    "brand": "Ford",
    "year": 1969,
    # values can also be of list type
    "models": ["mod1", "mod2", "mod3"]
}

# Printing entire dict
print(testDict)
# Printing length i.e. the number of keys
print(len(testDict))
# Printing the type of dict: <class 'dict'>
print(type(testDict))

# Ways to access the values in the dictionary
x = testDict["brand"]
# or
y = testDict.get("models")
print(x, y)

# function to obtain list of keys in the dictionary
z = testDict.keys()
print(z)