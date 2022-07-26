// Code by Desh Iyer

// Write program to add 0th letter in the beginning. In above case ppwsxtpbcderxrtxgt

import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            String appendString = a.substring(0, 1);

            String resultString = appendString + a;

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
