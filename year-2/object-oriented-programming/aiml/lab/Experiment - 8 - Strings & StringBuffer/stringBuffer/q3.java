// Code by Desh Iyer

// Replace second x by y.

import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String b;
        
        try {
            StringBuffer a = new StringBuffer("");

            System.out.print("Enter string: ");
            b = in.nextLine();

            a.append(b);

            int tempIndex = a.indexOf("x");
            
            a.setCharAt(tempIndex,'a');
            
            int index = a.indexOf("x");
            
            a.setCharAt(index,'y');
            a.setCharAt(tempIndex,'x');

            System.out.println(a);
        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }

        in.close();
    }
}
