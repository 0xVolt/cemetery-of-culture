// Code by Desh Iyer

// Write program to replace first occurrence of right neighbor of 2nd x by left neighbor of 1st x. Input imgpxugxutkl output imgpxpgxutkl. Input bcxdefxgh output bcxdefxch

import java.util.Scanner;

public class q17 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.println("Enter string: ");
            a = input.next();

            int firstX = a.indexOf('x');

            String newString = a.substring(firstX + 1);

            int secondX = newString.indexOf('x') + 1;

            char rightNSX = a.charAt(secondX + 1);

            int firstOccRNSX = a.indexOf(rightNSX);

            String LNFX = String.valueOf(a.charAt(firstX - 1));

            String finalString = a.substring(0, firstOccRNSX + 1) + LNFX + a.substring(firstOccRNSX + 2);

            System.out.println("Final string is: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}