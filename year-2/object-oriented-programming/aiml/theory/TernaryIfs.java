import java.util.Scanner;

public class TernaryIfs {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String test = "red";
        boolean testColour;

        testColour = test == "red"? true: false;

        System.out.println(testColour);

        input.close();
    }
}
