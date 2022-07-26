a = []
result = []

n = int(input("How many elements? "))

print("Enter list elements:")
for i in range(n):
    a.append(int(input("Enter element: ")))

print("The original list is : " + str(a))

for i in a:
    if i not in result:
        result.append(i)

print("The resultant list : " + str(result)) 