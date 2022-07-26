// Code by Desh Iyer

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Calc C1 = new Calc();

        System.out.println("Enter two numbers separated by a space: ");

        int a, b;
        a = input.nextInt();
        b = input.nextInt();

        try {
            long result = C1.power(a, b);
            System.out.println(result);
            // System.out.println("Result = " + result);
        } catch(Exception e) {
            System.out.println(e);
        }

        input.close();
    }
}
