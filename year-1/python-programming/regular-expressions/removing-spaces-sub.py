import re

# Adding extra spaces on purpose
txt = "    This is a   test string    "

# Unable to see the whitespaces at the end
print(txt)

print(list(txt))

# Subs more than one consecutive occ of space with a single space
result_string = re.sub(r'\s+', ' ', txt)

print(result_string)
print(list(result_string))

# To remove the space at start
result_string = re.sub(r'^\s', '', result_string)
# To remove the space at end
result_string = re.sub(r'\s$', '', result_string)

print(result_string)
print(list(result_string))