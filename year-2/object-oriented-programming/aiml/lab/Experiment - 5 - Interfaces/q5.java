// Code by Desh Iyer

import java.util.Scanner;

interface StackInterface {
    void push(int element);
    void pop();
    void display();
}

class Stack implements StackInterface {
    private int size = 10;
    private int top = -1;
    private int[] stack = new int[size]; 

    public void push(int element) {
        if (top == size - 1) {
            System.out.println("Stack Overflow!");
            return;
        } else {
            top++;
            stack[top] = element;
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Stack Underflow!");
            return;
        } else {
            System.out.println("Popped element: " + stack[top]);
            top--;
        }
    }

    public void display() {
        if (top == - 1) {
            System.out.println("Stack Empty!");
            return;
        } else {
            for (int i = top; i >= 0; i--) {
                System.out.printf("%d: %d\n", i, stack[i]);
            }
        }
    }
}

public class q5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Stack S = new Stack();
        int choice;

        for (;;) {
            System.out.println("\n\nM E N U\n");
            System.out.println("1. Push an element to the Stack");
            System.out.println("2. Pop an element from the Stack");
            System.out.println("3. Display all elements of the Stack");
            System.out.println("4. Exit\n");
            System.out.println("Enter your choice (1-4): ");

            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the element to push: ");
                    int pushElt = input.nextInt();
                    S.push(pushElt);
                    break;
                
                case 2:
                    S.pop();
                    break;

                case 3:
                    System.out.println("Displaying stack:\n");
                    S.display();
                    break;

                case 4:
                    System.exit(0);

                default:
                    System.out.println("Choose another option pls ty...");
            }
        }
    }
}