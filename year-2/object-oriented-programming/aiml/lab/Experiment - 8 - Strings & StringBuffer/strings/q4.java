// Code by Desh Iyer

// Write program to exchange 4th and 10th letter. In above case pwsxrpbcdetxrtxgt

import java.util.Scanner;

public class q4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            String fourthLetter = a.substring(4, 5);
            String tenthLetter = a.substring(10, 11);

            System.out.println("Fourth letter: " + fourthLetter);
            System.out.println("Tenth letter: " + tenthLetter);

            String resultString = a.substring(0, 4) + tenthLetter + a.substring(5, 10) + fourthLetter + a.substring(11);

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
