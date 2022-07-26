/*  Code by Desh Iyer

    3. Write a program for the following HashSet

        •	copy another collection object to HashSet object.
        •	delete all entries at one call from HashSet
        •	search user defined objects from HashSet

 */

import java.util.*;

public class q3 {
    public static void main(String[] args) {
        // Creating a Scanner object to take user input
        Scanner in = new Scanner(System.in);

        // Creating an ArrayList of names
        ArrayList<String> names = new ArrayList<String>();

        // Adding names to the AL
        names.add("Bhavy");
        names.add("Bharat");
        names.add("Divy");
        names.add("Divyam");

        // Printing original AL
        System.out.println("Printing values in original ArrayList:");
        for (String Value: names) {
            System.out.println(Value);
        }

        // Creating a copy of the org AL
        System.out.println("\nCreating a copy of the above ArrayList");
        HashSet<String> copy = new HashSet<String>(names);

        // Taking user input
        System.out.println("\nEnter a value to search the HashSet for: ");
        String lookFor = in.next();
        
        // Searching HS for user inputted String
        if (copy.contains(lookFor)) {
            System.out.println("Value entered is present in the HashSet!");
        } else {
            System.out.println("Value entered is NOT present in the HashSet!");
        }

        System.out.println("\nClearing HashSet");
        // Clearing all elts of the HS in one statement
        copy.clear();
        System.out.println("Printing HashSet: " + copy);

        in.close();
    }
}
