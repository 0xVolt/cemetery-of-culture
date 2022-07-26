class Computer:

    counter = 0

    def __init__(self, Company_name, RAM, HDD, Price):
        self.Company_name = Company_name
        self.RAM = RAM
        self.HDD = HDD
        self.Price = Price

        Computer.counter += 1

    def increasePrice(self):
        self.Price = self.Price + (0.02 * self.Price)

    def displayCount():
        print(Computer.counter)

o1 = Computer('A', 2, 10, 1000)

Computer.displayCount()

o1.increasePrice()
print(o1.Price)