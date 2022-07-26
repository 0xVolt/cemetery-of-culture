import re

txt = input("Enter a string: ")

x = re.search('', txt)

if x:
    print("Matches: ")
    print(x.group())
else:
    print("No matches!")