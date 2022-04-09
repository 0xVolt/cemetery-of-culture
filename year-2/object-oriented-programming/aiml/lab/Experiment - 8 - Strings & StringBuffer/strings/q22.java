// Code by Desh Iyer

// Print second word. In below case Prasad
// Input: ram Prasad dey

import java.util.Scanner;

public class q22 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");

            // Use nextLine instead of next() to get a sentence
            a = in.nextLine();
            a = a.trim();

            int firstSpace = a.indexOf(' ');

            String temp = a.substring(firstSpace + 1);

            int secondSpace = temp.indexOf(' ');

            String finalString = temp.substring(0, secondSpace);

            System.out.println(finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
        
        in.close();
    }

}
