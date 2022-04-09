import java.util.*;
class Q1
{
    public void strconcat(String a,String b)
   {    
        String c = a.concat(b);
        System.out.println("CONCAT()");
        System.out.println(c);
    }


    public void strequals(String a , String b)
    {
        System.out.println("EQUALS()");
        if(a.equals(b))
        
            System.out.println("TRUE");
        else
            System.out.println("FALSE");
        
    }
    public void equalsigc(String a , String b)
    {
        System.out.println("EQUALSIGNORECASE()");
        if(a.equalsIgnoreCase(b))
        
            System.out.println("TRUE");
        else
            System.out.println("FALSE");
    }   
    public void struc(String a, String b) 
    {
        String c = a.toUpperCase();
        System.out.println("UPPERCASE()");
        System.out.println(c);    
    }
    public void pos(String a)
    {
        int n = a.length();
        char f,l;
        f =  a.charAt(0);
        l = a.charAt(n-1);
        System.out.println("CHARAT()");
        System.out.println("Character at 0:" + f +"\n"+"Character at n-1:" + l);
    }
    public void comp(String a , String b) 
    {
        int  c = a.compareTo(b);
        System.out.println("COMPARETO()");
        System.out.println(c);

    }
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        String a,b;
        System.out.println("Enter two strings:");
        a = in.nextLine();
        b= in.nextLine();
        Q1 q = new Q1();
        q.strconcat(a, b);
        q.strequals(a, b);
        q.equalsigc(a, b);
        q.struc(a, b);
        q.pos(a);
        q.comp(a, b);
        System.out.println("Divyam Kumar\n500083141");
            
    }
}