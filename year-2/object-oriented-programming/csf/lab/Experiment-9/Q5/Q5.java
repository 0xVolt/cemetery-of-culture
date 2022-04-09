import java.util.Scanner;
class Thread1 extends Thread
{
    public void run()
    {
        for(int i = 0;i<10;i++)
        {
            System.out.println("Thread 0:"+i);
        } 
            
        
    }

}
class Thread2 extends Thread
{
    public void run()
    {
        for(int i = 11;i<=20;i++)
        {
            System.out.println("Thread 1:"+i);
        } 
            
        
    }

}
class Thread3 extends Thread
{
    public void run()
    {
        for(int i = 21;i<=30;i++)
        {
            System.out.println("Thread 2:"+i);
        } 
            
        
    }

}
class Q5
{
    public static void main(String[] args) 
    {   Scanner sc = new Scanner(System.in);
        int a,b,c;
        Thread1 t1 = new Thread1();
        Thread2 t2 = new Thread2();
        Thread3 t3 = new Thread3();
        System.out.println("Thread Created is:"+t1.getName());
        System.out.println("Enter a priority between 0-10");
        a = sc.nextInt();
        t1.setPriority(a);
        System.out.println("Priorty:"+t1.getPriority());       
        System.out.println("Thread Created is:"+t2.getName());
        System.out.println("Enter a priority between 0-10");
        b = sc.nextInt();
        t2.setPriority(b);
        System.out.println("Priorty:"+t2.getPriority());
        System.out.println("Thread Created is:"+t3.getName());
        System.out.println("Enter a priority between 0-10");
        c = sc.nextInt();
        t3.setPriority(c);
        System.out.println("Priorty:"+t3.getPriority());
        t1.start();
        t2.start();
        t3.start();
        System.out.println("Divyam Kumar\n500083141");
    }
}