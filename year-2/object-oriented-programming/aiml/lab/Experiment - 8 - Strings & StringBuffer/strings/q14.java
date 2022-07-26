// Code by Desh Iyer

// Write program to find 2nd location of 0th letter. Input pwerpty output 4.

import java.util.Scanner;

public class q14 {
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.println("Enter string: ");
            a = input.next();

            char firstChar = a.charAt(0);

            String newString = a.substring(1);

            int secondIndex = newString.indexOf(firstChar);
            secondIndex++;

            System.out.printf("Second location of character %c = %d", firstChar, secondIndex);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
