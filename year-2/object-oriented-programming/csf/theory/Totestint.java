interface Test
{
    void square();
}
class Arthematic implements Test
{
    public void square()
    {
        System.out.println("A square has 4 sides");
    }
}
class Totestint extends Arthematic
{
    public static void main(String[] args) 
    {
        Arthematic a = new Arthematic();
        a.square();    
        System.out.print("Divyam\n500083141");
    }
}