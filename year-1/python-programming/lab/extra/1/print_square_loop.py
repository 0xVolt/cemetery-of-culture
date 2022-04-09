n = int(input("Enter an integer: "))

if n < 0:
    n *= -1

for i in range(n):
    print(i ** 2)