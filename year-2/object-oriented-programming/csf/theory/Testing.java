import java.util.*;
import Calculation.Calculator;
class Test
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a,b;
        System.out.println("Enter 2 numbers:");
        a = sc.nextDouble();
        b = sc.nextDouble();
        Calculator c =new Calculator();
        c.add(a,b);
        c.diff(a,b);
        c.mul(a,b);
        c.div(a,b);
	System.out.println("Divyam Kumar \n 500083141");
    }
}