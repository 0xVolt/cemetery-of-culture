// Code by Desh Iyer

// Find length of the string without using length()

import java.util.Scanner;

public class q7 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");
        int count = 0;
        
        try {
            System.out.print("Enter string: ");
            String input = in.nextLine();
            
            a.append(input);
            
            for (int i = 0; a.charAt(i) != '\0'; i++) {
                count++;
            }

        } catch (Exception e) {
            System.out.println("Length of string: " + count);
        }

        in.close();
    }
}
