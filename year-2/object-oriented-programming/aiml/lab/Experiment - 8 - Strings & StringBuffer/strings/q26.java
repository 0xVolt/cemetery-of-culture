// Code by Desh Iyer

// Exchange last letters of first two words

import java.util.Scanner;

public class q26 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");

            // Use nextLine instead of next() to get a sentence
            a = in.nextLine();
            a = a.trim();

            int firstSpace = a.indexOf(' ');
            String firstWLL = String.valueOf(a.charAt(firstSpace - 1));
            
            
            String temp = a.substring(firstSpace + 1);
            int secondSpace = temp.indexOf(' ') + firstSpace + 1;

            String secondWLL = String.valueOf(a.charAt(secondSpace - 1));

            System.out.println(firstSpace);
            System.out.println(secondSpace);

            System.out.println(firstWLL);
            System.out.println(secondWLL);

            String finalString = a.substring(0, firstSpace - 1) + secondWLL + a.substring(firstSpace, secondSpace - 1) + firstWLL + a.substring(secondSpace);

            System.out.println(finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
        
        in.close();
    }
}
