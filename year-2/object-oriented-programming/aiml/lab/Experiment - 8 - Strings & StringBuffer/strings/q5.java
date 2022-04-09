// Code by Desh Iyer

// Write program to insert 't' between 1st and 2nd letter. In above case pwtsxtpbcderxrtxgt. [Hint: a+"t"+b].

import java.util.Scanner;

public class q5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a;

        try {
            System.out.print("Enter string: ");
            a = input.next();

            String resultString = a.substring(0, 1) + "t" + a.substring(3);

            System.out.println("Result string: " + resultString);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        input.close();
    }
}
