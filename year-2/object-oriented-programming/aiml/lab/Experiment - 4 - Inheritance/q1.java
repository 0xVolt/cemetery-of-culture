// Code by Desh Iyer

// PROBLEM STATEMENT
// Write a Java program to show that private member of a super class cannot be accessed from derived classes

class Parent {
    private int privateInt;
    public int publicInt;

    public Parent() {}

    public Parent(int x, int y) {
        privateInt = x;
        publicInt = y;
    }

    public void printData() {
        System.out.printf("\nPrivate int = %d\nPublic int = %d", privateInt, publicInt);
    }
}

class Child extends Parent {
    public int childPublicInt;

    public Child() {}

    public Child(int x, int y, int z) {
        super(x, y);
        childPublicInt = z;
    }

    // We can clealy tell that this.privateInt raises an error since we are not able to access it due to its private visibility. This is contrasted by us being able to access this.publicInt which is a public field of Parent class 

    // public boolean accessSuperPrivate() {
    //     return if (this.privateInt) {}
    // }

    public void accessSuperPublic() {
        System.out.printf("Public integer of the parent class = %d", this.publicInt);
    }
}

public class q1 {
    public static void main(String[] args) {
        // Parent P = new Parent(2, 5);
        Child C = new Child(1, 2, 3);

        C.accessSuperPublic();
    }
}
