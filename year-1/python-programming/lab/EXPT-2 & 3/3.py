stamps_list = []

n = int(input("Enter the number of countries' stamps: "))

for i in range(n):
    country = input("Enter the country: ")
    stamps_list.append(country)

stamps_set = set(stamps_list)

count = 0
for country in stamps_set:
    count += 1

print("The unique count of countries in the stamp collection is {}.".format(count))    