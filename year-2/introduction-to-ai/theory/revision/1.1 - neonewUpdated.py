def newneo_game(lower, upper):
    if lower < upper:
        for i in range(lower, upper):
            addstring = '= '
            if i % 3 == 0:
                addstring += "NEO"
                if i % 5 == 0:
                    addstring += "NEW"

            elif i % 5 == 0:
                addstring == "NEO"

            print(i, addstring)
    else:
        print("Lower range entered is greater than upper range")


lower = int(input("Enter a number as lower bound: "))
upper = int(input("Enter a number as upper bound (upper > lower): "))

newneo_game(lower, upper)