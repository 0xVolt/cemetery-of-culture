// Code by Desh Iyer

// Write program to delete the string between 1st and 2nd x. In above case pwsxxrtxgt.

import java.util.Scanner;

public class q11 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();
    
            int indexOfFirstX = a.indexOf('x');
    
            String resultString = a.substring(0, indexOfFirstX) + a.substring(indexOfFirstX + 1);

            int indexOfSecondX = resultString.indexOf('x') + 1;
    
            System.out.println("X #1: " + indexOfFirstX);
            System.out.println("X #2: " + indexOfSecondX);

            String finalString = a.substring(0, indexOfFirstX + 1) + a.substring(indexOfSecondX);
    
            System.out.println("Result string: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
