# Using for

""" for i in range(2, 101, 2):
    print(i) """

# Using while

""" x = range(2, 102, 2)
i = 0
while i < len(x):
    print(x[i])
    i += 1 """

x = int(input("Enter a number: "))
if x % 2 == 0:
    print("Even!")
elif x == 0:
    print("Neither even nor odd!")
else:
    print("Odd!")

for i in range(10):
    print("Thanks Divy!")