// Code by Desh Iyer

// Replace all x's by y's

import java.util.*;

public class q4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");

        try {
            System.out.print("Enter string: ");
            String input = in.nextLine();
            a.append(input);

            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == 'x') {
                    a.setCharAt(i, 'y');
                }
            }
            
            System.out.println("Required string: " + a);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        in.close();
    }
}
