// An instance of an interface can never be created
// You always use a class to implement an interface and then use the classes object to create an instance

interface NewTelephone {
    void powerOn();

    // Attributes always need to be declared
    // Since we will never create an instance of the interface, we use static 
    // final means that value will never change

    // like public is redundant to methods in interfaces,
    // public, static and final are redundant to attributes in an interface
    public static final int a = 10;
    int b = 20;

    // defining an interface
    static void staticMethod() {
        System.out.println("Static Method has been invoked!");
    }
}
