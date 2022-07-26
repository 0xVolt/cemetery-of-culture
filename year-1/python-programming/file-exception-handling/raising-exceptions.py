def func1():
    raiseException()

def raiseException():
    raise Exception('This is a generic exception!') # Raising parent exception from which all others are derived, i.e. generic exception

# Function call
func1()

# Displays traceback and stack unwinding takes place