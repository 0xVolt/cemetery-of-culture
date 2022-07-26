// Code by Desh Iyer

// Write program, which reads a string. Let x and y be respectively left and right neighbors of the second occurrence of the 0th  letter. Find the substring between first occurrence of y and (first occurrence of x after first occurrence of y). e.g. input patkgfmpkst output kgfm. Input pastgksfsptse output tgks. Input raklfrgmcfd output gmcf. Input ywetyykjhtl output ywet.

import java.util.Scanner;

public class q18 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.println("Enter string: ");
            a = input.next();

            char zeroth = a.charAt(0);
            String b = a.substring(1);
            int secondZeroth = b.indexOf(zeroth) + 2;

            char x = a.charAt(secondZeroth - 1);
            char y = a.charAt(secondZeroth + 1);

            String temp = a.substring(a.indexOf(y) + 1);

            String finalString = a.substring(a.indexOf(y + 1), temp.indexOf(x) + 1);

            System.out.println("Final string is: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
