// method overloading only works when we change the return type AND variable types
// not just the return type

public class MethodsOverloading {
    public static void main(String[] args) {
        // calling 1
        System.out.println("Function 1: " + calcSum(10, 5));
        // calling 2
        System.out.println("Function 2: " + calcSum(10, 5, 6));
        // calling 3
        System.out.println("Function 3: " + calcSum(10.0, 5.5));
    }

    // Function 1
    public static int calcSum(int first, int second) {
        return first + second;
    }
    
    // Function 2
    public static int calcSum(int first, int second, int third) {
        return first + second + third;
    }

    // Function 3
    public static double calcSum(double first, double second) {
        return first + second;
    }
}
