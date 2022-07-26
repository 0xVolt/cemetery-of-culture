// Code by Desh Iyer
// Q6
// Java program which outputs the sum of product of corresponding digits. Input 327 and 539 output 3x5 + 2x3 + 7x9 = 84. 

import java.util.Scanner;

public class sumDigitsTwoNos {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Input 1: ");

        int n1 = input.nextInt();

        System.out.println("Input 2 (Same number of digits as Input 1): ");

        int n2 = input.nextInt();

        int sum = 0;

        while (n1 > 0) {
            sum += (n1 % 10) * (n2 % 10);

            n1 /= 10;
            n2 /= 10;
        }

        System.out.printf("Sum = %d", sum);

        input.close();
    }
}
