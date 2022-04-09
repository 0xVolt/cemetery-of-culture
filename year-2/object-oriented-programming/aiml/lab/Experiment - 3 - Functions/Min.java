// Code by Desh Iyer

// Q5
// Write a set of overloaded functions min() that returns the smaller of two numbers passed to them as arguments. Make versions for int and float.

import java.util.*;

public class Min {
    // Function 1
    public static int min(int x, int y) {
        System.out.println("Returning min of int type");
        return x < y? x : y;
    }
    
    // Function 2
    public static float min(float x, float y) {
        System.out.println("Returning min of float type");
        return x < y? x : y;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int x, y;
        float a, b;

        System.out.println("Enter two int numbers: ");
        x = input.nextInt();
        y = input.nextInt();

        // Calling function 1 
        System.out.println(min(x, y));

        System.out.println("Enter two float numbers: ");
        a = input.nextFloat();
        b = input.nextFloat();

        // Calling function 2
        System.out.println(min(a, b));

        input.close();
    }

}
