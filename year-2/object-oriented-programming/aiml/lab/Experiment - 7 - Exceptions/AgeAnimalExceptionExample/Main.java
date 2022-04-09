// Example to demonstrate proper exception handling in java

// Animal class and Custom exception class are defined in separate files

// We then use the ctor of the Animal class to throw new exception

// Then when instantiating the object in the main function, we use try catch

public class Main {
    public static void main(String[] args) {
        // Notice that we first declare the object outside the try catch block
        // This is because, the try catch block contains code which is protected and hence has its own scope

        // We declare the object
        Animal Dog = null;

        try {
            // We instantiate the object
            Dog = new Animal("Einstein", -10);
        } catch(AgeAnimalException E) {
            // getMessage() gets the string passed to the parameter in the ctor
            System.out.println(E.getMessage());
        }
    }
}
