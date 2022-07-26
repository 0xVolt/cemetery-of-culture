dict = {}

n = int(input("How many students records: "))

for i in range(n):
    key = input("Name: ")

    marks = []
    print("Enter marks in 3 subjects:")
    for j in range(3):
        marks.append(float(input()))
    
    dict[key] = marks

for key, values in dict.items():
    sum = 0
    for j in range(3):
        sum += values[j]

    print("Average marks of student {} is {}".format(key, sum / 3))