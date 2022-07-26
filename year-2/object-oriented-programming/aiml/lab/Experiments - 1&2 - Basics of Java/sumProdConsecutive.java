// Code by Desh Iyer
// Q5
// Java program to sum the products of the consecutive digits in a number
// eg: when the input is 23145 the output is 2x3 + 3x1 + 1x4 + 4x5 = 33

import java.util.Scanner;

public class sumProdConsecutive {
    public static void main(String[] args) { 
        Scanner ip = new Scanner(System.in);

        System.out.println("Enter number: ");

        int n = ip.nextInt();
        int originalNum = n;

        int sum = 0;

        while (n > 0) {
            int firstDigit = n % 10;
            int secondDigit = (n % 100) / 10;

            sum += firstDigit * secondDigit;
            
            n /= 10;
        }

        System.out.printf("The sum of product of consecutive digits in %d = %d", originalNum, sum);

        ip.close();
    }
}
