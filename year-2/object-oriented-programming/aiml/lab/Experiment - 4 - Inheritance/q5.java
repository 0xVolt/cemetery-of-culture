// Code by Desh Iyer

// PROBLEM STATEMENT
// Design a class employee of an organization. An employee has a name, empid, and salary. Write the default constructor, a constructor with parameters (name, empid, and salary) and methods to return name and salary. Also write a method increaseSalary that raises the employee’s salary by a certain user specified percentage. Derive a subclass Manager from employee. Add an instance variable named department to the manager class. Supply a test program that uses theses classes and methods.   

class Employee {
    private String name;
    private String empid;
    private double salary;

    public Employee() {}

    public Employee(String name, String empid, double salary) {
        this.name = name;
        this.empid = empid;
        this.salary = salary;
    }

    public String getName() {
        return this.name;
    }

    public double getSalary() {
        return this.salary;
    }

    public void increaseSalary(double increaseBy) {
        increaseBy /= 100;
        this.salary += this.salary * increaseBy;
    }

    // Overriden function
    public void displayDetails() {
        System.out.printf("\n\nDisplaying Details:\nName: %s\nEmp id: %s\nSalary: %.2f\n", name, empid, salary);
    }
}

class Manager extends Employee {
    private String department;

    public Manager() {};

    public Manager(String name, String empid, double salary, String department) {
        super(name, empid, salary);
        this.department = department;
    }

    // Overidding function
    // @Override
    public void displayDetails() {
        super.displayDetails();
        System.out.printf("Department: %s", department);
    }
}

public class q5 {
    public static void main(String[] args) {
        Employee E1 = new Employee("E1", "1", 100);
        E1.displayDetails();
    
        Manager M1 = new Manager("M1", "2", 250, "Stationery");
        M1.displayDetails();

        // Creating an object of the child class using the parent reference variable
        // Example of Upcasting
        Employee M2 = new Manager("EM1", "3", 300, "Frozen Foods");
        M2.displayDetails();
    }    
}
