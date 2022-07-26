class Outer:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def print_details(self):
        print('x = {} | y = {}'.format(self.x, self.y))

class Inner(Outer):
    def __init__(self, x, y, a, b):
        super().__init__(x, y)
        self.a = a
        self.b = b

    def print_details(self):
        super().print_details()
        print(f'a = {self.a} | b = {self.b}')

o = Outer(1, 1)
i = Inner(5, 5, 2, 2)

print('o: ')
o.print_details()
print("i: ")
i.print_details()