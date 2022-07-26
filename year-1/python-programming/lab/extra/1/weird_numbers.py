n = int(input("Enter an integer: "))

if n < 0:
    print("Testing cases of |", n, "|")
    n *= -1

if not n % 2 == 0:
    print("Weird")
else:
    if n >= 2 and n <= 5:
        print("Not Weird")
    if n >= 6 and n <= 20:
        print("Weird")
    elif n > 20:
        print("Not Weird")
