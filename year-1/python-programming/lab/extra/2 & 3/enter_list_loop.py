ls = []

n = int(input("Enter the number of elements in the list: "))

print("Enter elements of the list:")
for i in range(n):
    ls.append(input("Enter element: "))

print("\nDisplaying list:")
# print(ls)
for i in range(n):
    print(ls[i], end = " ")