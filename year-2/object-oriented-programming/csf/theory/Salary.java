
class Worker
{
String name;
int empno;
Worker(String n,int no)
{
    name =n;
    empno = no;
}
void show()
{
    System.out.println("Employee Name: "+name);
    System.out.println("Employee ID: "+empno);
}
}
class DailyWorker extends Worker
{
    DailyWorker(String n, int no)
    {
        super(n,no);
    }
    void show(){
        super.show();
        System.out.println("No. of Days worked: 50");
        double sal=5.0*50;
        System.out.println("Salary with 5.0 rate: "+sal);
    }
    
}
class SalariedWorker extends Worker
{
    SalariedWorker(String n, int no)
    {
    super(n,no);
    }
    double rate = 6.0;
    void Compay(int h)
    {
        super.show();
        System.out.println("Salary for 40 hours of work with 6.0 rate:"+rate*h);
        
    }
}
class Salary
{
    public static void main(String[] args) 
    {
        DailyWorker dw = new DailyWorker("Rohan",102);
        SalariedWorker sw = new SalariedWorker("Shayam",208);
        dw.show();
        sw.Compay(40);

    }
}