package Ppack;

public class A {

    protected void display1() {
        System.out.println("this is protected display method no 1");
    }

    public void display2() {
        System.out.println("this is a public and can be accessed anywhere");
    }

    void display3() {
        System.out.println(" this is the default one and can be accessed inside the package only");

    }

    private void display4() {
        System.out.println(" this is private and cant be easily accessed.works only for the same class  ");
    }
    /*
     * public static void main(String[] args) { A obj1 = new A(); obj1.display4();
     * // for protected only accessible inside the same class }
     */
}

class C {
    public static void main(String[] args) {
        A obj = new A();
        obj.display3();
        // obj.display4(); can be acccessed within the same class as it is private
    }
}