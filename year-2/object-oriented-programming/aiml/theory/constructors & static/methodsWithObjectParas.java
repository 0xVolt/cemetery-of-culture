class Check {
    int x = 10, y = 15;
    public static void printMsg() {
        System.out.println("Inside printMsg() method!");
    }
    
    public void fa() {
        x = 2 * x;
        y = x + y;
    }
    
    public void fa(Check a) {
        x = 2 * a.x;
        y = a.x + a.y;
    }

    public void printData() {
        System.out.println("\nPrinting data");
        System.out.println("x: " + x);
        System.out.println("y: " + y);
    }
}

public class methodsWithObjectParas {
    public static void main(String[] args) {
        Check A = new Check();
        Check B = new Check();

        Check.printMsg();

        System.out.println("\n\nA:\n--------");
        A.fa();
        A.printData();

        // B calls fa() taking object A as a parameter
        System.out.println("\n\nB:\n--------");
        B.fa(A);
        B.printData();
    }
}
