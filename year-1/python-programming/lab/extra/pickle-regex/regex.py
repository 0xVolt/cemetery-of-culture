import re

# Write a Python program that matches a string that has an a followed by zero or more b's.
txt = "this is a tesabbbbbbbbbbbbbbbb abbb ab test"

x = re.search('ab*', txt)

if x:
    print('Matches: ')
    print(x.group())
else:
    print("No matches!")