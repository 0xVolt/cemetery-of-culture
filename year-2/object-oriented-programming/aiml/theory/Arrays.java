import java.util.Scanner;

public class Arrays {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // declaring an int array
        int[] firstArray = new int[5]; // default value of the ints is 0

        // printing the first index of the array
        System.out.println(firstArray[0]);

        // if an array index is being accessed which doesnt exist, then the ArrayIndexOutOfBounds exception pops up

        // declaring an array using loops
        int[] secondArray = new int[10];
        for (int i = 0; i < secondArray.length; i++) {
            System.out.printf("Index %d: ", i + 1);
            secondArray[i] = input.nextInt();
        }

        
        // printing the array using loops
        System.out.println("Printing secondArray:");
        for (int i = 0; i < secondArray.length; i++) {
            System.out.println(secondArray[i]);
        }

        input.close();
    }
}
