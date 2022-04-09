// Code by Desh Iyer

import java.util.*;

interface Test {
    public void square();
}

class Arithmetic implements Test {
    public void square() {
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a number to get it's square: ");
        int num = input.nextInt();

        System.out.println("The square of " + num + " is :" + num * num);

        input.close();
    }
}

// This class is 'ToTestInt class'
public class q1 {  
    public static void main(String[] args) {
        Arithmetic obj = new Arithmetic();
        obj.square();
    }
}