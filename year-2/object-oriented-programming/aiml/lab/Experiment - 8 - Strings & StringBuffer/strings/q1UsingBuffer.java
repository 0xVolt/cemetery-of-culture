import java.util.Scanner;

public class q1UsingBuffer {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        StringBuffer a = new StringBuffer("");
        
        try {
            String b;
            
            System.out.print("Enter string: ");
            b = input.next();

            a.append(b);

            char deletedChar = a.charAt(2);
            a.deleteCharAt(2);

            System.out.println("Deleted char: " + deletedChar);
            System.out.println("Result string: " + a);

        } catch (Exception e) {
            System.out.println("Error encountered: " + e.getMessage());
        }
    
        input.close();
    }
}
