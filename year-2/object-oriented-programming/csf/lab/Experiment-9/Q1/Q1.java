class Thread1 extends Thread
{
    public void run()
    {
        int i = 0;
        while(i<10)
        {
            System.out.println("Thread no."+i);
            i++;
        }
    }
}
class Thread2 extends Thread
{
    public void run()
    {
        int i = 10;
        while(i<20)
        {
            System.out.println("Thread no."+i);
            i++;
        }
    }
}
class Q1
{
    public static void main(String[] args) {
        Thread1 t1 = new Thread1();
        t1.start();
        Thread2 t2 = new Thread2();
        t2.start();
	System.out.println("Divyam Kumar\n500083141");
    }
}