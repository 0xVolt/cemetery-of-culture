// 7.	Write program to print positional values of digits. Input 21463 output 3, 60, 400, 1000 and 20000.

import java.util.Scanner;

public class positionalValues {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Input: ");
        int n = input.nextInt();

        int originalN = n;
        System.out.printf("The positional values of %d are, ", originalN);

        int position = 1;
        while (n > 0) {
            System.out.printf("%d, ", (n % 10) * position);

            n /= 10;
            position *= 10;
        }


        input.close();
    }
}