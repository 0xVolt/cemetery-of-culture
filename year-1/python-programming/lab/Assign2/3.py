# Code by Desh Iyer

# base class 1
class GroundVehicle():
    def drive(self):
        print("Drive me on the road!")

# base class 2
class FlyingVehicle():
    def fly(self):
         print("Fly me to the sky!")

# subclass
class FlyingCar(GroundVehicle, FlyingVehicle):
    pass

# create an object of a subclass
fc = FlyingCar()

fc.drive()
# Prints Drive me on the road!
fc.fly()
# Prints Fly me to the sky!
