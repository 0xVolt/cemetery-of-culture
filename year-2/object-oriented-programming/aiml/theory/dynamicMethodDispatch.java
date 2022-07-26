class Display {
    public void printDisplay() {
        System.out.println("Indside Display class!");
    }
}

class SubDisplay extends Display {
    public void printDisplay() {
        System.out.println("Inside Sub Display class!");
    }
}

public class dynamicMethodDispatch {
    public static void main(String[] args) {
        Display D = new Display();
        SubDisplay S = new SubDisplay();

        // Creating an object of parent class using child class
        // Upcasting
        Display DS = new SubDisplay();

        D.printDisplay();
        S.printDisplay();
        DS.printDisplay();
    }
}