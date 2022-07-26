// Code by Desh Iyer

// import java.util.Scanner;

class NonNumericValue extends Exception {
    public NonNumericValue(String Message) {
        super(Message);
    }
}

public class q2Test {
    public static boolean isInt(int x) {
        return (x % 1 == 0 ? true : false);
    }

    public static void main(String[] args) {
        try {
            if (!isInt(Integer.parseInt(args[0]))) {
                throw new NonNumericValue("Value entered is non-numeric");
            }
        } catch(NonNumericValue e) {
            System.out.println(e);
        } catch(NumberFormatException e) {
            System.out.println(e);
        }

        System.out.println("Outside try-catch block!");
    }    
}


