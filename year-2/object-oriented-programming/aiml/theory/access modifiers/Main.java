class Student {
    // defining public fields
    public String name;
    public String city;

    // make cgpa private
    private double cgpa;

    // variable to count number of student objects created
    public static int studentCount = 0; 

    void changeCGPA(double x) {
        // whenever a student changes their cgpa, the count is incremented
        studentCount++;
        cgpa = x;
    }
    void printCGPA() {
        System.out.println("CGPA: " + cgpa);
        // print the count of students in the current state
        System.out.println("Total Students: " + studentCount);
    }
}

// we change the name of the file to this classes' name so we can run using code runner
class Main {
    public static void main(String[] args) {
        Student student1 = new Student();
        student1.name = "Amit";
        student1.city = "Bangalore";
        // student1.cgpa = 9.8;

        System.out.println("Name: " + student1.name);
        System.out.println("City: " + student1.city);
        // System.out.println("CGPA: " + student1.cgpa); not possible since cgpa is a private field
        
        student1.changeCGPA(7.65);
        student1.printCGPA();
        
        Student student2 = new Student();
        student2.name = "Sumit";
        student2.city = "Chennai";
        System.out.println("Name: " + student2.name);
        System.out.println("City: " + student2.city);
        student2.changeCGPA(5.76);
        student2.printCGPA();
    }
}
