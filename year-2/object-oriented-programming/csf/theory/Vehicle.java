import java.util.*;
class Vehicle
{
void car(String n,int c,double m)
    {
        System.out.println("NAME: "+n);
        System.out.println("CHASIS NO: "+c);
        System.out.println("MILEAGE: "+n);
    }
void car(String n,double m)
    {
        System.out.println("NAME: "+n);
        System.out.println("MILEAGE: "+m);
    }
    public static void main(String[] args) 
    {
        Vehicle v = new Vehicle();
        v.car("Hyundai",123,20);
        v.car("Tata",24);    
        System.out.println("Divyam Kumar\n500083141");
    }
}