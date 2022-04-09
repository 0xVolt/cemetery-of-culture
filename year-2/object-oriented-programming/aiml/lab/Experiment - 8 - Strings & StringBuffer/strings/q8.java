// Code by Desh Iyer

// Write program to output the location of second x. In above case 11.

import java.util.Scanner;

public class q8 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            int indexOfX = a.indexOf('x');

            String resultString = a.substring(0, indexOfX) + a.substring(indexOfX + 1);

            // + 1 to compensate for the removal of the first x when counting indices of the original string
            int indexOfSecondX = resultString.indexOf('x') + 1;

            System.out.println("X #1: " + indexOfX);
            System.out.println("X #2: " + indexOfSecondX);

            System.out.println("Location of second x: " + indexOfSecondX);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
