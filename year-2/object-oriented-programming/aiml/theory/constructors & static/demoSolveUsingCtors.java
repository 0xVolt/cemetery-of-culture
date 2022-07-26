class Student {
    private String name;
    private String city;
    private double cgpa;

    // Default ctor
    public Student() {
        name = "Amit";
        city = "Bangalore";
        cgpa = 7.76;
    }

    // Parameterized ctor
    public Student(String name, String city, double cgpa) {
        this.name = name;
        this.city = city;
        this.cgpa = cgpa;
    }

    // Copy ctor where the parameter is an object of the same class
    public Student(Student A) {
        this.name = A.name;
        this.city = A.city;
        this.cgpa = A.cgpa;
    }

    // public void getData(String name, String city, double cgpa) {
    //     this.name = name;
    //     this.city = city;
    //     this.cgpa = cgpa;
    // }

    public void putData() {
        System.out.println("Printing data:");
        System.out.println("Name: " + name);
        System.out.println("City: " + city);
        System.out.println("CGPA: " + cgpa);
        System.out.println();
    }
}

public class demoSolveUsingCtors {
    public static void main(String[] args) {
        // Init using default ctor
        Student stu1 = new Student();
        stu1.putData();

        // Init using parameterized ctor
        Student stu2 = new Student("Sumit", "Chennai", 8.81);
        stu2.putData();

        
        // Init using copy ctor
        Student stu2Copy = new Student(stu2);
        stu2Copy.putData();
        
        /* Why do we use copy ctors instead of using a reference variable?
        
        Without using copy ctor:

        Student stu2Copy = new Student(stu2);
        stu2Copy = stu2; ----> (*)
        stu2Copy.putData();

        In this case, statement * lets stu2Copy and stu2 point to the same location in memory. Any changes in either object will reflect in the other.
        
        */
    }
}
