interface A 
{
    void meth1();
    void meth2();
}
class Myclass implements A
{
    public void meth1()
    {
        int a =5,b=10;
        System.out.println("Sum:"+(a+b));
    }
    public void meth2()
    {
        int a=5,b=10;
        System.out.println("Product:"+(a*b));
    }
public static void main(String[] args) 
 {
    Myclass m = new Myclass();
    m.meth1();
    m.meth2();
    System.out.print("Divyam\n500083141");
}
}