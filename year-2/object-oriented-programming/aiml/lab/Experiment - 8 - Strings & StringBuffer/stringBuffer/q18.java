// WORK IN PROGRESS

// Code by Desh Iyer

// Write program, which reads an expression and outputs its value. Assume that parenthesis is not used. Assume all operations are left associative and all numbers are integers. Take only ‘+’ and ‘*’ as operators. e.g. input 12+17*10 output 290.

import java.util.Scanner;

public class q18 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuffer a = new StringBuffer(" ");

        try {
            System.out.println("Enter a string: ");
            String input = in.next();
            a.append(input);

            for (int i = 0; i < 1; i++) {
                char indexChar = a.charAt(i);

                if (indexChar != (int) indexChar) {
                    int result;

                    switch (indexChar) {
                        case '+':
                            result = Integer.parseInt(String.valueOf(a.charAt(i - 1))) + Integer.parseInt(String.valueOf(a.charAt(i + 1)));
                            
                            break;
                            
                        case '-':
                            result = Integer.parseInt(String.valueOf(a.charAt(i - 1))) - Integer.parseInt(String.valueOf(a.charAt(i + 1)));

                            break;
                        
                        case '/':
                            result = Integer.parseInt(String.valueOf(a.charAt(i - 1))) / Integer.parseInt(String.valueOf(a.charAt(i + 1)));

                            break;

                        case '*':
                            result = Integer.parseInt(String.valueOf(a.charAt(i - 1))) * Integer.parseInt(String.valueOf(a.charAt(i + 1)));

                            break;
                    }

                    a.delete(i - 1, i + 1);
                }
            }

            System.out.println(a);
        } catch (Exception E) {
            System.out.println("Error encountered! - " + E.getMessage());
        }

        in.close();
    }
}