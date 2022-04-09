class Counter {
    // Starting thread count from 1 for simplicity
    public int count = 1;

    public void printCount() {
        try {
            System.out.println("Synced count: " + count);
            count++;
        } catch (Exception e) {
            System.out.println("Thread interrupted.");
        }
    }
}

class ChildThread extends Thread {
    private Thread t;
    private String threadName;

    // Variable to keep track of number of objects created
    // Starting thread count from 1 for simplicity
    private static int threadCount = 1;
    
    Counter C;

    ChildThread(Counter c) {
        threadName = "Thread #" + threadCount;
        threadCount++;
        C = c;

        start();
    }

    public void run() {
        synchronized (C) {
            C.printCount();
        }
        System.out.println("Thread " + threadName + " exiting.");
    }

    public void start() {
        System.out.println("Starting " + threadName);
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
}

public class q3 {

    public static void main(String args[]) {
        Counter C = new Counter();

        ChildThread[] TArray = new ChildThread[10];

        int numberThreads = 10;
        for (int i = 0; i < numberThreads; i++) {
            TArray[i] = new ChildThread(C);
        }

        // wait for threads to end
        try {
            for (int i = 0; i < 10; i++) {
                TArray[i].join();
            }
        } catch (Exception e) {
            System.out.println("Interrupted");
        }
    }
}