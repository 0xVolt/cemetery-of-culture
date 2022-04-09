// Code by Desh Iyer

// Write program to remove 2nd letter. Let the input string is pwsxtpbcderxrtxgt then output is pwxtpbcderxrtxgt.

import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    
        try {
            System.out.print("Enter string: ");
            String a = input.next();
            
            String resultString = a.substring(0, 2) + a.substring(3);
            char deletedChar = a.charAt(2);

            System.out.println("Result after deleting character at index 2: " + resultString);

            System.out.println("Deleted char: " + deletedChar);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
    
        input.close();
    }
}
