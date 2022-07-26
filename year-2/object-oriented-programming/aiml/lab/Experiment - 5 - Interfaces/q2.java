// Code by Desh Iyer

interface A {
    void meth1();
    void meth2();
}

class MyClass implements A {
    private int x;

    public MyClass(int a) {
        x = a;
    }

    public void printData() {
        System.out.println("X: " + x);
    }

    public void meth1() {
        System.out.println("Square = " + Math.pow(x, 2));
    }

    public void meth2() {
        System.out.println("Cube = " + Math.pow(x, 3));
    }
}

public class q2 {
    public static void main(String[] args) {
        MyClass M = new MyClass(15);
        M.printData();
        M.meth1();
        M.meth2();
    }
}
