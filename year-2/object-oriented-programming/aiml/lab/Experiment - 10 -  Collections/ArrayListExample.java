import java.util.*;

public class ArrayListExample {
    public static void main(String[] args) {
        // Creating a generic collection
        ArrayList L = new ArrayList();

        // Creating a new generic collection
        ArrayList<String> I = new ArrayList<String>();

        // Creating a string array
        String[] things = { "eggs", "lasers", "hats", "pie" };

        // Creating a blank array list of strings
        List<String> list1 = new ArrayList<String>();

        // Adding array items to the list using a for-each enhanced for loop
        for (String s : things) {
            list1.add(s);
        }

        // Creating another list
        String[] moreThings = { "lasers", "hats" };

        // Demonstrating removing duplicates from a list

        List<String> list2 = new ArrayList<String>();

        for (String s : moreThings) {
            list2.add(s);
        }

        // To print without []
        // for (int i = 0; i < list1.size(); i++) {
        // System.out.printf("%s ", list1.get(i)); \
        // }

        // To print with []
        System.out.println(list1);

        // Iterating through an ArrayList using an iterator
        ArrayList<String> list3 = new ArrayList<String>();// Creating arraylist
        list3.add("Mango");// Adding object in arraylist
        list3.add("Apple");
        list3.add("Banana");
        list3.add("Grapes");
        // Traversing list through Iterator
        Iterator itr = list3.iterator();// getting the Iterator
        while (itr.hasNext()) {// check if iterator has the elements
            System.out.println(itr.next());// printing the element and move to next
        }
    }
}
