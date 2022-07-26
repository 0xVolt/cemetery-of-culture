// Code by Desh Iyer

// Suppose string has words. e.g. Ram is a good boy. Find first and second word.

import java.util.Scanner;

public class q8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");
        int count = 0;
        
        try {
            System.out.print("Enter string: ");
            String input = in.nextLine();
            
            a.append(input);
            
            int space = a.indexOf(" ");
            String first = a.substring(0, space);

            int secondSpace = a.substring(space + 1).indexOf(" ");
            String second = a.substring(space + 1, secondSpace);


            System.out.printf("First: %s\nSecond: %s", first, second);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        in.close();
    }
}