// Code by Desh Iyer

// Q8
// Implement a = a * b as a.mul(b), where a and b are objects of class Comp.

import java.util.*;

// Given class Comp
class Comp {
    float real, img;

    // Added parameterized ctor
    public Comp(float a, float b) {
        this.real = a;
        this.img = b;
    }

    // Added default ctor to avoid errors
    public Comp() {}

    public void getComp(float a, float b) {
        real = a;
        img = b;
    }

    public void print1() {
        System.out.println(real + " + " + img + "i");
    }

    public void duble() {
        real = 2 * real;
        img = 2 * img;
    }

    public void ktimes(int k) {
        real = k * real;
        img = k * img;
    }

    private float magsq() {
        return real * real + img * img;
    }

    public float magnitude() {
        float t;
        t = (float) Math.sqrt(this.magsq());
        return (t);
    }

    public void add(Comp x) {
        real = real + x.real;
        img = img + x.img;
    }

    public void add(Comp x, Comp y) {
        real = x.real + y.real;
        img = x.img + y.img;
    }

    public Comp add3(Comp x) {
        Comp c;
        float a, b;
        c = new Comp();
        a = real + x.real;
        b = img + x.img;
        c.getComp(a, b);
        return (c);
    }

    public float getreal() {
        return (real);
    }

    public float getimaginary() {
        return (img);
    }

    // Added mul to take an object of class Comp as an argument
    // Functionality: a = a * b
    public void mul(Comp b) {
        // To prevent the change in value of real to reflect in img
        float originalReal = this.real;
        float originalImg = this.img;

        originalReal = (this.real * b.real) - (this.img * b.img);
        originalImg = (this.real * b.img) + (this.img * b.real);

        this.real = originalReal;
        this.img = originalImg;
    }
}

public class MultiplyComplexNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Use the flg test input
        // n1: 2, -7
        // n2: 4, 3
        // o/p = 29, -22

        System.out.println("Input Real and Img of first number: ");
        int r1 = input.nextInt();
        int i1 = input.nextInt();
        
        System.out.println("Input Real and Img of second number: ");
        int r2 = input.nextInt();
        int i2 = input.nextInt();

        Comp a = new Comp(r1, i1);
        Comp b = new Comp(r2, i2);

        System.out.println("Printing both complex numbers");
        a.print1();
        b.print1();

        a.mul(b);

        System.out.println("Updated a");
        a.print1();

        input.close();
    }
}
