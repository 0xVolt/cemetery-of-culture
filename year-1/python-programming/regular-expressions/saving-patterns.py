import re

txt = 'python   programming   '

# One or more occurrences of whitespace at end
pattern = re.compile('\s+$')
txt = pattern.sub('', txt)

print(txt)
print(list(txt))