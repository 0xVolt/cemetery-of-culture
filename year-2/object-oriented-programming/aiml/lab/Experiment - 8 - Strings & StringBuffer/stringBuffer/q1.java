// Code by Desh Iyer

// Read a string and replace first x by y. Input artxuxtxxp output artyuxtxxp

import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String b;
        
        try {
            StringBuffer a = new StringBuffer("");

            System.out.print("Enter string: ");
            b = in.nextLine();

            a.append(b);

            int index = a.indexOf("x");

            a.setCharAt(index,'y');

            System.out.println(a);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        in.close();
    }
}