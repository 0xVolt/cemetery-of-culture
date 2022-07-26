# Code by Desh Iyer

class Vehicle:                      # Parent Class
    def __init__(self):
        self.colour = ''
        self.horsePower = 0
        self.weight = 0
        self.regNum = ''

    def inputDetails(self):
        self.colour = input('Enter the vehicle colour: ')
        self.horsePower = int(input('How much horsepower: '))
        self.weight = float(input('How heavy: '))
        self.regNum = input('Enter registration number of the vehicle: ')

    def printDetails(self):
        print(
            '\n\nPrinting vehicle details...\n\nColour: {}\nHorsepower: {}\nWeight: {}\nRegistered: {}'.format(
                self.colour, self.horsePower, self.weight, self.regNum)
        )


class Car(Vehicle):                 # Child Class
    def __init__(self):             # Overwritten constructor
        self.horsePower = 250
        self.weight = 500


class Truck(Vehicle):               # Child Class
    def __init__(self):             # Overwritten constructor
        self.horsePower = 500
        self.weight = 1500


c = Car()
c.inputDetails()
c.printDetails()

t = Truck()
t.inputDetails()
t.printDetails()
