// Code by Desh Iyer

// Write program to exchange first two letters. In above case wpsxtpbcderxrtxgt

import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            String firstLetter = a.substring(0, 1);
            String secondLetter = a.substring(1, 2);

            String resultString = secondLetter + firstLetter + a.substring(3);

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
