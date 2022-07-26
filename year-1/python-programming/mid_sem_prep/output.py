# Can use '%' or '{}'
    # %d -> int
    # %s -> string
    # %f / %g -> float
        # %g only prints the number of decimal places in the number and no extra ones

name = input("Name: ")
age = int(input("Age: "))
sal = float(input("Salary: "))

# Approach 1
""" print(name, age, sal) """

# Approach 2
""" print("Name is:", name) # ',' is a separator
print("Age is:", age)
print("Sal is:", sal) """

# Approach 3: Using % operator --> data-type dependent
""" print("Name is: %s\nAge is: %d\nSal is: %g" %(name, age, sal)) """

# Approach 4: Using {} --> data-type independent
""" print("Name: {}\nAge: {}\nSal: {}".format(name, age, sal))
# Same o/p as above
print("Name: {0}\nAge: {1}\nSal: {2}".format(name, age, sal))

# Can mix up the order easily using {}
print("Name: {2}\nAge: {0}\nSal: {1}".format(name, age, sal)) """