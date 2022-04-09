""" for i in range(10):
    print("Hello, World") """

# range creates a LIST of values till n - 1
# range(5) -> [0, 1, 2, 3, 4]
# the loop makes i travel through every elt in the list
    # so i need not be intialized

# range(1, 5) -> [1, 2, 3, 4] 
# range(1, 5, 2) -> [1, 3, 4] i.e. updates numbers by adding 2

x = [1, 2, 3, "test"]

# print(x)
for i in x:
    print(i, end = " ")