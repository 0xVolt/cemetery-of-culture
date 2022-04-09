// Code by Desh Iyer

// Q1
// Write a JAVA program which contains a function square() such that square(3) returns 9, square(0.2) returns 0.04

import java.util.*;

public class Square {
    public static float square(float x) {
        return x * x;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        float x;
        System.out.println("Input: ");
        x = input.nextFloat();

        float sq = square(x);

        System.out.printf("The sqaure of %.2f = %.2f", x, sq);

        input.close();
    }
}