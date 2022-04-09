// Code by Desh Iyer

// Find the location of first ‘a’ in second word. 

import java.util.Scanner;

public class q27 {
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
            int secondSpace = temp.indexOf(' ') + firstSpace + 1;

            String secondWord = a.substring(firstSpace + 1, secondSpace);

            int location = secondWord.indexOf('a');

            System.out.println("Location of 'a' in the second word is (counting from 0): " + location);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
        
        in.close();
    }
}
