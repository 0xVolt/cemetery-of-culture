# initialization
# condition (loop)
    # updation (in loop)

""" i = 0
while i <= 10:
    print(i, end = " ")
    i += 1 # ++ and -- don't exist in python """

i = 1
while i <= 10:
    print("Hello, World", i)
    i += 1

# Traversing a list using while

# while loop takes a conditional statement
# to traverse, we need the length of the list

x = [1, 2, 3, "test"]

i = 0
l = len(x)
while i < l:
    print(x[i])
    i += 1