// Code by Desh Iyer

// Q2	
// Write a JAVA program which contains a function cube() such that cube(3) returns 27, cube(0.2) returns 0.008.

import java.util.*;

public class Cube {
    public static float cube(float n) {
        return n * n * n;
    } 

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        float n;
        System.out.println("Input: ");
        n = input.nextFloat();
        float cubeOfN = cube(n);

        System.out.printf("The cube of %.3f = %.3f", n, cubeOfN);

        input.close();
    }
}
