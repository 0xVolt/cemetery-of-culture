# Code by Desh Iyer

# Experiment 1
# Write a program to solve different set operations using python

print('\nMy Name is "Desh Iyer"\nMy SAP Id is "500081889"\n')

listA = []
listB = [] 

n = int(input("Number of set elements: "))

print("Enter set A:")
for i in range(n):
    listA.append(int(input()))

print("Enter set B:")
for i in range(n):
    listB.append(int(input()))

A = set(listA)
B = set(listB)

print("Union of two sets:", A | B)

print("Intersection of two sets:", A & B)

print("Difference of two sets:", A - B)

print("Symmetric difference of two sets:", A ^ B)
