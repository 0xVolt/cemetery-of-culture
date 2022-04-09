a1 = []
a2 = []

n = int(input("Enter the number of elements in each list: "))

print("Enter list a1")
for i in range(n):
    a1.append(int(input("Enter element: ")))

print("Enter list a2")
for i in range(n):
    a2.append(int(input("Enter element: ")))

print("Searching for common element between lists a1 and a2")
for elt1 in a1:
    for elt2 in a2:
        if elt1 == elt2:
            print("The common element between the lists is", elt1)