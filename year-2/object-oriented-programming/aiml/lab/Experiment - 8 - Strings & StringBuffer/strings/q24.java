// Code by Desh Iyer

// Exchange first and second word

import java.util.Scanner;

public class q24 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");

            // Use nextLine instead of next() to get a sentence
            a = in.nextLine();
            a = a.trim();

            int firstSpace = a.indexOf(' ');

            String firstW = a.substring(0, firstSpace);

            String temp = a.substring(firstSpace + 1);

            int secondSpace = temp.indexOf(' ');

            String secondW = temp.substring(0, secondSpace);

            String finalString = secondW + " " + firstW + temp.substring(secondSpace);

            System.out.println(finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
        
        in.close();
    }
}
