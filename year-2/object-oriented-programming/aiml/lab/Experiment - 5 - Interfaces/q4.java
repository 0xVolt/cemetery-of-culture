// Code by Desh Iyer

interface implementMethods {
    void division(int a);

    void modules(int b);
}

class Methods implements implementMethods {
    int divisionVar, moduleVar;

    public Methods() {}

    public void division(int a) {
        divisionVar = a;
    }

    public void modules(int b) {
        moduleVar = b;
    }

    public void displayDetails() {
        System.out.println("Division : " + divisionVar);
        System.out.println("Modules  : " + moduleVar);
    }
}

class q4 {
    public static void main(String args[]) {
        Methods M = new Methods();

        M.division(5);
        M.modules(15);
        M.displayDetails();
    }
}