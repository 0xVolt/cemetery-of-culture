import java.util.*;
class Q4 
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        float n = 0;
        System.out.println("Enter a number:");
        n = in.nextFloat();
        Float obj = new Float(n);
        System.out.println("float to Float:"+obj);
        String a = Float.toString(obj);
        System.out.println("Float to String:"+a);
        float b = Float.parseFloat(a);
        System.out.println("String to float:"+b);
        String c = Float.toString(b);
        System.out.println("float to String:"+c);
        Float obj2 = Float.valueOf(c);
        System.out.println("String to Float:"+obj2);
        float d = obj2.floatValue();
        System.out.println("Float to float:"+d);
        System.out.println("Divyam Kumar\n500083141");
        

    }    
}
