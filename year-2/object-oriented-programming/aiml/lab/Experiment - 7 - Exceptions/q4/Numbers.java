import java.util.InputMismatchException;

public class Numbers {
    private int a;
    private int b;

    public Numbers(int a, int b) throws InputMismatchException, ArithmeticException {
        if (a != (int) a || b != (int) b) {
            throw new InputMismatchException();
        } else if (b == 0) {
            throw new ArithmeticException("/ by zero");
        } else {
            this.a = a;
            this.b = b;
            System.out.println("Object created!\na / b = " + (this.a / (float)this.b));
        }
    }
}