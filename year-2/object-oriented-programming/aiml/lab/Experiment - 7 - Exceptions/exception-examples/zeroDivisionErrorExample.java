import java.util.Scanner;

public class zeroDivisionErrorExample {
    public static void main(String[] args) {
        int a = 1, b = 0;
        Scanner input = new Scanner(System.in);
        
        // try throws the exception
        try {
            int c = a / b;
            System.out.println("C = A / B = " + c);
        } catch(ArithmeticException ex) { // catch is called the exception handler
            System.out.println("Arithmetic error!");
            System.out.println(ex.getMessage());
        }
        
        input.close();
    } 
}