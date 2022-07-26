// Code by Desh Iyer

// Write program to exchange neighbors of first x. In above case pwtxspbcderxrtxgt
// For input: pwsxtpbcderxrtxgt

import java.util.Scanner;

public class q13 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();
    
            int indexOfFirstX = a.indexOf('x');
    
            System.out.println("Index of first x: " + indexOfFirstX);

            String charBefore = a.substring(indexOfFirstX - 1, indexOfFirstX);
            String charAfter = a.substring(indexOfFirstX + 1, indexOfFirstX + 2);

            System.out.println("Character before first 't': " + charBefore);
            System.out.println("Character after first 't': " + charAfter);
            
            String finalString = a.substring(0, indexOfFirstX - 1) + charAfter + 'x' + charBefore + a.substring(indexOfFirstX + 2); 

            System.out.println("Result string: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}