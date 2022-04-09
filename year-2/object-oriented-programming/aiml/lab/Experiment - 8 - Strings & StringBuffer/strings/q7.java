// Code by Desh Iyer

// Write program to replace first x by y. In above case pwsytpbcderxrtxgt.

import java.util.Scanner;

public class q7 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            int indexOfX = a.indexOf('x');

            String resultString = a.substring(0, indexOfX) + "y" + a.substring(indexOfX + 1);

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
