// Code by Desh Iyer

// Q4
// Write a JAVA program which contains a function fun() such that fun(x) returns x and fun(x,y) returns x + y and fun(x,y,z) returns x*y*z. (where x, y and z are integers).

import java.util.*;

public class Fun_3 {
    public static int fun(int x) {
        System.out.println("Inside fun(x), printing x");
        return x;
    }
    
    public static int fun(int x, int y) {
        System.out.println("Inside fun(x, y), printing x + y");
        return x + y;
    } 
    
    public static int fun(int x, int y, int z) {
        System.out.println("Inside fun(x, y, z), printing x * y * z");
        return x * y * z;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int x, y, z;
        System.out.println("Enter integers x, y & z: ");

        x = input.nextInt();
        y = input.nextInt();
        z = input.nextInt();

        System.out.println();
        System.out.println(fun(x));
        System.out.println();
        System.out.println(fun(x, y));
        System.out.println();
        System.out.println(fun(x, y, z));
        System.out.println();
        
        input.close();
    }
}
