public class q4 {
    public static void main(String[] args) {
        int resultString1 = isNumber(args[0]);
        
        try {
            resultString1 = 1 / resultString1;

            System.out.println(0); // Output if it is a number
        } catch (ArithmeticException e) {
            try {
                char p = args[0].charAt(0);

                int result = Character.isDigit(p) ? 1 : 0;
                result = 1 / result;

                int length = args[0].length();

                int index = length - (p + 1);

                try {
                    int[] testArray = new int[100];

                    testArray[index] = 2;

                    System.out.println(2);
                } catch (ArrayIndexOutOfBoundsException g) {
                    // (p + 1) is greater than length
                    String pString = String.valueOf(p + 1); 
                    String newString = args[0].replace(pString, "");

                    int newStringResult = isNumber(newString);

                    System.out.println(3);
                    try {
                        result = 1 / result;
                    } catch (ArithmeticException h) {
                        System.out.println(4);
                    }
                }
            } catch (Exception f) {
                System.out.println(1);
            }
        }
    }

    // Returns 0 if there is a character
    // Returns 1 if it is a number 
    static int isNumber(String a) {
        int length = a.length();

        for (int i = 0; i < length; i++) {
            // if (!Character.isDigit(a.charAt(i))) {
            //     return false;
            // }
            try {
                int result = Character.isDigit(a.charAt(i)) ? 1 : 0;
                int checkResult = 1 / result;
            } catch (ArithmeticException e) {
                return 0;
            }
        }

        return 1;
    }
}
