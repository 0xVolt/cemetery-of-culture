# With exception handling

while True:
    # Try looks out for any error within code in the try block
    try:
        n1 = int(input("Enter numerator: "))
        n2 = int(input("Enter denominator: "))
        result = n1 / n2

    # If ValueError exception occurs
    except ValueError:
        print("Please enter two integers")

    except ZeroDivisionError:
        print("Denominator must be non-zero")

    # Else clause without corresponding if
    # If try block does not raise exception then execute else
    else:
        print(f'Result = {n1 : .3f} / {n2 : .3f} = {result : .3f}')
        break # Or while loop will keep going