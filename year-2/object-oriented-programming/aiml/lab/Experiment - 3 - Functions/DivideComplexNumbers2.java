// Code by Desh Iyer

// Q12
// Implement a=b/c as a=divide(b, c), where a, b and c are objects of class Comp.
// [Hint: a/b is defined as a*b.conjugate()/b.magnitude2()]

// import java.util.*;

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
        return (real * real) + (img * img);
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

    public static Comp mul(Comp b, Comp c) {
        // To prevent the change in value of real to reflect in img
        Comp returnComp = new Comp();

        float returnReal = (b.real * c.real) - (b.img * c.img);
        float returnImg = (b.real * c.img) + (b.img * c.real);

        returnComp.real = returnReal;
        returnComp.img = returnImg;

        return returnComp;
    }

    public static Comp divideObjs(Comp b, Comp c) {
        Comp resultObject = new Comp();

        Comp numerator = new Comp();
        c.img *= -1;
        numerator = mul(b, c);

        // double bMag = this.magnitude();
        float denominator = c.magnitude() * c.magnitude();

        resultObject.real = numerator.real / denominator;
        resultObject.img = numerator.img / denominator;

        return resultObject;
    }
}

public class DivideComplexNumbers2 {
    public static void main(String[] args) {
        Comp a = new Comp();

        // Known test case
        Comp b = new Comp(2, -7);
        Comp c = new Comp(4, 3);

        // Known output is (-0.52, -1.36)
        a = Comp.divideObjs(b, c);

        a.print1();
    }
}