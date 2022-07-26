class NewThread implements Runnable {
    String name;
    Thread t;

    NewThread(String name) {
        this.name = name;
        this.t = new Thread(this, name);
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

public class CreateMultipleThreads {
    public static void main(String[] args) {
        new NewThread("One");
        new NewThread("Two");
        new NewThread("Three");

        try {
            for (int i = 5; i >= 0; i--) {
                System.out.println("Main thread: " + i);
                Thread.sleep(200);
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }

        System.out.println("Exiting main thread.");
    }
}
