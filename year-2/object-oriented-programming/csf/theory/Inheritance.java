class Inheritance
{
    private int a =100;
    private static void mul(int a,int b)
    {
        System.out.println("Product:"+(a*b));
    }
}
class Base extends Inheritance
{
    public static void main(String[] args) {
        Inheritance.mul(5,4);
        System.out.println(a);
    }
}