
class Zero
{
    public static void main(String[] args) {
        int n=0,s;
        int a=40;
        try
        {
            s=a/n;

        }
        catch(ArithmeticException e)
        {
            System.out.println("Division by zero");
            

        }
        catch(Exception e)
        {
            System.out.println(e);

        }
       
    }   
}