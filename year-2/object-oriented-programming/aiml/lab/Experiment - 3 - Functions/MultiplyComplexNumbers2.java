// Code by Desh Iyer

// Q8
// Implement a = b * c as a = Comp.mul(b, c), where a and b are objects of class Comp.

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
    // Functionality: return b * c

    // Here we need to use static since we dont use the this. keyword. Since the func doesnt depend on the 'self' obj, its static
    public static Comp mul(Comp b, Comp c) {
        // To prevent the change in value of real to reflect in img
        Comp returnComp = new Comp();

        float returnReal = (b.real * c.real) - (b.img * c.img);
        float returnImg = (b.real * c.img) + (b.img * c.real);

        returnComp.real = returnReal;
        returnComp.img = returnImg;

        return returnComp;
    }
}

public class MultiplyComplexNumbers2 {
    public static void main(String[] args) {
        // TODO
        // Make it user input

        Comp a = new Comp();

        // Known test case
        Comp b = new Comp(2, -7);
        Comp c = new Comp(4, 3);

        // Output: 29, -22
        a = Comp.mul(b, c);

        a.print1();
    }
}
