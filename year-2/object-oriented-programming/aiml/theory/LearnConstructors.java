// They are methods that aer invoked when the class is initialized for the first time
// We can do some ops when the class is first initialized

// each class by default has a parameter-less default constructor with no code in it
// we can explicitly put some code in it

// the order of calling constructors is opposite to the order of printing inside the constructors

// import java.util.Scanner;

public class LearnConstructors {
    private int a;
    private String b;

    public int getA() {
        return this.a;
    }

    public void setA(int a) {
        this.a = a;
    }

    public String getB() {
        return this.b;
    }

    public void setB(String b) {
        this.b = b;
    }

    public LearnConstructors() {
        // how to call one constuctor from another
        // note: this needs to be the first line in the constructor
        // this jumps to the para ctor and sets the two values with what is passed to this()
        this(10, "This is a pre-test string");

        System.out.println("Empty ctor");
        
    }
    
    public LearnConstructors(int x, String y) {
        // to call the empty constructor, we run
        // this();
        
        a = x;
        b = y;

        System.out.println("Parameterized ctor");
    }

    public static void main(String[] args) {
        // Scanner input = new Scanner(System.in);

        // int x;
        // String y;

        // x = input.nextInt();
        // y = input.next();

        // to demonstrate this()
        LearnConstructors object = new LearnConstructors();
        // LearnConstructors object = new LearnConstructors(x, y);

        System.out.println(object.getB());

        // LearnConstructors nullObject = null;
        // nullObject.getA(); will return a 'NullPointerException' since the object is null

        // input.close();
    }
}
