import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Number N = null;

        System.out.println("Enter a number: ");
        int n = input.nextInt();

        try {
            N = new Number(n);
        } catch(LessThanException e) {
            System.out.println(e.getMessage());
        }

        System.out.println("Outside try-catch block!");
        input.close();
    }
}
