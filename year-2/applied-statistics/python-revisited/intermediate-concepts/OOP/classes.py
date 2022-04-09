class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def celebrate_birthday(self):
        self.age += 1

    def display_details(self):
        print(f'Name: {self.name}\nAge: {self.age}\n')

person1 = Person('A', 20)
person2 = Person('B', 22)

person1.display_details()
person2.celebrate_birthday()
person2.display_details()

del person1, person2
