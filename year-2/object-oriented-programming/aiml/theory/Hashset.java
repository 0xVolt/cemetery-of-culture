import java.util.*;

public class Hashset {
    public static void main(String[] args) {
        HashSet<String> numbers = new HashSet<>();

        // Adding repetitions to show that hashing works
        numbers.add("One");
        numbers.add("One");
        numbers.add("Two");
        numbers.add("Three");
        numbers.add("Three");
        numbers.add("Three");
        numbers.add("Four");
        numbers.add("Five");

        Iterator<String> itr = numbers.iterator();

        while (itr.hasNext()) {
            System.out.println(itr.next());
        }
    }   
}
