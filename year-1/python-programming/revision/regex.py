""" 
- We can use RegEx to extract date/time from a log file.
Helps us solve a lot of 'word' problems

- You can use regex to verify email addresses since all legit emails have certain patterns 

- You can verify phone numbers with regional extentions too

- From a database, we can modify large amount of data in a few steps by looking for patterns

What are regex?

- They are special strings that descibe a search pattern used for identifying strings for operations

- Important to note that regex and strings have their own cursors
 """

import re           # importing the re lib to use regex commands

# find a word in a string -> re.search() returns the first match

""" 
pattern = re.search('test', 'This is a test') # ---> returns the first match 

if pattern:
    print('word {} was found!'.format(pattern))
else:
    print('word {} was NOT found!'.format(pattern))
"""

# find all instances of a word -> re.findall() returns all matches

""" 
pattern = re.findall('inform', 'we need to inform them of the latest information') # ---> returns a list of all matches

for i in pattern:
    print(i)
"""

# Matching patterns

""" 
txt = 'Sat, sat, mat, pat, cat'
pattern = re.findall('[smpc]at', txt) # specifically match for words starting with s, m, p, c

for i in pattern:
    print(i) # -> will not print Sat since S is not included
"""

# replace a string


txt = 'hat, rat, mat, sat'
pattern = re.findall([])