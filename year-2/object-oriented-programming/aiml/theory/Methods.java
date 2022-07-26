// main() is an example of a method
// its main purpose is to perform actions
// they are also called functions
// the help to reuse code since we can call the same method multiple types

// every method needs a return type
// static methods dont return anything, so they are declared as void

// methods can only be declared inside a class

public class Methods {
    public static void main(String[] args) {
        System.out.println("Inside the main() method");

        // function call
        printHello();

        int sum = 0;
        sum = calcSum(10, 5);
        // function call
        System.out.print(sum);
    }

    // we want this method to execute regardless of object creation - static method
    public static void printHello() {
        System.out.println("Inside printHello. Hello, World!");
    }

    // declaring a method with an int return type
    public static int calcSum(int first, int second) {
        System.out.println("Inside calcSum");
        // return the sum of the variables passed
        return first + second;
    }
}
