import java.util.*;
class Q2 
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);
        int a = Integer.hashCode(169);
        System.out.println("HashCode:"+a);
        String s = "Hello        ";
        int b,c;
        b = s.length();
        c = s.trim().length();
        System.out.println("TRIM()"+c + "\nWithoutTRIM"+b);
        String st = s.substring(1, 3);
        String m = s.replace("l", "a");
        System.out.println(m);;
        System.out.println("Divyam Kumar\n500083141");

    }    
}
