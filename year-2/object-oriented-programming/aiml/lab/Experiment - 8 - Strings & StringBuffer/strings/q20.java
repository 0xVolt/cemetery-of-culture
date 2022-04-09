// Code by Desh Iyer

// Read two string. Print 1 if first string is bigger, 2 if second string is bigger, 0 if both are same.

import java.util.Scanner;

public class q20 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a, b;

        System.out.println("Enter two strings:");

        a = input.next();
        b = input.next();

        try {
            boolean isLexGreaterA = a.compareTo(b) > 0 ? true : false;

            if (isLexGreaterA) {
                System.out.println("1");
            } else {
                if (a.compareTo(b) == 0)
                    System.out.println("0");
                else
                    System.out.println("2");
            }
        } catch (Exception e) {
            System.out.println("Exception encountered: " + e.getMessage());
        }

        input.close();
    }
}
