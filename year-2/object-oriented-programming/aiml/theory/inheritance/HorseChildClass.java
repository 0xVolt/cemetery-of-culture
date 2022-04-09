package Inheritance;

public class HorseChildClass extends AnimalBaseClass {
    public HorseChildClass() {
        // super() runs in bg
    }

    // private int numberEyes;
    // private int numberLegs;

    public HorseChildClass(String name, int size, int weight, int avg, int ne, int nl) {
        super(name, size, weight, avg);
        // numberEyes = ne;
        // numberLegs = nl;
        System.out.println("Child second ctor");
    }
}
