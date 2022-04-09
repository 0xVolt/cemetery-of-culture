// Code by Desh Iyer
// Q1
// Java program to print the kth digit from the last in a given number
// eg: i/p 23617, k = 4 | o/p 3

import java.util.Scanner;

public class kFromLast {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Input (n & k): ");
        
        int number = input.nextInt();
        int k = input.nextInt();

        for (int i = 0; i < k - 1; i++) {
            number /= 10;
        }

        System.out.printf("\n%dth digit from the last is %d", k, number % 10);

        input.close();
    }
}
