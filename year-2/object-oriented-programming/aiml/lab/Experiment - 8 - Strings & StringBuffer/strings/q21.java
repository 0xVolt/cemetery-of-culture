// Code by Desh Iyer

// Read three strings. Print 1 if first string is biggest, 2 if second string is biggest, 3 if 3rd string is biggest, 0 if all are same, -1 if 1st and 2nd string are biggest, -2 if 2nd and 3rd string are biggest, -3 if 1st and 3rd string are biggest.

// To be optimized

import java.util.Scanner;

public class q21 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a, b, c;

        System.out.println("Enter three strings:");

        a = input.next();
        b = input.next();
        c = input.next();

        try {
            if (a.compareTo(b) == 0 && a.compareTo(c) == 0)
                System.out.println("0");
            else {
                if (a.compareTo(b) > 0) {
                    if (a.compareTo(c) > 0) {
                        System.out.println("1");
                    } else if (a.compareTo(c) == 0) {
                        System.out.println("-3");
                    } else {
                        System.out.println("3");
                    }
                } else if (a.compareTo(b) == 0) {
                    System.out.println("-1");
                } else if (b.compareTo(c) == 0) {
                    System.out.println("-2");
                } else {
                    System.out.println("2");
                }

            }
        } catch (Exception e) {
            System.out.println("Exception encountered: " + e.getMessage());
        }

        input.close();
    }
}
