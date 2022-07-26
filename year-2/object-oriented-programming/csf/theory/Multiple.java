interface f1{
    int  dist=25;
    public void time();
}

interface f2{
    int time=10;
    public void dist();
}

class Car  implements f1,f2
{
    int dist;
    int speed =50;
    public void dist()
    {
        dist=speed*time; 
        System.out.println("Distance:"+dist);
    }
    public void time()
    {
        int time=dist/speed;
        System.out.println("Time:"+time);
    }
}

class Multiple extends Car
{
    public static void main(String args[]){
        Car c =new Car();
        c.dist();
        c.time();
        System.out.println("Divyam Kumar\n500083141");
    }
}