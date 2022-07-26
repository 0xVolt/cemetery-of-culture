// For keyboard input
import java.util.Scanner;

// This program returns the second word of a string
public class q22a {
    public static void main(String[]args) {

        //Creates a scanner object for keyboard input
        Scanner in = new Scanner(System.in);

        //Gets a string from the user
        System.out.print("String: ");
        String x = in.nextLine();

        //If the string contains more than one word
        if (x.contains(" ")) {
            //Finds the position of the first space, adds one to it to find the position of the first character of the second word
            int pos = x.indexOf(" ") + 1;

            //Replace the first space with a different character so the program can test if it has a second space
            char[] chars = x.toCharArray();
            chars[pos - 1] = 'a';
            x = String.valueOf(chars);

            //If there is a space after the second word
            if (x.contains(" ")) {

                //Finds the position of the space after the second word
                int pos1 = x.indexOf(" ", pos);

                //Gets the second word
                String second = x.substring(pos, pos1);

                //Displays the second word
                System.out.println(second);

                //If there is not a space after the second word
            } else {

                //Add a space to the end
                x += " ";

                //Finds the position of the space after the second word
                int pos1 = x.indexOf(" ", pos);

                //Gets the second word
                String second = x.substring(pos, pos1);

                //Displays the second word
                System.out.println(second);
            }
        } 
    }
}