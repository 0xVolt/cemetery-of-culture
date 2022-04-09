class Shape:                                        # Parent Class
    def __init__(self, col, fill):
        self.colour = col
        self.filled = fill

    def getShape(self):
        print("Printing Shape details:\n")
        print("Colour: ", self.colour, "\nFilled: ", self.filled)

    def setShape(self, col, fill): 
        self.colour = col
        self.filled = fill

class Rectangle(Shape):                             # Child Class
    def __init__(self, col, fill, len, bre):
        super().__init__(col, fill)

        self.len = len
        self.bre = bre
        self.area = self.len * self.bre
        self.per = 2 * (self.len + self.bre)

    def getShape(self):
        super().getShape()
        print("Length: ", self.len, "\nBreadth: ", self.bre, "\nArea: ", self.area, "\nPerimeter: ", self.per)

class Circle(Shape):
    def __init__(self, col, fill, rad):
        super().__init__(col, fill)
        self.radius = rad
        self.area = 3.1415 * (rad ** 2)
        self.per = 2 * 3.1415 * rad

    def getShape(self):
        super().getShape()
        print('Radius: ', self.radius, '\nArea: ', self.area, '\nPerimeter: ', self.per)

# Declare an object of child class Rectangle
A = Rectangle('Blue', True, 10, 20)

A.setShape('Red', False)
print('\nShape A')
A.getShape()

# Declare an object of child class Cicle
B = Circle('Green', True, 7)

B.setShape('Purple', False)
print('\nShape B')
B.getShape()