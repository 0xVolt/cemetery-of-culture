// Code by Desh Iyer
// Q3
// Java program to print the second digit in a given number
// eg: input 23516, output 3

import java.util.Scanner;

public class secondDigit {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input: ");

        int number = input.nextInt();
        int originalNumber = number;

        while (number > 100) {
            number /= 10;
        }

        System.out.printf("The second digit in %d is %d", originalNumber, number % 10);

        input.close();
    }
}
