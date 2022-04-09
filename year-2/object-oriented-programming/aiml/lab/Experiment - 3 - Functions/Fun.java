// Code by Desh Iyer

// Q3
// Write a JAVA program which contains a function fun() such that fun(x) returns x2 and fun(x,y) returns x2 + y2. (where x and y are integers).

import java.util.*;

public class Fun {
    // Function 1
    public static double fun(int x) {
        System.out.println("Inside fun(x)");
        return Math.pow(x, 2);
    }
    
    // Function 2
    public static double fun(int x, int y) {
        System.out.println("Inside fun(x, y)");
        return (Math.pow(x, 2) + Math.pow(y, 2));
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input two integers (x & y) separated by a space: ");
        int x, y;
        x = input.nextInt();
        y = input.nextInt();

        System.out.printf("\nx: %d | y: %d\n\n", x, y);

        System.out.println(fun(x));
        System.out.println();
        System.out.println(fun(x, y));
        System.out.println();

        input.close();
    }
}
