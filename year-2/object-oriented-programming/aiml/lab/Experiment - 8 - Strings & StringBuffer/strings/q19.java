// Code by Desh Iyer

// Read two strings. Print lexicographically bigger string first and smaller later

import java.util.Scanner;

public class q19 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a, b;

        System.out.println("Enter two strings:");

        a = input.next();
        b = input.next();

        try {
            boolean isLexGreaterA = a.compareTo(b) > 0 ? true : false;

            if (isLexGreaterA) {
                System.out.printf("%s\t%s", a, b);
            } else {
                System.out.printf("%s\t%s", b, a);
            }
        } catch (Exception e) {
            System.out.println("Exception encountered: " + e.getMessage());
        }

        input.close();
    }
}
