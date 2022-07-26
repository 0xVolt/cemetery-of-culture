a = []

n = int(input("Enter the number of elements: "))

print("Enter list: ")
for i in range(n):
    a.append(int(input("Enter element: ")))

sum = 0
for elt in a:
    sum += elt

print("Sum of elements in the list is =", sum)