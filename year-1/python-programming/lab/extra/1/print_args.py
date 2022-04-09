n = int(input("Enter an integer: "))

if n < 0:
    n *= -1

for i in range(1, n + 1):
    print(i, end = "")