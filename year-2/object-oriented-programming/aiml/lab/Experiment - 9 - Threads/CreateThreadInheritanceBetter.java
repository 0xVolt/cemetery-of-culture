// Code by Desh Iyer

// Program to demonstrate threads in Java using method 1 but more efficiently

class NewThread extends Thread {
    NewThread() {
        super("Demo Thread");
        System.out.println("Child thread: " + this);

        // To save lines by converting start to run state on declaration 
        start();
    }

    public void run() {
        try {
            for (int i = 5; i >= 0; i--) {
                System.out.println("Child thread: " + i);

                // Accepts time in ms (long int)
                // 500ms -> Half a sec
                Thread.sleep(500);
            }
        // To catch another thread interrupting our program
        } catch (InterruptedException e) {
            System.out.println("Child interrupted!");
        }

        System.out.println("Exiting child thread.");
    }
}

public class CreateThreadInheritanceBetter {
    public static void main(String[] args) {
        // To create a thread
        // Though we give the object a name, we never use it, so to save time, we create an anon object 
        //// NewThread T = new NewThread();
        new NewThread();

        // Change state from New to Running
        // T.start();

        try {
            for (int i = 5; i >= 0; i--) {
                System.out.println("Main thread: " + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Main interrupted!");
        }

        System.out.println("Exiting main thread.");
    }
}
