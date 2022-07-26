// Code by Desh Iyer

// 5.	Find the number of x’s. In above case 4

import java.util.Scanner;

public class q5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");

        try {
            System.out.print("Enter string: ");
            String input = in.nextLine();
            a.append(input);

            int count = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == 'x') {
                    count++;
                }
            }
            
            System.out.println("Number of x's: " + count);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }

        in.close();
    }
}
