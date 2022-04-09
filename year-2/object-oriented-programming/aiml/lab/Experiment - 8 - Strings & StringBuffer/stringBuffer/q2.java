// Code by Desh Iyer

// Replace last x by y. (do not use loop)

import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String b;
        
        try {
            StringBuffer a = new StringBuffer("");

            System.out.print("Enter string: ");
            b = in.nextLine();

            a.append(b);

            a.reverse();

            int index = a.indexOf("x");

            a.setCharAt(index,'y');

            a.reverse();

            System.out.println(a);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        in.close();
    }
}
