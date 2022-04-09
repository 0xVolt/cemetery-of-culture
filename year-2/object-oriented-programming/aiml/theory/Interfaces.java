// Interfaces are sort of contracts where each class that implements an interface, needs to implement the methods in an interface
// We dont EXTEND interfaces but we IMPLEMENT them - the terminology differs
// The interface is abstract - only function signatures but no definitions
// You can think of it as an abstract class with abstract methods in it

// They help tidy up code and make it easier to work on because of commitments
// Changing methods is difficult and its easier to add a new method rather than change a signature

// Convention in C# is to name it with an I before the name since there was no way to implement interfaces
// In Java, we just name it whatever we want

// public interface Telephone
interface Telephone {
    // declaring abstract methods without using the abstract keywords
    // public void powerOn(); -- modifier public is redundant for interfaces, this means by default its public
    // for classes, by default its package private

    void powerOn();
    void dial(int phoneNumber);
    boolean isRinging();

    public static final int a = 10;
    int b = 20;

    // static belongs to the interface
    static void staticMethod() {
        System.out.println("Static Method has been invoked!");
    }

    // default belongs to the instance
    // default void defaultMethod {
    //     System.out.println("Default Method has been invoked!");
    // }
}

// notice we use the keywork implements rather than extends
class DesktopPhone implements Telephone {
    // private int phoneNumber;
    // private boolean isRinging;

    public DesktopPhone(int n) {
        // this.phoneNumber = n;
    }

    @Override
    public void powerOn() {
        System.out.println("Powered On!");
    }

    @Override
    public void dial(int phoneNumber) {
        System.out.println("Dialing " + phoneNumber);
    }

    @Override
    public boolean isRinging() {
        System.out.println("True");
        return true;
    }
}

class MobilePhone implements Telephone {
    private int phNumber;
    private boolean isRinging;
    private boolean isOn;

    public MobilePhone(int n) {
        this.phNumber = n;
    }

    @Override
    public void powerOn() {
        System.out.println("Powered On!");
        isOn = true;
    }

    @Override
    public void dial(int phNumber) {
        if (isOn) {
            System.out.println("Dialing " + this.phNumber);
        } else {
            System.out.println("Cannot dial. Powered Off!");
        }
    }

    @Override
    public boolean isRinging() {
        return isRinging;
    }
}

public class Interfaces {
    public static void main(String[] args) {
        // DesktopPhone D = new DesktopPhone(1234);
        Telephone D = new DesktopPhone(1234);
        // its like using polymorphism but we cant say that the parent ref var is creating a child obj since were using an interface and a class which implements the interface

        D.powerOn();
        D.isRinging();

        MobilePhone M = new MobilePhone(4567);
        M.powerOn();
        M.dial(4567);
        if (M.isRinging()) {
            System.out.println("Phone ringing!");
        }
    } 
}
