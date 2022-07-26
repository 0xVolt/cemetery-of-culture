# We can use the flg methods
    # add() -> add individual elements
    # update() -> add multiple elements at a time

testSet = {
    1,
    2,
    3,
    4,
    5,
    6
}

print(testSet)
testSet.add("Mozambique here!")
print(testSet)

testSet.update(
    ["Come and get your birthday present!", 7, 8, 9]
)
print(testSet)

""" for i in testSet:
    print(type(i)) """