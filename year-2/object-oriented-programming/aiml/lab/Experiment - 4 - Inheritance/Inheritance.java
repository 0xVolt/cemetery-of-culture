// Code by Desh Iyer

// Program to demonstrate inheritance of child class from parent class

class Parent {
    private int x; // Cant be accessed
    protected int y; // Only within package and sub-classes
    public int z; // Everywhere

    public Parent() {}

    public Parent(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void printData() {
        System.out.println("\n\nInside Child class");
        System.out.printf("X = %d\nY = %d\nZ = %d", x, y, z);
    }
}

class Child extends Parent {
    int a;

    public Child() {}

    public Child(int x, int y, int z, int a) {
        // Simply calling super and passing paras, we call the super classes ctor
        super(x, y, z);
        this.a = a;
    }

    // Method overriding since the child class method has same signature as parent class method signature

    // Child contains two copys of printData, one is inherited and one is defined here. The one defined here overrides the one in the parent class
    public void printData() {
        System.out.println("\n\nInside Child class");

        // Using super._function name_ calls the method defined in the super class
        super.printData();
        System.out.println("\nA = " + a);
    }

    public void sum() {
        // We cant use x because x is private
        System.out.println("\nInside Child class\nInside sum()");
        System.out.println(y + z + a);
    }
}

public class Inheritance {
    public static void main(String[] args) {
        // Passing 1, 2, 3 as x, y, z
        Parent P = new Parent(1, 2, 3);
        
        P.printData();
        
        Parent P2 = new Child(1, 2, 3, 4);
        // Passing 4, 5, 6, 7 as x, y, z, a
        Child C = new Child(4, 5, 6, 7);

        C.printData();
        P2.printData();
        
        C.sum();
        // P2.sum(); will not work since it raises a compile time error since they are not compatible
        // However, typecasting the parent ref var will work
        ((Child)P).sum();

        // Note: for two classes, A and B, we cant do this
        // A a = new B();

        // but for parent and child classes:
        // Parent P = new Child(1, 2, 3, 4);
        // P.printData(); ---> executes the one in child
        // this is callde dynamic polymorphism
    }
}