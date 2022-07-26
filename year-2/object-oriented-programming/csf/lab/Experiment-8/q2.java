import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter two numbers: ");
        int a = in.nextInt();
        int b = in.nextInt();

        try {
            int c = a / b;
            System.out.println("Division = " + c);
        } catch (ArithmeticException e) {
            System.out.println("Error. You are trying to divide by zero!");
        }
        
        System.out.println("Outside try-catch block!");

        in.close();
    }
}
