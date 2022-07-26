// Code by Desh Iyer

// Write program to exchange neighbors of first occurrence of left neighbors of first ‘x’. e.g. input abcdefxgh output abcdxfegh. input abfcdefxgh output acfbdefxgh

import java.util.Scanner;

public class q16 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.println("Enter string: ");
            a = input.next();

            int firstX = a.indexOf('x');
            char leftNeighbourFirstX = a.charAt(firstX - 1);
            String sub = String.valueOf(leftNeighbourFirstX);
            
            int firstOccLeftNeighbour = a.indexOf(leftNeighbourFirstX);
            String leftN = a.substring(firstOccLeftNeighbour - 1, firstOccLeftNeighbour);
            String rightN = a.substring(firstOccLeftNeighbour + 1, firstOccLeftNeighbour + 2);

            String finalString = a.substring(0, a.indexOf(leftN)) + rightN + sub + leftN + a.substring(a.indexOf(rightN) + 1);

            System.out.println("The final string is: " + finalString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}