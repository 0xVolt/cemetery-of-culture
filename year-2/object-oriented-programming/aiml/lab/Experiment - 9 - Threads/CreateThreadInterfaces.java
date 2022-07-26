class NewThreadInterfaceMethod implements Runnable {
    NewThreadInterfaceMethod() {
        
        //* Using def Thread(Reference Object of class implementing Runnable interface, Message)
        //? Instead of creating the thread object in the main method, we just create it here to save LOC and make it more efficient

        Thread t = new Thread(this, "Demo Thread");
        System.out.println("Child Thread: " + t);
        t.start();
    }

    @Override
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

public class CreateThreadInterfaces {
    public static void main(String[] args) {
        //! Start of main() method

        // Anonymous object having no reference variable
        new NewThreadInterfaceMethod();

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