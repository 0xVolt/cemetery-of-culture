// Code by Desh Iyer

// Program to exchange the string between 1st and 2nd x, with the string before 1st x. In above case tpbcderxpwsxrtxgt

import java.util.Scanner;

public class q12 {
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

            String beforeFirstX = a.substring(0, indexOfFirstX);
            String betweenXs = a.substring(indexOfFirstX + 1, indexOfSecondX);

            System.out.println("Before first x: " + beforeFirstX);
            System.out.println("Between x's: " + betweenXs);

            // Could've just omitted the second "x" but included it for better readability
            String finalString = betweenXs + "x" + beforeFirstX + "x" + a.substring(indexOfSecondX + 1);

            System.out.println("Result string: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}