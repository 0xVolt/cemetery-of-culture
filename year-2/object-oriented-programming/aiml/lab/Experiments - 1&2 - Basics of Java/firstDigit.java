// Code by Desh Iyer
// Q2
// Java program to print the first digit in a given number
// eg: input 23516, output 2

import java.util.Scanner;

public class firstDigit {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input: ");

        int number = input.nextInt();
        int originalNumber = number;

        while (number > 10) {
            number /= 10;
        }

        System.out.printf("The first digit in %d is %d", originalNumber, number);

        input.close();
    }
}
