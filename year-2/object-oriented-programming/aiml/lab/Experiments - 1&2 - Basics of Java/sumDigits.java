// Code by Desh Iyer
// Q4
// Java program to sum the digits of a given number
// eg: Input = 22222, Sum = 10

import java.util.Scanner;

public class sumDigits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Input: ");
        int number = input.nextInt();

        int sumOfDigits = 0, originalNumber = number;

        while (number > 0) {
            int digit = number % 10;
            sumOfDigits += digit;
            number /= 10;
        }

        System.out.printf("Input = %d\nSum of its digits = %d", originalNumber, sumOfDigits);

        input.close();
    }
}
