// Code by Desh Iyer

// Program to demonstrate threads in Java using method 1

class NewThread extends Thread {
    NewThread() {
        super("Demo Thread");
        System.out.println("Child thread: " + this);
    }

    public void run() {
        try {
            for (int i = 5; i >= 0; i--) {
                System.out.println("Child thread: " + i);

                // Accepts time in ms (long int)
                // Frees up CPU for 500ms -> Half a sec
                Thread.sleep(500);
            }
        // To catch another thread interrupting our program
        } catch (InterruptedException e) {
            System.out.println("Child interrupted!");
        }

        System.out.println("Exiting child thread.");
    }
}

public class CreateThreadInheritance {
    public static void main(String[] args) {
        // Note: the ouput can vary since the CPU might execute another thread between these threads

        NewThread T = new NewThread();

        // Change state from New to Running
        T.start();

        try {
            for (int i = 5; i >= 0; i--) {
                System.out.println("Main thread: " + i);
                // Frees up CPU for 1s
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            // If a higher priority thread executes or when reading from an IOT device, its off, etc...  
            System.out.println("Main interrupted!");
        }

        System.out.println("Exiting main thread.");
    }
}
