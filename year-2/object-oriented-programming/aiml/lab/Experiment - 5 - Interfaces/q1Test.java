// Code by Desh Iyer

interface test {
    void square();
}

class Arithmetic implements test {
    private int a;
    private int square;
    
    public Arithmetic() {}

    public Arithmetic(int a) {
        this.a = a;
    }
    
    public void printData() {
        System.out.println("A: " + a);
        System.out.println("Sqaure: " + square);
    }
    
    public void square() {
        this.square = this.a * this.a;
    }
}

class ToTestInt extends Arithmetic {
    private int b;
    private int testSquare;
    
    public ToTestInt() {}
    
    public ToTestInt(int a, int b) {
        super(a);
        this.b = b;
    }
    
    public void printData() {
        super.printData();
        System.out.println("B: " + b);
        System.out.println("Test Square: " + testSquare);
    }

    public void square() {
        super.square();
        this.testSquare = this.b * this.b;
    }
}

public class q1Test {
    public static void main(String[] args) {
        Arithmetic A = new Arithmetic(10);
        A.square();
        A.printData();

        System.out.println();

        Arithmetic B = new ToTestInt(15, 100);
        B.square();
        B.printData();
    } 
}
