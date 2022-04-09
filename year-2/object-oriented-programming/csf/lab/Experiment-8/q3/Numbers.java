import java.util.InputMismatchException;

public class Numbers {
    private int a;
    private int b;
    private int mod;

    Numbers(int a, int b) throws InputMismatchException, ArithmeticException {
        if (a != (int) a || b != (int) b) {
            throw new InputMismatchException("Values entered are non-numeric!");
        } else if (b == 0) {
            throw new ArithmeticException("Second value should not be 0");
        } else {
            this.a = a;
            this.b = b;
            this.mod = a % b; 
            System.out.println("Object has been created!\nModulo = " + mod);
        }
    }
}
