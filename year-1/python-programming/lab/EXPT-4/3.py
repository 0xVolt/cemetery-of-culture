string = input("Enter string: ")

string = string.upper()

print(string)

string_list = list(string)
string_set = set(string_list)

for i in string_set:
    count = 0

    for j in string_list:
        if i == j:
            count += 1

    print("{} {}".format(
        count, i
    ))