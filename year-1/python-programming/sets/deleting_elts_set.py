""" 
Using 
    discard() --> set remains unchanged if item doesnt exist
    remove() --> error if the item doesn't exist in the set

Thet both remove a particular elt from the set
Also, pop() removes the elt at the top of the set but since
it is unordered, the top element changes 
"""

testSet = {1, 2, 3, 4, 5}
print(testSet)

testSet.discard(1)
testSet.discard("John") # remains unchanged

print(testSet)

testSet.remove(2)
print(testSet)
testSet.remove(10)