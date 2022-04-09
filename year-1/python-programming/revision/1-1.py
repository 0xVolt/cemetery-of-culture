count = 0
condition = True

while condition:
    n = int(input("Enter an integer: "))
    if n % 2 != 0 and n > 10 and n < 20:
        print("You won the game!")
        condition = False
    else:
        count += 1

    if count == 3:
        print("You lost the game!")
        condition = False