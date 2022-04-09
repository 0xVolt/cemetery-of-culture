import java.text.MessageFormat;

public class MessageFormatClass {
    
    public static void main(String[] args) {
        // declaring a message using MessageFormat
        String message = MessageFormat.format("{0} is the first field and {1} is the second field\n", "firstField", "secondField");

        // printing message
        System.out.println(message);
    }
}
