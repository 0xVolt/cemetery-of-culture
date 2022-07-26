import re

txt = "This is a test string!"

res = re.split('\s', txt)
print(res)

res = re.split('\s', txt, 2)
print(res)