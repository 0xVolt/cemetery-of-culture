class Thread1 extends Thread
{
    public void run()
    {
        for(int i = 0;i<10;i++ )
        {
            System.out.println("Thread 1:"+i);
        }
    }
}
class Thread2 extends Thread
{
    public void run()
    {
        for(int i = 11; i<=20 ;i++)
        {
            try {
                Thread.sleep(2500);
                
            } catch (InterruptedException e) {
                System.out.println(e);
            }
            System.out.println("Thread 2:"+i);
        }
    }
}
class Thread3 extends Thread
{
    public void run()
    {
        for(int i = 21; i<=30;i++)
        {
            try {
                Thread.sleep(2000);
            } catch (Exception e) {
                System.out.println(e);
            }
        System.out.println("Thread 3:"+i);
        }
    }
}
class Q4
{
    public static void main(String[] args) 
    {
        Thread1 t1 = new Thread1();
        t1.start();
        try 
        {
            t1.join();
        } 
        catch (Exception e) 
        {
            
            System.out.println(e);
        }
        Thread2 t2 = new Thread2();
        t2.start();
        Thread3 t3 = new Thread3();
        t3.start();
        System.out.println("Divyam Kumar\n500083141");
    }
}