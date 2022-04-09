/*  Code by Desh Iyer

    1. Write a program for the following 
        •	Read all elements from ArrayList by using Iterator.
        •	Create duplicate object of an ArrayList instance.
        •	Reverse ArrayList content.

 */

import java.util.*;

public class q1 {
    public static void main(String[] args) {
        // Create a new ArrayList of Strings
        ArrayList<String> list = new ArrayList<String>();

        // Add strings to the ArrayList
        list.add("A");
        list.add("B");
        list.add("C");
        list.add("D");

        // Create an iterator
        Iterator IT = list.iterator();
        // Iterate through the ArrayList
        while (IT.hasNext()) {
            System.out.println(IT.next());
        }

        // Create a new ArrayList to store the clone (copy) of the above ArrayList
        ArrayList<String> temp = new ArrayList<String>();

        // Store the clone of the ArrayList
        temp = (ArrayList<String>) list.clone();

        // Or both together:
        // ArrayList<String> temp = (ArrayList<String>) list.clone();

        System.out.println("\nDuplicate Array List Instance:" + temp);

        // Reverse the above list and display
        Collections.reverse(list);
        System.out.println("\nReversed Array List:" + list);
    }
}