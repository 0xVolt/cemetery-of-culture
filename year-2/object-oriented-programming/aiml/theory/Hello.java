// You cant write programs in java without creating classes since its 
// object oriented

// Classes contain fields and methods
// Fields - holds data for objects and class
// Methods - operates on fields

// Multiple classes can be created in a source file but only one of them can be public

// Every java since 8, needs a main() function to execute a program
// Since the main() function is to be defined in the class, its gonna be called the main()
// method

// Creating the public class Hello
public class Hello {
    // static - we dont need to create an object of class Hello to execute main()
    public static void main(String[] args) {
        // System.out.println("Hello, World!");

        int x = 10;
        float y = 3.14f; 
        System.out.printf("%d %f", x, y);
    }
}