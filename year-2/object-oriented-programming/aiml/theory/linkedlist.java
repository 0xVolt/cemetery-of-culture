import java.util.*;

class linkedlist {
    public static void main(String[] args) {
        LinkedList <Double> numList = new LinkedList<>();
        
        numList.add(1.0);
        numList.add(2.21);
        numList.add(4.2);

        Iterator<Double> revIter = numList.descendingIterator();

        System.out.println("Displaying linked list in reverse order:");
        while (revIter.hasNext()) {
            System.out.println(revIter.next());
        }
    }
}