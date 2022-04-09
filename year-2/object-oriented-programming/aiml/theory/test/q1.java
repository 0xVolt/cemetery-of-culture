public class q1 {
    public static void main(String[] args) {
        new B(5);
    }
}

class A {
    public A() {
        System.out.println("A");
    }

    public A(int i) {
        this();
        System.out.println(i);
    }
}

class B extends A {
    public B() {
        System.out.println("B");
    }

    public B(int i) {
        this();
        System.out.println(i + 3);
    }
}
