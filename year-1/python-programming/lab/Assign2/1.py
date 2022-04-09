# Code by Desh Iyer

import math


class Shape:

    def __init__(self, color='black', filled=False):
        self.color = color
        self.filled = filled

    def get_color(self):
        return self.color

    def set_color(self, color):
        self.color = color

    def get_filled(self):
        return self.filled

    def set_filled(self, filled):
        self.filled = filled


class Rectangle(Shape):

    def __init__(self, length, breadth):
        super().__init__()
        self.length = length
        self.breadth = breadth

    def get_length(self):
        return self.length

    def set_length(self, length):
        self.length = length

    def get_breadth(self):
        return self.breadth

    def set_breadth(self, breadth):
        self.breadth = breadth

    def get_area(self):
        return self.length * self.breadth

    def get_perimeter(self):
        return 2 * (self.length + self.breadth)


class Circle(Shape):
    def __init__(self, radius):
        super().__init__()
        self.radius = radius

    def get_radius(self):
        return self.radius

    def set_radius(self, radius):
        self.radius = radius

    def get_area(self):
        return math.pi * self.radius ** 2

    def get_perimeter(self):
        return 2 * math.pi * self.radius


r1 = Rectangle(10.5, 2.5)

print("Area of rectangle r1:", r1.get_area())
print("Perimeter of rectangle r1:", r1.get_perimeter())
print("Color of rectangle r1:", r1.get_color())
print("Is rectangle r1 filled ? ", r1.get_filled())
r1.set_filled(True)
print("Is rectangle r1 filled ? ", r1.get_filled())
r1.set_color("orange")
print("Color of rectangle r1:", r1.get_color())

c1 = Circle(12)
print("\nArea of circle c1:", format(c1.get_area(), "0.2f"))
print("Perimeter of circle c1:", format(c1.get_perimeter(), "0.2f"))
print("Color of circle c1:", c1.get_color())
print("Is circle c1 filled ? ", c1.get_filled())
c1.set_filled(True)
print("Is circle c1 filled ? ", c1.get_filled())
c1.set_color("blue")
print("Color of circle c1:", c1.get_color())
