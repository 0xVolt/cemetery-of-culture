class EvenT extends Thread
{
    public void run()
    {
        for(int i = 0;i<10;i++)
        {
            if(i%2==0)
            System.out.println("Even Thread"+i);
        }
    }
}
class OddT extends Thread
{
    public void run()
    {
        for(int i = 0;i<10;i++)
        {
            if(i%2!=0)
            System.out.println("Even Thread"+i);
        }
    }
}
class Q3
{
    public static void main(String[] args) 
    {
        EvenT et = new EvenT();
        et.run();
        OddT ot = new OddT();
        ot.run();    
        System.out.println("Divyam Kumar\n500083141");
    }
}