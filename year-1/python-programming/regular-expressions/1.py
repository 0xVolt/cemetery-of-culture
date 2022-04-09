import re

txt = "This is a test to see how this module works"

# r -> raw string
x = re.findall(r's$', txt)

if x:
    print(x.group())
    print(f"Matches = {len(x)}")
else:
    print("No match")