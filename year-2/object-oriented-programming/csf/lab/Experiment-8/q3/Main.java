import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Numbers N = null;

        try {
            int a, b;
            // a = Integer.parseInt(args[0]);
            // b = Integer.parseInt(args[1]);
            a = in.nextInt();
            b = in.nextInt();

            N = new Numbers(a, b);
        } catch (InputMismatchException e) {
            System.out.println(e);
        } catch (ArithmeticException e) {
            System.out.println(e);
        }

        in.close();
    }
}