n = int(input("N: "))

list1 = list()

for i in range(n):
    score = int(input("Enter score {}: ".format(i + 1)))
    list1.append(score)

mx = max(list1[0], list1[1])
secondmax = min(list1[0], list1[1])

for i in range(2, n):
    if list1[i] > mx:
        secondmax = mx
        mx = list1[i]
    elif list1[i] > secondmax and \
            mx != list1[i]:
        secondmax = list1[i]

print("Second highest number is: ", str(secondmax))