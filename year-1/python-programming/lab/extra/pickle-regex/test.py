import re

txt = "THis is a really gooooooooooood test"

x = re.search('o.*', txt)

if x:
    print("Matches: ")
    print(x.group())
else:
    print("No matches!")