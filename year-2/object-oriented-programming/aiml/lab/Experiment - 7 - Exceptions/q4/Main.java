// Code by Desh Iyer

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Numbers N = null;

        try {
            int a = input.nextInt();
            int b = input.nextInt();

            N = new Numbers(a, b);
        } catch(InputMismatchException e) {
            System.out.println(e);
        } catch(ArithmeticException e) {
            System.out.println(e);
        }

        input.close();
    }    
}
