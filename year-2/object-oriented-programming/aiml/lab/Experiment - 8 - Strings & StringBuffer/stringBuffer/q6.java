// Code by Desh Iyer

// Whether given string is a Palindrome. A Palindrome is word which remains same when reversed. e.g. malayalam. 

import java.util.Scanner;

public class q6 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");

        try {
            System.out.print("Enter string: ");
            String input = in.nextLine();
            
            a.append(input);
            StringBuffer b = a.reverse();

            if (a.compareTo(b) == 0) {
                System.out.println("String entered is a palindrome!");
            } else {
                System.out.println("String entered is not a palindrome!");
            }
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        in.close();
    }
}
