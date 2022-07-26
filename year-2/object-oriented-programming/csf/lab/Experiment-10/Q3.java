
import java.util.*;
class Q3 
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int n = 0;
        System.out.println("Enter a number:");
        n = in.nextInt();
        Integer obj = new Integer(n);
        System.out.println("int to Integer:"+obj);
        String a = Integer.toString(obj);
        System.out.println("Integer to String:"+a);
        int b = Integer.parseInt(a);
        System.out.println("String to int:"+b);
        String c = Integer.toString(b);
        System.out.println("int to String:"+c);
        Integer obj2 = Integer.valueOf(c);
        System.out.println("String to Integer:"+obj2);
        int d = obj2.intValue();
        System.out.println("Integer to int:"+d);
        System.out.println("Divyam Kumar\n500083141");
        

    }    
}
