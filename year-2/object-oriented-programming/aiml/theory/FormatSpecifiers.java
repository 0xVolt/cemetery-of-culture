public class FormatSpecifiers {

    public static void main(String[] args) {
        // declare string
        String sVariable = "This is a test String";

        // if we need to print a new line after each print statement, use the println() method
        // we cant use println with format specs, hence the name print'F'
        System.out.printf("The string is: %s\n", sVariable);
        System.out.printf("Printing a number: %d\n", 10);

        // storing the string then printing it
        String sNewVariable = String.format("The number to print is %d", 25);
        System.out.println(sNewVariable);
    }
}
