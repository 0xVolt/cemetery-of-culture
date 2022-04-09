// Code by Desh Iyer

class DetectStringArgException extends Exception {
    public DetectStringArgException(String message) {
        super(message);
    }
}

public class q2 {
    public static void main(String[] args) {
        try {
            if (!isNumber(args[0]) || !isNumber(args[1])) {
                throw new DetectStringArgException("Argument entered is not a number!");
            }

            int x = Integer.parseInt(args[0]);
            int y = Integer.parseInt(args[1]);

            System.out.println("Result = " + (x % y));
        } catch (DetectStringArgException e) {
            System.out.println(e.getMessage());
        }
    }

    public static boolean isNumber(String a) {
        int length = a.length();

        for (int i = 0; i < length; i++) {
            if (!Character.isDigit(a.charAt(i))) {
                return false;
            }
        }

        return true;
    }

    public static int isNumberInt(String a) {
        // int stringLen = a.length();

        for (int i = 0; i < a.length(); i++) {
            if (!Character.isDigit(a.charAt(i)))
                return 0;
        }
        
        return 1;
    }
}
