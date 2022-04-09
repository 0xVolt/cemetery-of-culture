// Code by Desh Iyer

// Write a program, which reads a string and finds string after the first x. Let the input string is pwsxtpbcderxrtxgt then output is tpbcderxrtxgt.

import java.util.Scanner;

public class q6 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            int indexOfX = a.indexOf('x');

            String resultString = a.substring(indexOfX + 1);

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
