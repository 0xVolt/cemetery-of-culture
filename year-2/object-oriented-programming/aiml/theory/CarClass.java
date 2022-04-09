// the class is a template/blueprint for an object
// each obj has a state and behaviour - fields and methods
// pc - fields: cores, RAM, storage - methods: powering on, playing music
// methods - perform actions on objects


public class CarClass {
    // adding fields

    // usually fields are private access modifier and methods are usually public

    // fields can be public but its best practice to keep them private
    // we use the concept of encapsulation when we use access specifiers
    // each field needs an access specifier and they cant be grouped like in C++
    private int horsePower;
    private int model;
    private String type;
    private String colour;
    // it is best practice to keep boolean vars names starting with 'is'
    private boolean isFirstHand;

    public int getHorsePower() {
        return this.horsePower;
    }

    public void setHorsePower(int horsePower) {
        this.horsePower = horsePower;
    }

    public int getModel() {
        return this.model;
    }

    public void setModel(int model) {
        this.model = model;
    }

    public String getColour() {
        return this.colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }

    public boolean isIsFirstHand() {
        return this.isFirstHand;
    }

    public void setIsFirstHand(boolean isFirstHand) {
        this.isFirstHand = isFirstHand;
    }

    public int numberWheels; 

    // Start of main() method
    public static void main(String[] args) {
        // declaring an instance of CarClass
        CarClass car = new CarClass();

        // our fields are private so they cant be directly accessed

        // the only field that can be accessed is the public field numberWheels
        car.numberWheels = 4;
        System.out.println(car.numberWheels);

        // now setting type of type var
        car.setType("Mazda");
        String returnedType = car.getType();
        System.out.println("Type of Car: " + returnedType);
    }

    // we need a method to set value to a private field - setter - and a method to get the field - the getter

    // we will first set the value of type

    // setter function for type
    public void setType(String type) {
        // this. is similar to 'self' in py
        this.type = type;
    }

    // getter function for type
    public String getType() {
        return this.type;
    }
}

// if you dont add 'this.' when the variable and field have same names:
// String values will be assigned null
// int - 0
// double - 0.0