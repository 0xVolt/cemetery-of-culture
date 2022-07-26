//2.Write a program for generating 2 threads,
// one for printing even numbers and the other for printing odd numbers.

class Even extends Thread {
    String l;

    Even(String l) {
        this.l = l;
    }

    public void run() {
        synchronized (l) {
            System.out.println("the even nos are ");
            for (int i = 0; i <= 20; i += 2) {
                System.out.println("\n" + i);
            }
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println("interrupted");
            }
        }
    }
}

class Odd extends Thread {
    String l;

    Odd(String l) {
        this.l = l;
    }

    public void run() {
        synchronized (l) {
            System.out.println("odd nos are ");
            for (int i = 1; i <= 20; i += 2) {
                System.out.println("\n" + i);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("interrupted");
            }
        }
    }
}

// For a synchronized block, the lock is acquired on the object specified in the
// parentheses after the synchronized keyword
//
public class q2 {
    public static void main(String[] args) {
        String l = "";
        Even e1 = new Even(l);
        e1.start();

        Odd o1 = new Odd(l);
        o1.start();
    }
}
