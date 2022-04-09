/*  Code by Desh Iyer

    2.	Write a program for the following HashMap
        •	find whether specified key exists or not.
        •	find whether specified value exists or not
        •	get all keys from the given HashMap
        •	get all key-value pair as Entry objects

 */

import java.util.*;

public class q2 {
    public static void main(String[] args) {
        // Create HM
        HashMap<Integer, String> map1 = new HashMap<Integer, String>();

        // Adding Key-Value pairs to HM
        map1.put(1, "A");
        map1.put(2, "B");
        map1.put(3, "C");
        map1.put(4, "D");
        map1.put(5, "E");

        // Displaying HM
        System.out.println("Displaying created HashMap:");
        for (Map.Entry E: map1.entrySet()) {
            System.out.println(E.getKey() + " - " + E.getValue());
        }

        // Checking and displaying if HM contains certain keys
        System.out.println("\nChecking for key 3");
        displayCheckKey(map1.containsKey(3));
        System.out.println("\nChecking for key 6");
        displayCheckKey(map1.containsKey(6));
        
        // Checking and displaying if HM contains certain values
        System.out.println("\nChecking for value F");
        displayCheckValue(map1.containsValue("F"));
        System.out.println("\nChecking for value A");
        displayCheckValue(map1.containsValue("A"));

        // Printing only keys in the HM
        System.out.println("\nPrinting all keys in the above HashMap:");
        for (Map.Entry E: map1.entrySet()) {
            System.out.println(E.getKey());
        }

        // Printing the Key-Value pairs in the form of the entrySet
        System.out.println("\nPrinting all key-value pairs in the above HashMap:");
        System.out.println(map1.entrySet());
    }
}