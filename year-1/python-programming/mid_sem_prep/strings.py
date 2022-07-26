# String slicing
test = "Test String"

print(test[0:3])
print(test[0:4]) 

# lower limit is inclusive
# but upper limit isn't. example below

x = len(test)
print(x)
print(test[0 : x + 1])

# print(test[78]) --> ERROR, but
print(test[0:78]) # prints the string

# Also
print(test[0:]) # prints the entire string
# and
print(test[:5]) # takes it as 0:5 by default
# as well as
print(test[:]) # prints everything

# To skip a character:
print(test[0 : len(test) + 1 : 2])
print(test[0:5:]) # by default takes as 1
# so,
print(test[::]) # prints the entire string

# NOTE: to reverse a string in the easiest way:
print(test[::-1])

# Methods:
print(test.endswith("String"))
print(test.count("t")) # case sensitive
print(test.capitalize()) # only first char
print(test.find(" ")) # case sensitive
print(test.lower())
print(test.upper())
print(test.replace(" ", "lmao"))