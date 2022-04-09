class Check {
    // static funtions dont need an object to run
    public static void printMsg() {
        System.out.println("Inside the printMsg() method!");
    }
}

class staticExample {
    // another exmaple of static, no instance of class example1 is created yet main() runs
    public static void main(String[] args) {
        Check.printMsg();
    }    
}