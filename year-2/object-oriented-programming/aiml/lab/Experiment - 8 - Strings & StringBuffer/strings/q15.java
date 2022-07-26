// Code by Desh Iyer

// Write program, which will delete 1st y immediately after 1st x. If input string is pgyeryuyixaysdyexer then output is pgyeryuyixasdyexer

import java.util.Scanner;

public class q15 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.println("Enter string: ");
            a = input.next();

            int firstX = a.indexOf('x');

            String newString = a.substring(firstX);

            int diffStringLen = a.length() - newString.length();

            int firstY = newString.indexOf('y');
            firstY += diffStringLen;

            String finalString = a.substring(0, firstY) + a.substring(firstY + 1);

            System.out.println("The final string is: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    } 
}
