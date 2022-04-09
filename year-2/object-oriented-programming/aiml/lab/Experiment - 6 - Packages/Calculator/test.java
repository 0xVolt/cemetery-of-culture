//1. Write a Java program to implement the concept of importing classes from user defined package and created packages.
// Code by Bhavy Kharbanda
//Sap Id: 500082531
// This the test class in package calculator and this will be imported in the main class.

package Calculator;

public class test {
    public void add(int a, int b) {
        System.out.println("Addition of " + a + " & " + b + ": " + (a + b));
    }

    public void sub(int a, int b) {
        System.out.println("Subtraction of " + a + " & " + b + ": " + (a - b));
    }

    public void mult(int a, int b) {
        float result;
        result = a * b;
        System.out.println("Multiplication of " + a + " & " + b + ": " + result);
    }

    public void divide(int a, int b) {
        float result;
        result = a / b;
        System.out.println("Division of " + a + " & " + b + ": " + result);
    }
}
