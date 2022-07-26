# Code by Desh Iyer
# Program to demonstrate the NEONEW game:
#  * if a number is a multiple of 3 : print NEO
#  * elif a number is a multiple of 5 : print NEW
#  * elif a number is a multiple of 3 and 5 : print NEONEW
#  * else print the number


lower = int(input("Enter a number as lower bound: "))
upper = int(input("Enter a number as upper bound (upper > lower): "))

if lower < 0:
    lower *= -1
    print("converted lower bound to positive integer")

if upper < 0:
    upper *= -1
    print("converted upper bound to positive integer")

if lower > upper:
    print("lower bound is to be lesser than upper bound")
    exit()

ls = range(lower, upper + 1)

for i in ls:
    if i % 3 == 0 and i % 5 == 0:
        print(i, " = NEONEW")
    elif i % 3 == 0:
        print(i, " = NEO")
    elif i % 5 == 0:
        print(i, " = NEW")
    else:
        print(i)