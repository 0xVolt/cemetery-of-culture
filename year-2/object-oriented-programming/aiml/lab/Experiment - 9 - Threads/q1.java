//1.Write a program to implement the concept of
// threading by extending Thread Class and Runnable interface.
public class q1 {
    public static void main(String[] args) {
        MyThread t1 = new MyThread(); // using extends
        t1.start();

        MyThread1 t2 = new MyThread1();
        Thread t = new Thread(t2);
        t.start();
    }

}

class MyThread extends Thread {
    MyThread() {

        System.out.println("The thread using the method 1");
    }

    public void run() {
        try {
            for (int i = 0; i <= 5; i++) {
                System.out.println("thread using extend Method1 is running" + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(" interruption");

        }
        System.out.println("exiting from the method 1 extends ");
    }
}

class MyThread1 implements Runnable {
    MyThread1() {

        System.out.println("the thread is using runnable method2");
    }

    public void run() {
        try {
            for (int i = 0; i <= 5; i++) {
                System.out.println("thread using RUNNABLE Method1 is running" + i);
                Thread.sleep(2000);
            }
        } catch (InterruptedException e) {
            System.out.println(" interruption");

        }
        System.out.println("exiting from the method 2 RUNNABLE ");
    }
}