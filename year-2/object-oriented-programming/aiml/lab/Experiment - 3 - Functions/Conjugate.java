// Code by Desh Iyer

// Q10	
// Define Comp conjugate(); e.g. conjugate(2+3i) is 2-3i


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

    // Here we dont put static since we refer to 'this' object and hence the function depends on the value of this.img
    public void Conjugate() {
        this.img *= -1;
    }
}

public class Conjugate {
    public static void main(String[] args) {
        Comp a = new Comp(2, 3);

        System.out.println("Original complex number: ");
        a.print1();
        
        System.out.println("Conjugate complex number: ");
        a.Conjugate();
        a.print1();
    }
}
