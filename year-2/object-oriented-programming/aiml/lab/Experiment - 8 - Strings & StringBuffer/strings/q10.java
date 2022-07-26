// Code by Desh Iyer

// Write program to find string before 2nd x. In above case pwsxtpbcder

import java.util.Scanner;

public class q10 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();
    
            int indexOfFirstX = a.indexOf('x');
    
            String resultString = a.substring(0, indexOfFirstX) + a.substring(indexOfFirstX + 1);
    
            // + 1 to compensate for the removal of the first x when counting indices of the original string
            int indexOfSecondX = resultString.indexOf('x') + 1;
    
            String finalString = a.substring(0, indexOfSecondX);

            System.out.println("X #1: " + indexOfFirstX);
            System.out.println("X #2: " + indexOfSecondX);
    
            System.out.println("Result string: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
