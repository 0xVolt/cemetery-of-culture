Days = set(["Monday", "Tuesday", "Wednesday", "Thursday"])

for i in Days:
    print(i)

# Sets cannot have mutable datatypes as elements: test = {1, 2, ["testing", 3]} is an incorrect statement
# Whereas the flg. is possible
test = {1, 2, "Vader", 3} # The set is printed in any order
for i in test:
    print(i)