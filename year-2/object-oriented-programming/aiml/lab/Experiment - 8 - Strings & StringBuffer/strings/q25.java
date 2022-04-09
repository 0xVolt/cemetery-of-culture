// Code by Desh Iyer

// Exchange first letters of first two words

import java.util.Scanner;

public class q25 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");

            // Use nextLine instead of next() to get a sentence
            a = in.nextLine();
            a = a.trim();

            String firstWFL = String.valueOf(a.charAt(0));

            int firstSpace = a.indexOf(' ');

            String secondWFL = String.valueOf(a.charAt(firstSpace + 1));

            String finalString = secondWFL + a.substring(1, firstSpace + 1) + firstWFL + a.substring(firstSpace + 2);

            System.out.println(finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
        
        in.close();
    }
}
