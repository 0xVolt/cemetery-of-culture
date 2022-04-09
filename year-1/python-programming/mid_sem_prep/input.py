# input() always returns a string type i.e. <'str'>

""" a = int(input("Enter number 1: "))
b = int(input("Enter number 2: "))

print(a + b) """

# To pretend to enter a character
""" ch = input("Enter a character: ")
print(ch[0]) """

# OR

""" ch = input("Enter a character: ") [0]
print(ch) """

# Using the evaluate function to evaulate the expression entered
# in the input() fn
""" result = eval(input("Enter an expression: "))
print(result) """

# Using 'argv' as a command line argument

"""Example:
C:\Users\Volt\Desktop>python testCode.py 5 10
                                |        |  |
                        indices 0        1  2
Where 1 and 2 are command line args

x = argv[1]
y = argv[2]
print(x + y)"""

# But argv belongs under a module called 'sys' so we need to import sys
""" import sys

x = int(sys.argv[1])
y = int(sys.argv[2])
print(x + y) """
# NOTE: works in cmd but not in vs terminal