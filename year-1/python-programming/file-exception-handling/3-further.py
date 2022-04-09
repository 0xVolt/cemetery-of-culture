# With exception handling

while True:
    # Try looks out for any error within code in the try block
    try:
        n1 = int(input("Enter numerator: "))
        n2 = int(input("Enter denominator: "))
        result = n1 / n2

    # Combine two or more exceptions in a clause
    except(ValueError, ZeroDivisionError):
        print("Please enter two integers, denominator cannot be 0")

    # Else clause without corresponding if
    # If try block does not raise exception then execute else
    else:
        print(f'Result = {n1 : .3f} / {n2 : .3f} = {result : .3f}')
        break # Or while loop will keep going

    # Finally has to come at the end or it will show an invalid syntax error
    finally:
        print("Finally always runs (even after break!)")