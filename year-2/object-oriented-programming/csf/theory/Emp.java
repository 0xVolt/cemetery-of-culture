class Employee
{
    int empno;
    Double salary;
    String name;
    Employee()
    {
        System.out.println("Default constructor created");

    }
    Employee(int no,String n,Double slr)
    {
        empno=no;
        name=n;
        salary=slr;

    }
    void display()
    {
        System.out.println("Employee name is :"+name);
        System.out.println("Salary= "+salary);
    }
    Double increaseSalary(Double perc)
    {
        salary=salary+((perc/100)*salary);
        return salary;

    }
}
class Manager extends Employee
{
    
}

class Emp
{
    public static void main(String args[]) 
    {
        
    
    Employee emp=new Employee(101,"Mohit",25000.0);
    Manager mn=new Manager();
    mn.name="Jeff Bezoz";
    mn.salary=40000.00;
    mn.display();
    emp.increaseSalary(12.5);
    emp.display();
    
    }
}