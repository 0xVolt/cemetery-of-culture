class Runthread implements Runnable
{
    public void run()
    {
        for(int i = 0;i < 10;i++)
        {
            System.out.println("Thread 1:"+i);
        }
    }
}
class Runthread2 implements Runnable
{
    public void run()
    {
        for(int i = 11;i <= 20;i++)
        {
            System.out.println("Thread 2:"+i);
        }
    }
}
class Q2
{
public static void main(String[] args) {
    
    Runthread r1 = new Runthread();
    new Thread(r1).start();
    Runthread2 r2 = new Runthread2();
    new Thread(r2).start();   
    System.out.println("Divyam Kumar\n 500083141");

}
}