interface MD
{
    public void division(int n,int m);
    public void moudules(int a , int b);

}
class Calc implements MD
{   
    public void division(int n, int m)
    {
        System.out.println("Division:" +(n/m));
    }
    public void moudules(int a,int b)
    {
        System.out.println("Mod:"+(a%b));
    }
    public static void main(String[] args) 
    {
        Calc c = new Calc();    
        c.division(20,4);
        c.moudules(10,3);
        System.out.print("Divyam\n500083141");
    }
}